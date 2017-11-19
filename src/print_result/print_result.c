#include <stdio.h>
#include "print_result.h"

void print_result(Result *results, int *result_count)
{
    int i;

    for (i=0; i < (*result_count); i++)
    {
        printf("Line: %d\tPosition: %d\n", results[i].line, results[i].position);
    }
}
