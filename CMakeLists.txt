cmake_minimum_required(VERSION 3.29)
project(interpreteur C)

set(CMAKE_C_STANDARD 99)

add_executable(interpreteur main.c
        file.c)
