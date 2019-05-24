#include <stdio.h>

#include "structs.h"
#include "definitions.h"

void print_event_name(event_t event, int event_index)
{
    printf("%i: ", event_index);
    /* Print event name, right padded with spaces up until MAX_NAME_LEN
     * length */
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

void list_event_names(event_manager_t event_manager)
{
    if(event_manager.num_events == 0)
    {
        printf("No events\n");
        return;
    }

    int i;
    for (i = 0; i < event_manager.num_events; i++)
    {
        event_t event = event_manager.events[i];
        print_event_name(event, i + 1);
    }
    return;
}

void list_all(event_manager_t event_manager)
{
    printf("Events\n\n");
    int i;
    for (i = 0; i < event_manager.num_events; i++)
    {
        event_t event = event_manager.events[i];
        print_event_details(event, i + 1);
    }

    /*TODO*/
    return;
}


void print_menu_login(void)
{
    printf("\nLogin Menu\n\n");
    printf("Please select an option from the following list\n");
    printf("1. Login\n");
    printf("2. Create Account\n");
    printf("9. Exit\n");
    printf("> ");
    return;
}

void print_menu_main(char* current_logged_in_username)
{
    printf("\nMain Menu\n\n");
    printf("Currently logged in as '%s'\n", current_logged_in_username);
    printf("Please select an option from the following list\n");
    printf("1. Add Event\n");
    printf("2. Edit Event\n");
    printf("3. Join Event\n");
    printf("9. Logout\n");
    printf("> ");
    return;
}

void print_menu_admin(void)
{
    printf("\nAdmin Menu\n\n");
    printf("1. List All\n");
    printf("2. List Events\n");
    printf("9. Logout\n");
    printf("> ");
    return;
}

void print_menu_edit(char* event_name)
{
    printf("Edit Menu\n");
    printf("Currently editing event '%s'\n", event_name);
    printf("1. Edit Event Name\n");
    printf("2. Edit Event Type\n");
    printf("3. Edit Event Location\n");
    printf("4. Edit Event Time\n");
    printf("5. Edit Event Staff\n");
    printf("6. Edit Event Patrons\n");
    printf("9. Exit\n");
    printf("> ");
    return;
}