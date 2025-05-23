#include "chunk.h"
#include "debug.h"
#include "common.h"
#include <stdio.h>

// this is the starting point of our VM
int main(int argc, const char* argv[]){
    Chunk chunk;
    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN);
    printf("chunk capacity: %d\nchunk count : %d\n", chunk.capacity, chunk.count);
    // freeChunk(&chunk);
    // printf("chunk capacity: %d\n , chunk count : %d", chunk.capacity, chunk.count);
    disassembleChunk(&chunk, "test chunk");
    return 0;
}
