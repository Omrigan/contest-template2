cmake_minimum_required(VERSION 3.2)
project(cpp_pal)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DDEBUG")

set(SOURCE_FILES main.cpp)
add_executable(cpp_pal ${SOURCE_FILES})