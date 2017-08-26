cmake_minimum_required (VERSION 2.6)
project (Tutorial)
set (CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}")
add_executable(Tutorial tutorial.cpp)
