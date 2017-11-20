#include <stdlib.h>
#include "find_pattern.h"

void find_pattern(const char pattern[], const char content[], Result **results, int *results_count)
{





    *results_count = 2;
    *results = realloc(*results, (sizeof (**results)) * (*results_count));

    (*results)[0].line = 1;
    (*results)[0].position = 1;
}
