#include <assert.h>
#include <math.h>
#include <sys\stat.h>

#include "functions_for_input.h"
#include "functions_for_output.h"

int main (void) {

    FILE *onegin = fopen ("onegin.txt", "rb");

    assert (onegin);

    struct stat64 onegin_stat;
    stat64 ("onegin.txt", &onegin_stat);

    char *buf = BufMaker(onegin_stat.st_size);

    assert (buf);

    FileToBuf (onegin, buf, onegin_stat.st_size);

    fclose ("onegin.txt");

    size_t number_of_strings = StringCounter (buf);

    PtrToStr pointers_to_strings[number_of_strings];
    MakePointersToBuf (&pointers_to_strings, buf);

    rSymbolChecker (&pointers_to_strings);

    FILE *evgenin = fopen ("evgenin.txt", "w");

    PrintOriginal (&pointers_to_strings, evgenin, number_of_strings);

    free (buf);
    return 0;
}
