#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[8];

    // Create array to store plate numbers
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fgets(buffer, sizeof(buffer),infile)!=NULL)
    {
        // Replace '\n' with '\0'
        char *pos;
        if((pos=strchr(buffer,'\n'))!=NULL)
        {
            *pos='\0';
        }

        // Save plate number in array
        plates[idx] = strdup(buffer);
        idx++;
    }

    fclose(infile);

    for (int i = 0; i < idx; i++)
    {
        printf("%s\n", plates[i]);
        free(plates[i]);
    }
    return 0;
}
