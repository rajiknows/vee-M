
cmake_minimum_required(VERSION 3.10)
project(clox C)

set(CMAKE_C_STANDARD 99)

add_executable(vasa
    src/main.c
    src/chunk.c
    src/debug.c
    src/memory.c
    src/value.c
    src/rle.c
    src/vm.c
    src/compiler.c
)
