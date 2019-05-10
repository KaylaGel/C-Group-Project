#include <stdio.h> /* printf() */

#include "structs.h"
#include "function_prototypes.h"

void menu_login(event_t* events, int* event_count)
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
            break;
        default:
            printf("Not a valid entry\n");
            menu_login(events, event_count);
            break;
    }
    return;
}

void menu_main(event_t* events, int* event_count)
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
            break;
        case 3:
            printf("Join Event Selected\n");
            break;
        case 4:
            printf("Exit program Selected\n");
            break;
        default:
            printf("Not a valid entry\n");
            menu_main(events, event_count);
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