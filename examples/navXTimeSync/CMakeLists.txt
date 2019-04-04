add_executable(navXTimeSync
    TimeStamp.cpp
)

target_link_libraries(navXTimeSync
  PUBLIC
  navx
  ${CMAKE_THREAD_LIBS_INIT}
)
