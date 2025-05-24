#ifndef vasa_rle_h
#define vasa_rle_h
//
// typedef struct {
//     int count;
//     int *lines;
// } Rle;
//
/*
    *Encoding algorithm
    *Run-length encoding compresses data by reducing the physical size of a
repeating *string of characters. This process involves converting the input data
into a *compressed format by identifying and counting consecutive occurrences of
each *character. The steps are as follows:

    *Traverse the input data.
    *Count the number of consecutive repeating characters (run length).
    *Store the character and its run length.
*/

int encode(int *lines, int size, int line, int *newlines);

/*
 Decoding algorithm
 The decoding process involves reconstructing the original data from the
 encoded format by repeating characters according to their counts. The steps
 are as follows:

 Traverse the encoded data.
 For each count-character pair, repeat the character count times.

 Append these characters to the result string.
*/
int getLine();

#endif // !vasa_rle_h
