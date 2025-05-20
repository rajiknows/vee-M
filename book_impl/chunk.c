

#include "chunk.h"
#include "common.h"
#include <stdint.h>
#include "memory.h"



void initChunk(Chunk *chunk){
    chunk-> capacity = 0;
    chunk-> count =0;
    chunk-> code = NULL;
}


// free the array inside and init a new empty chunk
void freeChunk(Chunk *chunk){
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    initChunk(chunk);
}

// init a  new chunk double the capacity of old chunk and copy everything over to the new one
void writeChunk(Chunk *chunk, uint8_t byte){
    if ( chunk->capacity < chunk->capacity + 1){
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->count++;
}
