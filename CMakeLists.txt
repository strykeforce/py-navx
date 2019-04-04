cmake_minimum_required(VERSION 2.8.12)
project(py_navx)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -fstrict-aliasing -std=c++11")

find_package(Threads REQUIRED)

add_subdirectory(pybind11)
include_directories(navx)

add_subdirectory(navx)
add_subdirectory(examples)

pybind11_add_module(py_navx src/main.cpp)

target_link_libraries(py_navx
  PUBLIC
  navx
  ${CMAKE_THREAD_LIBS_INIT}
)
