#ifndef vasa_debug_h
#define vasa_debug_h

#include "chunk.h"

void disassembleChunk(Chunk* chunk, const char* name);
int  disassembleInstruction(Chunk* chunk, int offset);

#endif
