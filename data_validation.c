#include <stdio.h>
#include <string.h> /* strlen(), strcmp() */
#include <stdlib.h> /* strtol() */

#include "structs.h" /* event_manager_t, patron_t, staff_t, event_t */

/**************************************************************
 * Function Name: valid_int
 * Author(s): Ryan
 * Inputs: input(string pointer)
 * Outputs: Boolean
 * Description: Outputs true or false depending on whether the input ...
 *              is an integer that meets the criteria or not
**************************************************************/
int valid_int(char* input)
{
    
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
 * Function Name: convert_int
 * Author(s): Ryan
 * Inputs: input(string pointer)
 * Outputs: integer
 * Description: Returns the input converted to an integer
**************************************************************/
int convert_int(char* input)
{
    return (int) strtol(input, NULL, 10);
}

/**************************************************************
 * Function Name: username_taken
 * Author(s): Ryan 
 * Inputs: event_manager(pointer), username(sting pointer)
 * Outputs: Boolean
 * Description: Outputs a true or false depending on the supplied username is
 *              already taken. 
 *              The function loops through each user of the users linked list 
 *              and compares the username to the supplied username.
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