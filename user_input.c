#include <string.h>
#include <stdlib.h>

int valid_int(char* input)
{
    /* TODO: Account for negatives */
    int i;
    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}

int convert_int(char* input)
{
    return (int)strtol(input, NULL, 10);
}