#ifndef vasa_vm_h
#define vasa_vm_h

#include "chunk.h"
#include "value.h"
#include <stdint.h>

#define STACK_MAX 256
typedef struct {
    Chunk *chunk;
    uint8_t *ip;
    Value stack[STACK_MAX];
    Value *stackTop;
} VM;

void initVm();
void freeVm();

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR,
} InterpretResult;

InterpretResult interpret(Chunk *chunk);

void push(Value value);
Value pop();

#endif // !vasa_vm_h
