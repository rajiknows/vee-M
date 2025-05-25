#ifndef vasa_rle_h
#define vasa_rle_h
//
// typedef struct {
//     int count;
//     int *lines;
// } Rle;
//


int encode(int *lines, int size, int line, int *newlines);


int getLine(int *lines ,int size, int offset);

#endif
