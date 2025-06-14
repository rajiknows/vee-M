#include "chunk.h"
#include "common.h"
#include "memory.h"
#include "rle.h"
#include "value.h"
#include <stdint.h>
#include <stdio.h>

void initChunk(Chunk *chunk) {
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->code = NULL;
    chunk->lines = NULL;
    chunk->length = 0;
    initValueArray(&chunk->constants);
}

// free the array inside and init a new empty chunk
void freeChunk(Chunk *chunk) {
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    FREE_ARRAY(int, chunk->lines, chunk->capacity);
    freeValueArray(&chunk->constants);
    initChunk(chunk);
}

// init a  new chunk double the capacity of old chunk and copy everything over
// to the new one
void writeChunk(Chunk *chunk, uint8_t byte, int line) {
    if (chunk->capacity < chunk->capacity + 1) {
        int oldCapacity = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldCapacity);
        chunk->code =
            GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
        chunk->lines =
            GROW_ARRAY(int, chunk->lines, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte;
    // Update RLE-compressed lines array
    if (chunk->length >= 2 && chunk->lines[chunk->length - 2] == line) {
        chunk->lines[chunk->length - 1] += 1;
    } else {
        chunk->lines[chunk->length++] = line;
        chunk->lines[chunk->length++] = 1;
    }
    chunk->count++;
}

int addConstant(Chunk *chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}
