/**
 * @file sminclude.h
 * @brief Header that should be included everywhere.
 */
#ifndef SMINCLUDE_H
#define SMINCLUDE_H

#include "smconfig.h"

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * The type of a message.
 */
typedef enum {
    SWARMMAP = 0 ///< SwarmMap message. TODO Allow user to change the value.
} msg_type_t;

#if   LAMPORT_SIZE == 1
typedef uint8_t smlamport_t;
#elif LAMPORT_SIZE == 2
typedef uint16_t smlamport_t;
#elif LAMPORT_SIZE == 4
typedef uint32_t smlamport_t;
#endif // LAMPORT_SIZE == 1

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !SMINCLUDE_H