# cmake_minimum_required(VERSION <specify CMake version here>)
project(Snek C)

set(CMAKE_C_STANDARD 99)

add_executable(Snek main.c head.h snek.c constants.h)