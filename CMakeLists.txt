cmake_minimum_required(VERSION 2.8.12)
project(py-navx)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -fstrict-aliasing -std=c++11")

find_package(Threads REQUIRED)

include_directories(src)

add_subdirectory(src)
add_subdirectory(examples)
