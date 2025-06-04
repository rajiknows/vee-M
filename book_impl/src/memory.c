#include "memory.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

// wrapper function that calls realloc() inside
// checks is newsize is 0 we free the pointer and return null
void *reallocate(void *pointer, size_t oldsize, size_t newsize) {
    if (newsize == 0) {
        free(pointer);
        return NULL;
    }

    // Otherwise return the result after allocating the newsize
    void *result = realloc(pointer, newsize);
    // catch the exception if the result is NULL, we dont want null pointer
    // problems down the line
    if (result == NULL)
        exit(1);
    return result;
}
