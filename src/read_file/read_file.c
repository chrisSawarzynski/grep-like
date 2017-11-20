#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include "read_file.h"

void read_file(const char name[], int *error, char **content)
{
    int fd = open(name, O_RDONLY);

    if (fd == -1) 
    {
        *error = 1;
        content = realloc(*content, (sizeof *content) * 5);
        *content="error";
        return;
    }

    struct stat stat_buf;
    fstat(fd, &stat_buf);

    *content = (char *)realloc(*content, stat_buf.st_size);


    read(fd, *content, stat_buf.st_size);
    printf("content: %s\n", *content);

    close(fd);
}
