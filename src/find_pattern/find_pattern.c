#include <stdlib.h>
#include <string.h>
#include "find_pattern.h"


int *compute_prefix_function(const char pattern[])
{   
    int pattern_length = strlen(pattern);

    int *prefix = malloc(pattern_length * sizeof pattern_length);

    int k = -1;
    prefix[0] = k;
    
    int q;
    for(q=1; q<pattern_length; q++)
    {
        while(k>-1 && pattern[k+1] != pattern[q])
            k = prefix[k];

        if(pattern[k+1] == pattern[q])
            k = k + 1;

        prefix[q] = k;
    }

    return prefix;
}

void find_pattern(const char pattern[], const char content[], Result **results, int *results_count)
{
    int content_length = strlen(content);
    int pattern_length = strlen(pattern);

    *results = realloc(*results, (sizeof *results) * content_length);

    int *prefix = compute_prefix_function(pattern);
    int q = -1;

    int line = 1;

    int i;
    for (i=0; i<content_length; i++)
    {
        if(content[i] == '\n')
            line++;

        while (q>-1 && pattern[q+1] != content[i])
            q = prefix[q];

        if(pattern[q+1] == content[i])
            q++;

        if(q == pattern_length - 1)
        {
            (*results)[*results_count].line = line;
            (*results)[*results_count].position = i - pattern_length + 2;
            (*results_count)++;
        }
    }


    free(prefix);
}
