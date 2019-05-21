#include <stdio.h> /* printf() */
#include <string.h>

#include "structs.h" /* event_manager_t, event_t */
#include "function_prototypes.h" /* print_menu_login(), print_menu_main(), scan_int() */

void menu_login(event_manager_t* event_manager)
{
    print_menu_login();
    int user_selection = scan_int();
    switch(user_selection)
    {
        case 1:
            #ifdef DEBUG /* For debugging */
                printf("Login Selected\n");
            #endif
            switch(login(event_manager))
            {
                case 1:
                    printf("User Login: %s\n", event_manager->current_logged_in_user.username);
                    menu_main(event_manager);
                    break;
                case 2:
                    printf("Admin Login: %s\n", event_manager->current_logged_in_user.username);
                    menu_admin(event_manager);
                    break;
            }
            break;
        case 2:
            #ifdef DEBUG /* For debugging */
                printf("Create Account Selected\n");
            #endif
            account_creation(event_manager);
            break;



        case 9:
            #ifdef DEBUG /* For debugging */
                printf("Exit Selected\n");
            #endif
            printf("Exiting program\n");
            return;
        default:
            printf("Not a valid entry\n");
            break;
    }
    menu_login(event_manager);
    return;
}

void menu_main(event_manager_t* event_manager)
{
    print_menu_main(event_manager->current_logged_in_user.username);
    int user_selection = scan_int();
    switch(user_selection)
    {
        case 1:
            #ifdef DEBUG /* For debugging */
                printf("Add Event Selected\n");
            #endif

            break;
        case 2:
            #ifdef DEBUG /* For debugging */
                printf("Edit Event Selected\n");
            #endif

            /* TODO: Move the following function calls to their own function */
            printf("Please select the event you would like to edit\n");
            list_event_names(*event_manager);
            int event_selection = scan_int();
            printf("%i selected\n", event_selection);
            break;
        case 3:
            #ifdef DEBUG /* For debugging */
                printf("Join Event Selected\n");
            #endif

            break;



        case 9:
            #ifdef DEBUG /* For debugging */
                printf("Logout Selected\n");
            #endif
            printf("Logging out\n\n");
            return;
        default:
            printf("Not a valid entry\n");
            break;
    }
    menu_main(event_manager);
    return;
}

void menu_admin(event_manager_t* event_manager)
{
    print_menu_admin();
    int user_selection = scan_int();
    switch(user_selection)
    {
        case 1:
            list_all(*event_manager);
            break;
        case 2:
            list_event_names(*event_manager);
            break;
        case 9:
            printf("Logging out\n\n");
            return;
        default:
            printf("Not a valid entry\n");
            break;
    }
    menu_admin(event_manager);
    return;
}


void print_menu_login(void)
{
    printf("\nLogin Menu\n");
    printf("Please select an option from the following list\n");
    printf("1. Login\n");
    printf("2. Create Account\n");
    printf("9. Exit\n");
    printf("> ");
    return;
}

void print_menu_main(char* current_logged_in_username)
{
    printf("\nMain Menu\n");
    printf("Currently logged in as '%s'\n\n", current_logged_in_username);
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
    printf("1. List All\n");
    printf("2. List Events\n");
    printf("9. Logout\n");
    printf(">");
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

        printf("%i: %s\n", i, event.name);
    }
    return;
}

void list_all(event_manager_t event_manager)
{
    /*TODO*/
    return;
}