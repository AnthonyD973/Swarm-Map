cmake_minimum_required(VERSION 3.0.0)
project(swarmmap)

# PROJECT CONFIG
include(cmake/SwarmMapConfig.cmake)

# COMPILER FLAGS
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -std=c99   -Wall -O2 -march=native")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O2 -march=native")

# SUBDIRECTORIES
add_subdirectory(swarmmap)