#include "chunk.h"
#include "common.h"
#include "debug.h"
#include <stdio.h>

// this is the starting point of our VM
int main(int argc, const char *argv[]) {
    Chunk chunk;
    initChunk(&chunk);
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    writeChunk(&chunk, OP_RETURN, 123);
    printf("chunk capacity: %d\nchunk count : %d\n", chunk.capacity,
           chunk.count);
    // freeChunk(&chunk);
    // printf("chunk capacity: %d\n , chunk count : %d", chunk.capacity,
    // chunk.count);
    disassembleChunk(&chunk, "test chunk");
    return 0;
}
