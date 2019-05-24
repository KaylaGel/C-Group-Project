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