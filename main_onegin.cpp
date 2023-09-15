#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <sys\stat.h>
#include <stdlib.h>

#include "functions_for_input.h"
#include "functions_for_output.h"

int main (void) {

    FILE *onegin = fopen ("onegin.txt", "rb");

    assert (onegin);

    struct stat onegin_stat;
    stat ("onegin.txt", &onegin_stat);

    char *buf = BufMaker (onegin_stat.st_size);

    assert (buf);

    FileToBuf (onegin, buf, onegin_stat.st_size);

    fclose (onegin);

    size_t number_of_strings = StringCounter (buf, onegin_stat.st_size);

    PtrToStr *pointers_to_strings = (PtrToStr *) calloc (number_of_strings, sizeof (PtrToStr)); //TODO PtrMaker
    MakePointersToBuf (pointers_to_strings, buf, onegin_stat.st_size, number_of_strings);

    //rSymbolChecker (pointers_to_strings, number_of_strings);

    FILE *evgenin = fopen ("evgenin.txt", "w");

    PrintOriginal (pointers_to_strings, evgenin, number_of_strings);

    fclose (evgenin);

    free (buf);
    return 0;
}
