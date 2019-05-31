#include <stdio.h> /* printf */

#include "structs.h" /* event_manager_t, event_t, person_t */
#include "definitions.h" /* MAX_NAME_LEN  */
#include "linked_list.h" /* list_count, list_get */
#include "function_prototypes.h" /* print_event_name, print_user_details */

/**************************************************************
 * Function Name: print_event_name
 * Author(s): Kayla
 * Inputs: event - Struct Pointer, event_index - Integer
 * Outputs: N/A
 * Description: Prints out the basic details of the event and it index
**************************************************************/

void print_event_name(const event_t* event, const int event_index)
{
    printf("\t%i: ", event_index);
    /* Print event name, right padded with spaces up until MAX_NAME_LEN
     * length */
    printf("%-*s | ", MAX_NAME_LEN, event->name);
    printf("%-*s", MAX_NAME_LEN, event->event_type);

    /* If an event is free */
    if(event->free_event)
        printf(" | Free Event");
    printf("\n");
    return;
}

/**************************************************************
 * Function Name: print_event_details
 * Author(s): Kayla
 * Inputs: event - Struct Pointer, event_index - Integer
 * Outputs: N/A
 * Description: Print out the full details of the event
**************************************************************/

void print_event_details(const event_t* event, const int event_index)
{
    print_event_name(event, event_index);

    printf("\t\tLocation: %i %s %s %i %s\n", event->location.street_num,
                                             event->location.street_name,
                                             event->location.suburb,
                                             event->location.postcode,
                                             event->location.state);
    printf("\t\tDate: %02i:%02i %i/%i/%i\n", event->event_date.hour,
                                         event->event_date.minute,
                                         event->event_date.day,
                                         event->event_date.month,
                                         event->event_date.year );

    printf("\t\tCoordinator:\n");
    printf("\t\t\t%-*s | ", MAX_NAME_LEN, event->coordinator->username);
    printf("%s %s\n", event->coordinator->firstname,
                      event->coordinator->lastname);

    printf("\t\tStaff:\n");
    if(list_count(&event->staff) == 0)
    {
        printf("\t\t\tNo Staff\n");
    }
    int i;
    for (i = 0; i < list_count(&event->staff); i++)
    {
        person_t* current_staff = (person_t *) list_get(&event->staff, i)->data;
        printf("\t\t\t");
        printf("%-*s | ", MAX_NAME_LEN, current_staff->username);
        printf("%s %s\n", current_staff->firstname, current_staff->lastname);
    }

    printf("\t\tPatrons:\n");
    if(list_count(&event->patrons) == 0)
        printf("\t\t\tNo Patrons\n");
    int j;
    for (j = 0; j < list_count(&event->patrons); j++)
    {
        person_t* current_patron =
                (person_t *) list_get(&event->patrons, j)->data;
        printf("\t\t\t");
        printf("%-*s | ", MAX_NAME_LEN, current_patron->username);
        printf("%s %s\n", current_patron->firstname, current_patron->lastname);
    }
    printf("\n");
}

/**************************************************************
 * Function Name: list_events
 * Author(s): Kayla
 * Inputs: event_manager - Struct Pointer
 * Outputs: 
 * Description: Calls the print_event_name function for each event
**************************************************************/

void list_events(const event_manager_t* event_manager)
{
    if(list_count(&event_manager->events) == 0)
    {
        printf("No events\n");
        return;
    }

    int i;
    for (i = 0; i < list_count(&event_manager->events); i++)
    {
        event_t* event = (event_t*) list_get(&event_manager->events, i)->data;
        print_event_name(event, i + 1);
    }
    return;
}

/**************************************************************
 * Function Name: print_user_details
 * Author(s): Kayla
 * Inputs:user - Struct Pointer, user_index - Integer
 * Outputs: N/A
 * Description: Prints the details of a user
**************************************************************/

void print_user_details(const person_t* user, const int user_index)
{
    printf("\t%i: %-*s\n", user_index, MAX_NAME_LEN, user->username);
    printf("\t\tName: %s %s\n", user->firstname, user->lastname);
    printf("\t\tPassword: %s\n", user->password);
    printf("\t\tDOB: %i/%i/%i\n", user->DOB.day,
                                  user->DOB.month,
                                  user->DOB.year);
    return;
}

/**************************************************************
 * Function Name: list_all
 * Author(s): Kayla
 * Inputs: event_manager - Struct Pointer
 * Outputs: N/A
 * Description: Calls the "print details" function for every user and event 
**************************************************************/

void list_all(const event_manager_t* event_manager)
{
    int i;

    printf("Events\n");
    for (i = 0; i < list_count(&event_manager->events); i++)
    {
        event_t* event = (event_t*) list_get(&event_manager->events, i)->data;

        print_event_details(event, i + 1);
    }
    if(i == 0)
    {
        printf("\tNo Events\n");
    }
    printf("Users\n");
    for (i = 0; i < list_count(&event_manager->users); i++)
    {
        person_t* user = (person_t*) list_get(&event_manager->users, i)->data;
        print_user_details(user, i + 1);
    }
    if(i == 0)
    {
        printf("\tNo Users\n");
    }
    return;
}

