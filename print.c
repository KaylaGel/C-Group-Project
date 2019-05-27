#include <stdio.h>

#include "structs.h"
#include "definitions.h"

void print_event_name(event_t* event, int event_index)
{
    printf("\t%i: ", event_index);
    /* Print event name, right padded with spaces up until MAX_NAME_LEN
     * length */
    printf("%-*s", MAX_NAME_LEN, event->name);

    /* If an event is free */
    if(event->free_event)
        printf(" | Free Event");
    printf("\n");
    return;
}

void print_event_details(event_t* event, int event_index)
{
    print_event_name(event, event_index);
    printf("\t\tCoordinator:\n");
    printf("\t\t\t%-*s | ", MAX_NAME_LEN, event->coordinator->username);
    printf("%s %s\n", event->coordinator->firstname,
                      event->coordinator->lastname);

    printf("\t\tStaff:\n");
    if(list_count(event->staff) == 0)
    {
        printf("\t\t\tNo Staff\n");
    }
    int i;
    for (i = 0; i < list_count(event->staff); i++)
    {
        person_t* current_staff = (person_t *) list_get(event->staff, i)->data;
        printf("\t\t\t");
        printf("%-*s | ", MAX_NAME_LEN, current_staff->username);
        printf("%s %s\n", current_staff->firstname, current_staff->lastname);
    }

    printf("\t\tPatrons:\n");
    if(list_count(event->patrons) == 0)
        printf("\t\t\tNo Patrons\n");
    int j;
    for (j = 0; j < list_count(event->patrons); j++)
    {
        person_t* current_patron =
                (person_t *) list_get(event->patrons, j)->data;
        printf("\t\t\t");
        printf("%-*s | ", MAX_NAME_LEN, current_patron->username);
        printf("%s %s\n", current_patron->firstname, current_patron->lastname);
    }
    printf("\n");
}

void list_event_names(event_manager_t* event_manager)
{
    if(list_count(event_manager->events) == 0)
    {
        printf("No events\n");
        return;
    }

    int i;
    for (i = 0; i < list_count(event_manager->events); i++)
    {
        event_t* event = (event_t*) list_get(event_manager->events, i)->data;
        print_event_name(event, i + 1);
    }
    return;
}

void print_user_details(person_t* user, int user_index)
{
    printf("\t%i: %-*s\n", user_index, MAX_NAME_LEN, user->username);
    printf("\t\tName: %s %s\n", user->firstname, user->lastname);
    printf("\t\tPassword: %s\n", user->password);
    printf("\t\tDOB: %i/%i/%i\n", user->DOB.day,
                                  user->DOB.month,
                                  user->DOB.year);
    return;
}

void list_all(event_manager_t* event_manager)
{
    int i;

    printf("Events\n");
    for (i = 0; i < list_count(event_manager->events); i++)
    {
        event_t* event = (event_t*) list_get(event_manager->events, i)->data;

        print_event_details(event, i + 1);
    }
    if(i == 0)
    {
        printf("\tNo Events\n");
    }
    printf("Users\n");
    for (i = 0; i < list_count(event_manager->users); i++)
    {
        person_t* user = (person_t*) list_get(event_manager->users, i)->data;
        print_user_details(user, i + 1);
    }
    if(i == 0)
    {
        printf("\tNo Users\n");
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

void print_menu_edit_staff(void)
{
    printf("Edit Staff Menu\n");
    printf("1. Add Staff\n");
    printf("2. Remove Staff\n");
    printf("9. Exit\n");
    printf("> ");
    return;
}

void print_menu_edit_patrons(void)
{
    printf("Edit Patron Menu\n");
    printf("1. Add Patron\n");
    printf("2. Remove Patron\n");
    printf("9. Exit\n");
    printf("> ");
    return;
}