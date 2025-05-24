// chunk module header file

#ifndef vasa_chunk_h
#define vasa_chunk_h

#include "common.h"
#include "value.h"
#include <stdint.h>

typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

// this is kinda like a dynamic array implementation , from scratch
// we have a capacity ..... this is the capacity of the array , how much it can
// store we have a count which specifies what is the current amount filled in
// the array
//
//
//
// this works like this :
// 1 . if the count is less than capacity , we increment the count and insert
// the value 2 . if the count is equal to capacity , we init a another array
// with double the capacity and copy all elemennts
//          from the current array to the new array.

typedef struct {
    int capacity;
    int count;
    uint8_t *code;
    ValueArray constants;
    int *lines;
} Chunk;

// initialize a new chunk
void initChunk(Chunk *chunk);

// frees the chunk
void freeChunk(Chunk *chunk);

// writes into the chunk
void writeChunk(Chunk *chunk, uint8_t byte, int line);

// add a constant to a chunk  return the offset`
int addConstant(Chunk *chunk, Value value);

#endif
