#include <assert.h>
#include <math.h>

#include "functions_for_output.h"

void PrintOriginal (*PtrToStr const ptrs_to_strings, FILE *const output_file, const size_t num_of_str) {

    assert (ptrs_to_strings);
    assert (output_file);

    //TODO pointers sort

    PrintAll (ptrs_to_strings, output_file, num_of_str)
}

void PrintAll (*PtrToStr const ptrs_to_strings, FILE *const output_file, const size_t num_of_str) {

    assert (ptrs_to_strings);
    assert (output_file);

    for (int current_num_of_str = 0; current_num_of_str < num_of_str; current_num_of_str++) {

        if ((ptrs_to_strings[current_num_of_str] -> string_length) != 0) {
            fputs ((ptrs_to_strings[current_num_of_str] -> pointer_to_string), output_file);
            fputc ('\n', output_file);
        }
    }
}
