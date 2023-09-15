#ifndef FUNCTIONS_FOR_INPUT_H
#define FUNCTIONS_FOR_INPUT_H

struct PtrToStr[] {
    int string_length;
    char *pointer_to_string;
};

char BufMaker (const off64_t buf_size);

void FileToBuf (FILE *const text, char *const buffer, const off64_t buf_size);

size_t StringCounter (char *const buffer, const off64_t buf_size);

void MakePointersToBuf (*PtrToStr const ptrs_to_strings, char *const buffer, off64_t buf_size,
                        size_t num_of_str);

void rSymbolChecker (*PtrToStr const ptrs_to_strings, const size_t num_of_str);


#endif
