#include <stdio.h>
#include "print_result.h"

void print_result(const Result *results, int results_count)
{
    int i;

    if(results_count < 1)
    {
        puts("Not found");
        return;
    }

    for (i=0; i < results_count; i++)
    {
        printf("Line: %d\tPosition: %d\n", results[i].line, results[i].position);
    }
}
