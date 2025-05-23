

#include "chunk.h"
#include "common.h"
#include "memory.h"
#include "value.h"
#include <stdint.h>

void initChunk(Chunk *chunk) {
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->code = NULL;
    initValueArray(&chunk->constants);
}

// free the array inside and init a new empty chunk
void freeChunk(Chunk *chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

// init a  new chunk double the capacity of old chunk and copy everything over
// to the new one
void writeChunk(Chunk *chunk, uint8_t byte) {
    if (chunk->capacity < chunk->capacity + 1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code =
            GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    chunk->count++;
}


int addConstants(Chunk *chunk, Value value){
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count-1;
}
