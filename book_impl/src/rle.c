#include "rle.h"
#include <stdlib.h>

/*
    *Encoding algorithm
    *Run-length encoding compresses data by reducing the physical size of a
repeating string of characters. This process involves converting the input data
into a compressed format by identifying and counting consecutive occurrences of
each character. The steps are as follows:

    *Traverse the input data.
    *Count the number of consecutive repeating characters (run length).
    *Store the character and its run length.
*/

int encode(int *lines, int size, int line, int *newlines) {
    // we will do it from the very starting , so lets say the lines look like
    // ....
    //
    /*i am thinking of (value,count) pairs
     */
    // [3,3,3,3,3,4,4,4,4,5,5,5,5,5,5,5,5] -> [3,5, 4,4, 5,8];
    // every odd pos is value and its next pos is the count
    //
    //

    // alrighty so  we need to get the size of the pointer or how ling the lines
    // are ....... how to do that
    if (size == 0)
        return 0;
    int position = 0;
    int current_value = lines[0];
    int current_count = 1;
    for (int i = 1; i < size; i++) {
        if (lines[i] == current_value) {
            // we got the repeating case
            current_count++;
        } else {
            newlines[position++] = current_value;
            newlines[position++] = current_count;

            current_value = lines[i];
            current_count = 1;
        }
    }

    newlines[position++] = line;
    newlines[position++] = current_count;

    return position;
}

int getLine(int *lines, int size, int offset) {
    // so now we have this
    // [3,3,3,3,3,4,4,4,4,5,5,5,5,5,5,5,5] -> [3,5, 4,4, 5,8];
    //
    // we have the offset ,
    /*
     * we will take the window of two numbers , and maintain a line number
     */

    int count = 0;
    for (int i = 0; i < size; i += 2) {
        count += lines[i + 1];
        if (offset < count) {
            return lines[i];
        }
    }
    return -1;
}
