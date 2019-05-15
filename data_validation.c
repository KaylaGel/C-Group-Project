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
    /* Loop through each event */
    int i;
    for (i = 0; i < event_manager.num_events; i++)
    {
        event_t event = event_manager.events[i];

        /* Loop through each staff member of the currently iterated event */
        int j;
        for (j = 0; j < event.num_staff; j++)
        {
            staff_t staff = event.staff[j];

            /* Compare the currently iterated staff member's username with the supplied username */
            if( strcmp(staff.personal.username, username) )
            {
                return 1;
            }
        }

        /* Loop through each patron of the currently iterated event */
        int k;
        for (k = 0; k < event.num_patrons; k++)
        {
            person_t patron = event.patrons[j];

            /* Compare the currently iterated patron's username with the supplied username */
            if( strcmp(patron.username, username) )
            {
                return 1;
            }
        }
    }
    return 0;
}