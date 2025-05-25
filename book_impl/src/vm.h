#ifndef vasa_vm_h
#define vasa_vm_h

#include "chunk.h"

typedef struct {
    Chunk *chunk;
} VM;

void initVm();
void freeVm();

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
} InterpretResult;

InterpretResult interpret(Chunk *chunk);

#endif // !vasa_vm_h