/**************************************************************
 * Function Name: list_events_detail
 * Author(s): Kayla
 * Inputs: event_manager - Struct Pointer
 * Outputs: N/A
 * Description: Calls the print_event_details function for each event
**************************************************************/

void list_events_detail(const event_manager_t* event_manager)
{
    int i;

    printf("Events\n");
    for (i = 0; i < list_count(&event_manager->events); i++)
    {
        event_t* event = (event_t*) list_get(&event_manager->events, i)->data;

        print_event_details(event, i + 1);
    }
    if(i == 0)
    {
        printf("\tNo Events\n");
    }
    return;
}

/**************************************************************
 * Function Name: list_users_detail
 * Author(s): Kayla
 * Inputs: event_manager - Struct Pointer
 * Outputs: N/A
 * Description: calls the print_user_details function for every user
**************************************************************/

void list_users_detail(const event_manager_t* event_manager)
{
    int i;

    printf("Users\n");
    for (i = 0; i < list_count(&event_manager->users); i++)
    {
        person_t* user = (person_t*) list_get(&event_manager->users, i)->data;
        print_user_details(user, i + 1);
    }
    if(i == 0)
    {
        printf("\tNo Users\n");
    }
    return;
}

/**************************************************************
 * Function Name: print_menu_login
 * Author(s): Tylar
 * Inputs: N/A
 * Outputs: N/A
 * Description: Prints the login menu 
**************************************************************/

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

/**************************************************************
 * Function Name: print_menu_main
 * Author(s): Tylar
 * Inputs: current_logged_in_username - Character Pointer
 * Outputs: N/A
 * Description: Prints the main menu
**************************************************************/

void print_menu_main(const char* current_logged_in_username)
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

/**************************************************************
 * Function Name: print_menu_admin
 * Author(s): Tylar
 * Inputs: N/A
 * Outputs: N/A
 * Description: Prints the admin menu
**************************************************************/

void print_menu_admin(void)
{
    printf("\nAdmin Menu\n\n");
    printf("1. List All\n");
    printf("2. List Events\n");
    printf("3. List Events - Detailed\n");
    printf("4. List Users\n");
    printf("7. Save Database\n");
    printf("8. Load Database\n");
    printf("9. Logout\n");
    printf("> ");
    return;
}

/**************************************************************
 * Function Name: print_menu_edit
 * Author(s): Jacob
 * Inputs: N/A
 * Outputs: N/A
 * Description: Prints the edit menu and the event that is being edited
**************************************************************/

void print_menu_edit(const char* event_name)
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

/**************************************************************
 * Function Name: print_menu_edit_staff
 * Author(s): Jacob
 * Inputs: N/A
 * Outputs: N/A
 * Description: Prints the edit staff menu
**************************************************************/

void print_menu_edit_staff(void)
{
    printf("Edit Staff Menu\n");
    printf("1. Add Staff\n");
    printf("2. Remove Staff\n");
    printf("9. Exit\n");
    printf("> ");
    return;
}

/**************************************************************
 * Function Name: print_menu_edit_patrons
 * Author(s): Jacob
 * Inputs: N/A
 * Outputs: N/A
 * Description: Prints the edit patron menu
**************************************************************/

void print_menu_edit_patrons(void)
{
    printf("Edit Patron Menu\n");
    printf("1. Add Patron\n");
    printf("2. Remove Patron\n");
    printf("9. Exit\n");
    printf("> ");
    return;
}
/**************************************************************
 * Function Name: print_info
 * Author(s): Ryan
 * Inputs: N/A
 * Outputs: N/A
 * Description: Prints the information about this program
**************************************************************/
void print_info(void)
{
    printf(" \n"
           " ---- Welcome to EventManager v2.4 Information Mode ----\n"
           " \n"
           "Description: This program is specifically designed to help \n"
           "event organisers and patrons access event information and \n"
           "join them if they please. \n"
           "\n"
           "Note: All private information entered into the program \n"
           "will be saved in an encrypted format. Event HUB aims to \n"
           "provide a platform where anyone can create, edit or join \n"
           "an event. By creating an event, the user immediately \n"
           "becomes an event coordinator where they can specify the \n"
           "event name, whether or not they would like the event to be \n"
           "free, the type of event and the location of the event.\n"
           "\n"
           "Any user can create an account and events, however, \n"
           "only the Admin is able to save and load database files. \n"
           "Additionally, when a user creates an account, their \n"
           "passwords are immediately encrypted and when the admin \n"
           "saves the database file, the whole file is encrypted. \n"
           "Once the events have been created, the event coordinator \n"
           "is able to add staff or simply edit any important event \n"
           "details. If a user decides they want to join an event \n"
           "as a patron, then their details are added to the event. \n"
           "\n"
           "It is important to note that whilst our idea has been \n"
           "inspired by the university society system, we have not \n"
           "designed our criteria, specifically for UTS as we \n"
           "decided to create a broad design for the benefit and \n"
           "use of everyone.\n");
    return;
}