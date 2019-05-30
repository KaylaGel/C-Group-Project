#include <stdio.h>
#include <string.h>

#include "structs.h" /* event_t */

/**************************************************************
 * Function Name: search_event
 * Author(s): Dee-Jay
 * Inputs: list - Struct Pointer, event_name - Character Pointer
 * Outputs: Integer
 * Description: Goes through each event in the supplied list and 
 *              compares the supplied event name with it and returns 
 *              the index of the found event
**************************************************************/

int search_event(linked_list_t* list, char* event_name)
{
    int i;

    for (i = 0; i < list_count(list); i++)
    {
        event_t* event = (event_t*) list_get(list, i)->data;


        if ( strcmp(event_name, event->name) == 0 )
        {
            return i;
        }
    }
    return -1;
}

/**************************************************************
 * Function Name: search_event_edit
 * Author(s): Dee-Jay
 * Inputs: list - Struct Pointer
 * Outputs: 
 * Description: Helper function for the edit event menu
 *              Asks the user what event they would like to edit and 
 *              returns the index of the event found
**************************************************************/

int search_event_edit(linked_list_t* list)
{
    char event_name[MAX_NAME_LEN+1];

    printf("Enter the event name you would like to edit\n");
    printf("> ");
    scanf("%s", event_name);

    return search_event(list, event_name);
}

/**************************************************************
 * Function Name: search_event_join
 * Author(s): Dee-Jay
 * Inputs: list - Struct Pointer
 * Outputs: event_name
 * Description: Helper function for the join event menu
 *              Asks the user what event they would like to join and 
 *              returns the index of the event found
**************************************************************/

int search_event_join(linked_list_t* list)
{
    char event_name[MAX_NAME_LEN+1];

    printf("Enter the event name you would like to join\n");
    printf("> ");
    scanf("%s", event_name);

    return search_event(list, event_name);
}

/**************************************************************
 * Function Name: search_user
 * Author(s): Dee-Jay
 * Inputs: list - Struct Pointer, username - Character Pointer
 * Outputs: Integer
 * Description: Goes through each user in the supplied list and compares the 
 *              supplied username with it and returns the index of the 
 *              found user
**************************************************************/

int search_user(linked_list_t* list, char* username)
{
    int i;

    for (i = 0; i < list_count(list); i++)
    {
        person_t* user = (person_t*) list_get(list, i)->data;
        if ( strcmp(username, user->username) == 0 )
        {
            return i;
        }
    }
    return -1;
}

/**************************************************************
 * Function Name: search_user_add
 * Author(s): Dee-Jay
 * Inputs: list - Struct Pointer
 * Outputs: username
 * Description: Helper function for the add user menu
 *              Asks the user what user they would like to add to the event and
 *              returns the index of the user found
**************************************************************/

int search_user_add(linked_list_t* list)
{
    char username[MAX_NAME_LEN+1];

    printf("Who would you like to add to the event?\n");
    printf("> ");
    scanf("%s", username);

    return search_user(list, username);
}

/**************************************************************
 * Function Name: search_user_remove
 * Author(s): Dee-Jay
 * Inputs: list - Struct Pointer
 * Outputs: username
 * Description: Helper function for the add user menu
 *              Asks the user what user they would like to remove from the 
 *              event and returns the index of the user found
**************************************************************/

int search_user_remove(linked_list_t* list)
{
    char username[MAX_NAME_LEN+1];

    printf("Who would you like to remove from the event?\n");
    printf("> ");
    scanf("%s", username);

    return search_user(list, username);
}