#include <stdlib.h>
#include <string.h>
#include "find_pattern.h"


int *compute_prefix_function(const char content[])
{   
    int content_length = strlen(content);

    int *prefix = malloc( content_length * sizeof content_length);

    prefix[0] = 0;
    int k = 0;
    
    int q;
    for(q=1; q<content_length; q++)
    {
        while(k>0 && content[k] != content[q])
            k = prefix[k];

        if(content[k] == content[q])
            k = k + 1;

        prefix[q] = k;
    }

    return prefix;
}

void find_pattern(const char pattern[], const char content[], Result **results, int *results_count)
{
    int content_length = strlen(content);
    int pattern_length = strlen(pattern);

    *results = realloc(*results, (sizeof (int)) * content_length);

    int *prefix = compute_prefix_function(content);
    int q = 0;

    int line = 1;

    int i;
    for (i=0; i<content_length; i++)
    {
        if(content[i] == '\n')
            line++;

        while (q>0 && pattern[q] != content[i])
            q = prefix[q];

        if(pattern[q] == content[i])
            q = q + 1;
        if(q == pattern_length)
        {
            (*results)[*results_count].line = line;
            (*results)[*results_count].position = i - pattern_length + 1;
            (*results_count)++;
        }
    }

    (*results_count)--;

    free(prefix);
}
