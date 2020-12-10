cmake_minimum_required(VERSION 3.16)
project(LAB1)

set(CMAKE_CXX_STANDARD 11)
set(
        SOURCE_FILES
        main.cpp
        cmake-build-debug/Profiler.h
)

add_executable(LAB1 main.cpp)