#include <stdio.h>

#include "structs.h"
#include "definitions.h"

void print_event_name(event_t event, int event_index)
{
    printf("%i: ", event_index);
    /* Print event name, right padded with spaces up until MAX_NAME_LEN length */
    printf("%-*s", MAX_NAME_LEN, event.name);

    /* If an event is free */
    if(event.free_event)
        printf(" | Free Event");
    printf("\n");
    return;
}

void print_event_details(event_t event, int event_index)
{
    print_event_name(event, event_index);

    printf("\tCoordinator:\n");
    printf("\t\t%-*s | ", MAX_NAME_LEN, event.coordinator.username);
    printf("%s %s\n", event.coordinator.firstname, event.coordinator.lastname);

    printf("\tStaff:\n");
    if(event.num_staff == 0)
        printf("\t\tNo Staff\n");
    int i;
    for (i = 0; i < event.num_staff; i++)
    {
        person_t current_staff = event.staff[i];
        printf("\t\t");
        printf("%-*s | ", MAX_NAME_LEN, current_staff.username);
        printf("%s %s\n", current_staff.firstname, current_staff.lastname);
    }

    printf("\tPatrons:\n");
    if(event.num_patrons == 0)
        printf("\t\tNo Patrons\n");
    int j;
    for (j = 0; j < event.num_staff; j++)
    {
        person_t current_staff = event.staff[i];
        printf("\t\t");
        printf("%-*s | ", MAX_NAME_LEN, current_staff.username);
        printf("%s %s\n", current_staff.firstname, current_staff.lastname);
    }
    printf("\n");
}