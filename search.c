#include <stdio.h>
#include <string.h>

#include "structs.h" /* event_t */

#define DEBUG

int search_event(event_manager_t* event_manager, char* event_name)
{
    int i;

    for (i = 0; i < event_manager->num_events; i++)
    {
        #ifdef DEBUG /* For debugging */
            printf("DEBUG: %-*s | %-*s\n", MAX_NAME_LEN, event_name,
            MAX_NAME_LEN,
                    event_manager->events[i].name);
        #endif

        if ( strcmp(event_name, event_manager->events[i].name) == 0 )
        {
            return i;
        }
    }
    return -1;
}

int search_event_edit(event_manager_t* event_manager)
{
    char event_name[MAX_NAME_LEN+1];

    printf("Enter the event name you would like to edit\n");
    printf("> ");
    scanf("%s", event_name);

    return search_event(event_manager, event_name);
}

int search_event_join(event_manager_t* event_manager)
{
    char event_name[MAX_NAME_LEN+1];

    printf("Enter the event name you would like to join\n");
    printf("> ");
    scanf("%s", event_name);

    return search_event(event_manager, event_name);
}


int search_user(event_manager_t* event_manager, char* username)
{
    int i;

    for (i = 0; i < event_manager->num_users; i++)
    {
        if ( strcmp(username, event_manager->users[i].username) == 0 )
        {
            return i;
        }
    }
    return -1;
}

int search_user_add(event_manager_t* event_manager)
{
    char username[MAX_NAME_LEN+1];

    printf("Who would you like to add to the event?\n");
    printf("> ");
    scanf("%s", username);

    return search_user(event_manager, username);
}