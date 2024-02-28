cmake_minimum_required(VERSION 3.27)
project(maze_project C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)

add_executable(maze_project
        inc/main.h
        src/playsound.c)
