cmake_minimum_required(VERSION 3.27)
project(maze_project C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)

add_executable(maze_project
        src/playsound.c
        src/rain.c
        src/main.c
)
target_include_directories(maze_project PRIVATE inc)
# Set properties to exclude specific source files
set_source_files_properties(src/playsound.c PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties(src/rain.c PROPERTIES HEADER_FILE_ONLY TRUE)