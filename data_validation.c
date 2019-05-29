#include <stdio.h>
#include <string.h> /* strlen(), strcmp() */
#include <stdlib.h> /* strtol() */

#include "structs.h" /* event_manager_t, patron_t, staff_t, event_t */

/**************************************************************
 * Function Name: 
 * Author(s):
 * Inputs:
 * Outputs: 
 * Description: 
**************************************************************/
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

/**************************************************************
 * Function Name: 
 * Author(s):
 * Inputs:
 * Outputs: 
 * Description: 
**************************************************************/
int convert_int(char* input)
{
    return (int) strtol(input, NULL, 10);
}

/**************************************************************
 * Function Name: 
 * Author(s):
 * Inputs:
 * Outputs: 
 * Description: 
**************************************************************/
int username_taken(event_manager_t* event_manager, char* username)
{
    int i;
    for (i = 0; i < list_count(&event_manager->users); i++)
    {
        person_t* user = (person_t*) list_get(&event_manager->users, i)->data;
        if(event_manager->runtime_mode == MODE_DEBUG)
        {
            printf("DEBUG: %s | %s\n", username, user->username);
        }

        if ( strcmp(user->username, username) == 0 )
        {

            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Username '%s' exists\n", username);
            }
            return 1;
        }
    }
    if(event_manager->runtime_mode == MODE_DEBUG)
    {
        printf("DEBUG: Username '%s' does not exist\n", username);
    }
    return 0;
}