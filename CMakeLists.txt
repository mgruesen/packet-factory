project(packet-factory CXX)

enable_testing()

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++14")

include_directories(.)
include_directories(core)
include_directories(apps)

add_subdirectory(apps)
add_subdirectory(core)
add_subdirectory(test)
