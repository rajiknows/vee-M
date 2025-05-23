
cmake_minimum_required(VERSION 3.10)
project(clox C)

set(CMAKE_C_STANDARD 99)

add_executable(vasa
    main.c
    chunk.c
    debug.c
    memory.c
)
