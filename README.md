# Swarm map

This project defines a map-like data structure which propagates throughout a robot swarm.

**Addressed problems and limitations**

- Each robot can instantiate (currently) up to one entry and manages that entry.
- Entries can be updated by the robot that instantiated it.
- The swarm of robots must reach consensus despite high packet drop rates.
- The robots have bandwidth limitations.
- Entries can become inactive after a fixed amount of time to deal with defective/far-away robots.

**Possible usages**

- Sharing and updating sub-swarm memberships.
- Sharing and updating sensor readings.
- Reaching a barrier, that is, waiting until a certain number of robots are ready to go to the next state.

Compiling
=========

    $ mkdir build
    $ cd build
    $ cmake ../src
    $ make

Installing
==========

Optional step. You may link against the library and include the headers from source instead.

    $ sudo make install

Installing without root privileges
==================================

Run cmake with the option `-DCMAKE_INSTALL_PREFIX=/path/to/install/to`. For example:

    $ cmake ../src -DCMAKE_INSTALL_PREFIX="$HOME/local/"

Then you may install with:

    $ make install
