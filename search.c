#include <stdio.h>

#include "structs.h" /* event_t */

int search_event(event_t* events, int event_count, char* event_name)
{
    int i;

    for (i = 1; i < event_count; i++)
    {
        if (event_name == events[i].name)
        {
            return i;
        }
    }
    return -1;
}
