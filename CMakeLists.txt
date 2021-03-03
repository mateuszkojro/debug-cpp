cmake_minimum_required(VERSION 3.15)
project(deb1ug_cpp)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 17)

add_library(
  debug_cpp STATIC
  Logger.cc
)

#add_library(
  #debug_cpp SHARED
  #Logger.cc
#)
link_libraries(
  debug_cpp
)

add_executable(example example.cc)

target_link_libraries(
  debug_cpp
)
