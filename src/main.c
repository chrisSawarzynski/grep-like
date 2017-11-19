#include <string.h>
#include <stdio.h>
#include "result/result.h"
#include "read_file/read_file.h"
#include "find_pattern/find_pattern.h"
#include "print_result/print_result.h"

int main(int argc, char* argv[])
{
    int i;
    int error;
    Result *results;
    int *result_count;
    char *content;

    for(i=2; i<argc; i++)
    {
        content=NULL;
        results=NULL;
        result_count=NULL;
        error=0;

        read_file(argv[i], &error, content);

        if(error == 1)
        {
            perror(content);
            free(content);
            continue;
        }

        find_pattern(argv[1], content, results, result_count);

        print_result(results, result_count);

        free(content);
    }
    return 0;
}
