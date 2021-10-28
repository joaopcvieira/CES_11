cmake_minimum_required(VERSION 3.19)
project(Lab3_Erdos C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lab3_Erdos
        author.c
        author.h
        graphImplementation.c
        graphImplementation.h
        main.c)