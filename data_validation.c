#include <string.h> /* strlen() */
#include <stdlib.h> /* strtol() */

#include "structs.h"

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
    return (int) strtol(input, NULL, 10);
}

int username_taken(event_manager_t event_manager, char* username)
{
    /* TODO: Loop through every user in each event and test to see if the username is taken */
    return 0;
}