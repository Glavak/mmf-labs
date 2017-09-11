cmake_minimum_required(VERSION 3.8)
project(strings)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "-Wall -Werror")

set(SOURCE_FILES main.cpp mystring.cpp)
add_executable(strings ${SOURCE_FILES})