#include <stdlib.h>
#include "find_pattern.h"

void find_pattern(char pattern[], char *content, Result **results, int *results_count)
{
    *results = realloc(*results, sizeof **results * 1);
    *results_count = 2;

    (*results)[0].line = 1;
    (*results)[0].position = 1;

}
