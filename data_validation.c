#include <string.h> /* strlen(), strcmp() */
#include <stdlib.h> /* strtol() */

#include "structs.h" /* event_manager_t, patron_t, staff_t, event_t */

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
    int i;
    for (i = 0; i < event_manager.num_users; i++)
    {
        if ( strcmp(event_manager.users[i].username, username) == 0 )
        {
            return 1;
        }
    }

    return 0;
}