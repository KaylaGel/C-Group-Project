#include <stdio.h>
#include <string.h>

#include "structs.h" /* event_t */

int search_event(linked_list_t* list, char* event_name)
{
    int i;

    for (i = 0; i < list_count(list); i++)
    {
        event_t* event = (event_t*) list_get(list, i)->data;

        #ifdef DEBUG /* For debugging */
            printf("DEBUG: %-*s | %-*s\n", MAX_NAME_LEN, event_name,
            MAX_NAME_LEN, event->name);
        #endif

        if ( strcmp(event_name, event->name) == 0 )
        {
            return i;
        }
    }
    return -1;
}

int search_event_edit(linked_list_t* list)
{
    char event_name[MAX_NAME_LEN+1];

    printf("Enter the event name you would like to edit\n");
    printf("> ");
    scanf("%s", event_name);

    return search_event(list, event_name);
}

int search_event_join(linked_list_t* list)
{
    char event_name[MAX_NAME_LEN+1];

    printf("Enter the event name you would like to join\n");
    printf("> ");
    scanf("%s", event_name);

    return search_event(list, event_name);
}

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

int search_user_add(linked_list_t* list)
{
    char username[MAX_NAME_LEN+1];

    printf("Who would you like to add to the event?\n");
    printf("> ");
    scanf("%s", username);

    return search_user(list, username);
}
int search_user_remove(linked_list_t* list)
{
    char username[MAX_NAME_LEN+1];

    printf("Who would you like to remove from the event?\n");
    printf("> ");
    scanf("%s", username);

    return search_user(list, username);
}