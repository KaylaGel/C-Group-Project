#include <stdio.h> /* printf() */
#include <string.h>

#include "structs.h" /* event_manager_t, event_t */
#include "function_prototypes.h" /* print_menu_login(), print_menu_main(), scan_int() */

#define DEBUG

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
                    menu_main(event_manager);
                    break;
                case 2:
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
    print_menu_main(event_manager->current_logged_in_user->username);
    int user_selection = scan_int();
    switch(user_selection)
    {
        case 1:
            #ifdef DEBUG /* For debugging */
                printf("Add Event Selected\n");
            #endif
            create_event(event_manager, event_manager->current_logged_in_user);
            break;
        case 2:
            #ifdef DEBUG /* For debugging */
                printf("Edit Event Selected\n");
            #endif

            edit_event(event_manager);

            break;
        case 3:
            #ifdef DEBUG /* For debugging */
                printf("Join Event Selected\n");
            #endif

            join_event(event_manager);

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
            list_all(event_manager);
            break;
        case 2:
            list_event_names(*event_manager);
            break;
        case 3:
            printf("Note: Saving the database will overwrite any already "
                   "saved databases\n");
            printf("Would you like to continue?\n");
            printf("> ");
            if(response_yes())
            {
                save_database(event_manager);
            }else
            {
                printf("Exiting save attempt\n");
            }
        case 4:
            printf("Note: Loading a database will erase any data "
                   "already loaded in the database\n");
            printf("Would you like to continue?\n");
            printf("> ");
            if(response_yes())
            {
                load_database(event_manager);
            }else
            {
                printf("Exiting load attempt\n");
            }
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


void menu_edit(event_manager_t* event_manager, int event_num)
{
    event_t* event = (event_t*) list_get(&event_manager->events, event_num)
            ->data;

    print_menu_edit(event->name);
    int user_selection = scan_int();
    switch (user_selection)
    {
        case 1:
            edit_name(event);
            break;
        case 2:
            edit_type(event);
            break;
        case 3:
            edit_location(event);
            break;
        case 4:
            edit_date_time(event);
            break;
        case 5:
            edit_staff(event_manager, event_num);
            break;
        case 6:
            edit_patrons(event_manager, event_num);
            break;
        case 9:
            printf("Exiting edit menu\n\n");
            return;
        default:
            printf("Invalid Input\n");
            break;
    }
    menu_edit(event_manager, event_num);
    return;
}
