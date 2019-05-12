#include <stdio.h> /* printf() */

#include "structs.h"
#include "function_prototypes.h"

void menu_login(event_manager_t* event_manager)
{
    print_menu_login();
    int user_selection = scan_int();
    switch(user_selection)
    {
        case 1:
            printf("Login Selected\n");
            break;
        case 2:
            printf("Create Account Selected\n");
            break;
        case 3:
            printf("Exit Selected\n");
            return;
        default:
            printf("Not a valid entry\n");
            menu_login(event_manager);
            return;
    }
    return;
}

void menu_main(event_manager_t* event_manager)
{
    print_menu_main();
    int user_selection = scan_int();
    switch(user_selection)
    {
        case 1:
            printf("Add Event Selected\n");
            break;
        case 2:
            printf("Edit Event Selected\n");
            /* TODO: Move the following function calls to their own function */
            printf("Please select the event you would like to edit\n");
            list_event_names(*event_manager);
            int event_selection = scan_int();
            printf("%i selected\n", event_selection);
            break;
        case 3:
            printf("Join Event Selected\n");
            break;
        case 4:
            printf("Exit program Selected\n");
            break;
        default:
            printf("Not a valid entry\n");
            menu_main(event_manager);
            break;
    }
    return;
}


void print_menu_login(void)
{
    printf("1. Login\n");
    printf("2. Create Account\n");
    printf("3. Exit\n");
    printf("> ");
    return;
}
void print_menu_main(void)
{
    printf("1. Add Event\n");
    printf("2. Edit Event\n");
    printf("3. Join Event\n");
    printf("4. Exit program\n");
    printf("> ");
    return;
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