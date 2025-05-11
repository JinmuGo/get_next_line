#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1 = open("text/sample_bonus1.txt", O_RDONLY);
    int fd2 = open("text/sample_bonus2.txt", O_RDONLY);
    int fd3 = open("text/sample_bonus3.txt", O_RDONLY);
    char *line1;
    char *line2;
    char *line3;

    if (fd1 == -1 || fd2 == -1 || fd3 == -1)
    {
        printf("Error: Could not open one or more files\n");
        return (1);
    }

    printf("Reading from multiple files simultaneously:\n\n");
    
    while (1)
    {
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);
        line3 = get_next_line(fd3);

        if (line1 == NULL && line2 == NULL && line3 == NULL)
            break;

        if (line1 != NULL)
        {
            printf("File 1: %s", line1);
            free(line1);
        }
        if (line2 != NULL)
        {
            printf("File 2: %s", line2);
            free(line2);
        }
        if (line3 != NULL)
        {
            printf("File 3: %s", line3);
            free(line3);
        }
    }

    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}