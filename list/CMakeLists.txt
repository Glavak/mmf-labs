cmake_minimum_required(VERSION 3.8)
project(list)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-Wall -Werror")

set(SOURCE_FILES main.cpp)
add_executable(list ${SOURCE_FILES})