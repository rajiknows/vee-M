

#include "scanner.h"

typedef struct {
    const char *start;
    const char *current;
    int line;
} Scanner;

Scanner scanner;

void initscanner(const char *source) {
    scanner.start = source;
    scanner.current = source;
    scanner.line = 1;
}
