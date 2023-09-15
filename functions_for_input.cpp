#include <assert.h>
#include <math.h>
#include <sys\stat.h>
#include <stdlib.h>
#include <string.h>

#include "functions_for_input.h"

char *BufMaker (const off_t buf_size) {

    char *pointer_to_buf = (char *) calloc (buf_size + 1, sizeof (char));

    if (pointer_to_buf == NULL) {

        fprintf (stderr, "Not enough memory. Program was finished.");
        return 0;
    }

    return pointer_to_buf;
}

void FileToBuf (FILE *const text, char *const buffer, const off_t buf_size) {

    assert (buffer);
    assert (text);

    fread (buffer, sizeof (char), (size_t) buf_size, text);             //TODO fix type conversion bug

    buffer[buf_size] = '\0';

    char *n_symbol = NULL;

    while ((n_symbol = strrchr (buffer, '\n')) != NULL)
        *n_symbol = '\0';
}

size_t StringCounter (char *const buffer, const off_t buf_size) {

    assert (buffer);

    size_t num_of_str = 0;

    for (size_t counter = 0; counter < size_t (buf_size) + 1; counter++)
        if (buffer[counter] == '\0')
            num_of_str++;

    return num_of_str;
}

void MakePointersToBuf (PtrToStr *const ptrs_to_strings, char *const buffer, off_t buf_size,
                        size_t num_of_str) {

    assert (buffer);
    assert (ptrs_to_strings);

    size_t current_num_of_str = 0;
    char *buf_ptr_index = buffer;

    while (current_num_of_str < num_of_str && (buffer + buf_size) - buf_ptr_index >= 0) {

        (ptrs_to_strings[current_num_of_str].pointer_to_string) = buf_ptr_index;
        (ptrs_to_strings[current_num_of_str].string_length)     = strlen (buf_ptr_index);

        buf_ptr_index = (char *) strchr (buf_ptr_index, '\0') + 1;
        current_num_of_str++;
    }
}

void rSymbolChecker (PtrToStr *const ptrs_to_strings, const size_t num_of_str) {

    assert (ptrs_to_strings);

    char *r_symbol_exist = NULL;

    for (size_t current_num_of_str = 0; current_num_of_str < num_of_str; current_num_of_str++) {

        if ((r_symbol_exist = strchr (ptrs_to_strings[current_num_of_str].pointer_to_string, '\r'))) {

            r_symbol_exist = '\0';
            (ptrs_to_strings[current_num_of_str].string_length) -= 1;
        }
    }
}
