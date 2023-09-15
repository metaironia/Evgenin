#ifndef FUNCTIONS_FOR_INPUT_H
#define FUNCTIONS_FOR_INPUT_H

#include <stdio.h>
#include <string.h>

struct PtrToStr {
    int string_length;
    char *pointer_to_string;
};

char *BufMaker (const off_t buf_size);

void FileToBuf (FILE *const text, char *const buffer, const off_t buf_size);

size_t StringCounter (char *const buffer, const off_t buf_size);

void MakePointersToBuf (PtrToStr *const ptrs_to_strings, char *const buffer, off_t buf_size,
                        size_t num_of_str);

void rSymbolChecker (PtrToStr *const ptrs_to_strings, const size_t num_of_str);


#endif
