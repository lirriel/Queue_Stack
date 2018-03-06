cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp NiceQueue.h NiceStack.h NiceStack.hpp NiceQueue.hpp)
add_executable(untitled ${SOURCE_FILES})