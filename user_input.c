#include <stdio.h>


void scanString(char* input, int len)
{
    /* Get one character from stdin and save it to input */
    fgets(input, len + 1, stdin);

    /* Clear the rest of the stdin buffer */
    while ((getchar()) != '\n');
    return;
}

void scanChar(char* input)
{
    scanString(input, 1);
    return;
}