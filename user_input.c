#include <stdio.h>


void scanChar(char* input)
{
    /* Get one character from stdin and save it to input */
    fgets(input, 1, stdin);

    /* Clear the rest of the stdin buffer */
    while ((getchar()) != '\n');
    return;
}

void scanString(char* input, int len)
{
    /* Get one character from stdin and save it to input */
    fgets(input, len, stdin);

    /* Clear the rest of the stdin buffer */
    while ((getchar()) != '\n');
    return;
}