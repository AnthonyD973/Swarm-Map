/**
 * @file swarmmap.h
 * @brief Definition of the chunk-based propagation protocol.
 */

#ifndef SWARMMAP_H
#define SWARMMAP_H

#include "sminclude.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// ===============================
// =      SWARMMAP ENTRIES       =
// ===============================

/**
 * Entry of the SwarmMap.
 */
typedef struct PACKED {
    uint8_t key;              ///< Robot ID this entry is for.
    uint8_t* value;           ///< Data we wish to be shared.
    smlamport_t lamport;      ///< Time at which the entry was last updated (Lamport clock).
    uint8_t time_to_inactive; ///< Number of swarmmap ticks until we consider this robot to be inactive.
} swarmmap_entry_t;

/**
 * Determines whether a swarmmap entry is active.
 */
static inline
uint8_t swarmmap_entry_isactive(const swarmmap_entry_t* e) {
    return e->time_to_inactive > 0 || e->robot == kilo_uid;
}

// ===============================
// =     SWARMLIST STRUCTURE     =
// ===============================

/**
 * The data that we know about other robots.
 * @note We assume there is only one instance of this structure.
 */
typedef struct PACKED {
    swarmlist_entry_t data[ROBOT_SWARMLIST_CAP]; ///< The data of the swarm list.
    uint8_t size;  ///< Number of entries.
    uint8_t next_to_send; ///< The index of the next entry to send via a swarm chunk.
} swarmlist_t;

/**
 * Swarmlist single instance.
 */
extern swarmlist_t swarmlist;

/**
 * Constructs the swarmlist.
 */
void swarmlist_construct();

/**
 * Updates/creates an entry in the swarm list.
 */
void swarmlist_update(bbzrobot_id_t robot,
                      uint8_t swarm_mask,
                      lamport8_t lamport);

/**
 * Passes on to the next swarm entry.
 */
ALWAYS_INLINE
void swarmlist_next() {
    ++swarmlist.next_to_send;
    if (swarmlist.next_to_send >= swarmlist.size)
        swarmlist.next_to_send = 0;
}

/**
 * Determines the size of the swarmlist.
 */
ALWAYS_INLINE
uint8_t swarmlist_size() { return swarmlist.size; }

/**
 * Determines the number of active entries in the swarmlist.
 */
uint8_t swarmlist_count();

/**
 * Removes 1 from all timers. If a timer is at 0, remove the entry.
 */
void swarmlist_tick();

/**
 * Broadcasts a swarm data chunk.
 * @details A "swarm data chunk" is a set of swarm entry messages.
 * @see SWARM_CHUNK_DELAY
 * @see SWARM_CHUNK_AMOUNT
 */
void send_next_swarm_chunk();


// ===============================
// =       OTHER FUNCTIONS       =
// ===============================

/**
 * Processes a swarm message.
 */
void process_msg_rx_swarm(message_t* msg_rx);

/**
 * Decides whether a lamport is newer than another one.
 * @note If the two Lamport clocks are equal, the Lamport is not
 * considered as new.
 */
uint8_t lamport_isnewer(lamport8_t lamport, lamport8_t old_lamport);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !SWARMMAP_H