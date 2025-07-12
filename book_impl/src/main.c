#include "vm.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static void repl() {
    char line[1024];

    for (;;) {
        printf("> ");

        if (!fgets(line, sizeof(line), stdin)) {
            printf("\n");
            break;
        }

        interpret(line);
    }
}
static char *readfile(const char *path) {
    FILE *file = fopen(path, "rb");
    if (file == NULL) {
        fprintf(stderr, "failed to read the file");
        exit(78);
    }

    fseek(file, 0L, SEEK_END);
    size_t filesize = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc(filesize + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Not enough memory to read \"%s\".\n", path);
        exit(74);
    }

    size_t bytes_read = fread(buffer, sizeof(char), filesize, file);
    if (bytes_read < filesize) {
        fprintf(stderr, "Could not read file \"%s\".\n", path);
        exit(74);
    }

    buffer[bytes_read] = '\0';

    fclose(file);
    return buffer;
}

static void runfile(const char *path) {
    char *source = readfile(path);
    InterpretResult result = interpret(source);
    free(source);

    if (result == INTERPRET_COMPILE_ERROR)
        exit(65);
    if (result == INTERPRET_RUNTIME_ERROR)
        exit(70);
}

// this is the starting point of our VM
int main(int argc, const char *argv[]) {
    initVm();
    // Chunk chunk;
    // initChunk(&chunk);
    // int constant = addConstant(&chunk, 1.2);
    // writeChunk(&chunk, OP_CONSTANT, 123);
    // writeChunk(&chunk, constant, 123);
    // writeChunk(&chunk, OP_NEGATE, 123);
    //
    // constant = addConstant(&chunk, 3.4);
    // writeChunk(&chunk, OP_CONSTANT, 123);
    // writeChunk(&chunk, constant, 123);
    //
    // writeChunk(&chunk, OP_ADD, 123);
    //
    // constant = addConstant(&chunk, 5.6);
    // writeChunk(&chunk, OP_CONSTANT, 123);
    // writeChunk(&chunk, constant, 123);
    //
    // writeChunk(&chunk, OP_DIVIDE, 123);
    // writeChunk(&chunk, OP_NEGATE, 123);
    //
    // writeChunk(&chunk, OP_RETURN, 123);
    // printf("chunk capacity: %d\nchunk count : %d\n", chunk.capacity,
    //        chunk.count);
    // // printf("chunk capacity: %d\n , chunk count : %d", chunk.capacity,
    // // chunk.count);
    // disassembleChunk(&chunk, "test chunk");
    // interpret(&chunk);
    // freeVm();
    // freeChunk(&chunk);
    if (argc == 1) {
        repl();
    } else if (argc == 2) {
        runfile(argv[1]);
    } else {
        fprintf(stderr, "Usage: clox [path]\n");
        exit(64);
    }
    freeVm();
    return 0;
}
