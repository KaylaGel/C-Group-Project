#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void scan_string(char* input, int len)
{
    /* Get one character from stdin and save it to input */
    fgets(input, len + 1, stdin);

    /* Clear the rest of the stdin buffer */
    while ((getchar()) != '\n');
    return;
}

void scan_char(char* input)
{
    scanString(input, 1);
    return;
}

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