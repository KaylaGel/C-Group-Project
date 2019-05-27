#include <stdio.h>
#include <string.h>

#include "structs.h" /* event_t */

int search_event(node_t* list_node, char* event_name)
{
    int i;

    for (i = 0; i < list_count(list_node); i++)
    {
        event_t* event = (event_t*) list_get(list_node, i)->data;

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

int search_event_edit(node_t* list_node)
{
    char event_name[MAX_NAME_LEN+1];

    printf("Enter the event name you would like to edit\n");
    printf("> ");
    scanf("%s", event_name);

    return search_event(list_node, event_name);
}

int search_event_join(node_t* list_node)
{
    char event_name[MAX_NAME_LEN+1];

    printf("Enter the event name you would like to join\n");
    printf("> ");
    scanf("%s", event_name);

    return search_event(list_node, event_name);
}


int search_user(node_t* list_node, char* username)
{
    int i;

    for (i = 0; i < list_count(list_node); i++)
    {
        person_t* user = (person_t*) list_get(list_node, i)->data;
        if ( strcmp(username, user->username) == 0 )
        {
            return i;
        }
    }
    return -1;
}

int search_user_add(node_t* list_node)
{
    char username[MAX_NAME_LEN+1];

    printf("Who would you like to add to the event?\n");
    printf("> ");
    scanf("%s", username);

    return search_user(list_node, username);
}
int search_user_remove(node_t* list_node)
{
    char username[MAX_NAME_LEN+1];

    printf("Who would you like to remove from the event?\n");
    printf("> ");
    scanf("%s", username);

    return search_user(list_node, username);
}