#include <stdlib.h>
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
    int result_count;
    Result *results;
    char *content;

    for(i=2; i<argc; i++)
    {
        error=0;
        result_count=0;
        results=NULL;
        content=NULL;
        
        read_file(argv[i], &error, &content);
        printf("Content: %s", content);

        if(error == 1)
        {
            perror(content);
            free(content);
            continue;
        }

        find_pattern(argv[1], content, results, &result_count);

        print_result(results, &result_count);

        free(content);
    }
    return 0;
}
