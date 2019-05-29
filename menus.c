#include <stdio.h> /* printf() */
#include <string.h>

#include "structs.h" /* event_manager_t, event_t */
#include "function_prototypes.h" /* print_menu_login(), print_menu_main(), scan_int() */

/**************************************************************
 * Function Name: menu_login
 * Author(s): Ryan
 * Inputs: event_manager - Struct Pointer
 * Outputs: N/A
 * Description: Prints the login menu and then gets the user input to determine 
 *              the following function. It will then recursively call itself 
 *              until the exit option is selected.
**************************************************************/

void menu_login(event_manager_t* event_manager)
{
    if(event_manager->runtime_mode == MODE_DEBUG)
    {
        printf("DEBUG: Login Menu\n");
    }
    print_menu_login();
    int user_selection = scan_int();
    switch(user_selection)
    {
        case 1:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Login Selected\n");
            }
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
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Create Account Selected\n");
            }
            account_creation(event_manager);
            break;



        case 9:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Exit Selected\n");
            }
            printf("Exiting program\n");
            return;
        default:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Invalid option '%i' selected\n", user_selection);
            }
            printf("Not a valid entry\n");
            break;
    }
    menu_login(event_manager);
    return;
}

/**************************************************************
 * Function Name: main_menu
 * Author(s): Ryan
 * Inputs: event_manager - Struct Pointer
 * Outputs: N/A
 * Description: Prints the main menu and then gets the user input to determine 
 *              the following function. It will then recursively call itself 
 *              until the exit option is selected.
**************************************************************/

void menu_main(event_manager_t* event_manager)
{
    if(event_manager->runtime_mode == MODE_DEBUG)
    {
        printf("DEBUG: Main Menu\n");
    }
    print_menu_main(event_manager->current_logged_in_user->username);
    int user_selection = scan_int();
    switch(user_selection)
    {
        case 1:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Add Event Selected\n");
            }
            create_event(event_manager, event_manager->current_logged_in_user);
            break;
        case 2:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Edit Event Selected\n");
            }

            edit_event(event_manager);

            break;
        case 3:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Join Event Selected\n");
            }

            join_event(event_manager);

            break;
        case 9:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Logout Selected\n");
            }
            printf("Logging out\n\n");
            return;
        default:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Invalid option '%i' selected\n", user_selection);
            }
            printf("Not a valid entry\n");
            break;
    }
    menu_main(event_manager);
    return;
}

/**************************************************************
 * Function Name: menu_admin
 * Author(s): Tylar
 * Inputs: event_manager - Struct Pointer
 * Outputs: N/A
 * Description: Prints the admin menu and then gets the user input to determine 
 *              the following function. It will then recursively call itself 
 *              until the exit option is selected.
**************************************************************/

void menu_admin(event_manager_t* event_manager)
{
    if(event_manager->runtime_mode == MODE_DEBUG)
    {
        printf("DEBUG: Admin Menu\n");
    }
    print_menu_admin();
    int user_selection = scan_int();
    switch(user_selection)
    {
        case 1:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: List All selected\n");
            }
            list_all(event_manager);
            break;
        case 2:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: List events selected\n");
            }
            list_events(event_manager);
            break;
        case 3:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: List events detailed selected\n");
            }
            list_events_detail(event_manager);
            break;
        case 4:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: List users detailed selected\n");
            }
            list_users_detail(event_manager);
            break;
        case 7:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Save Database selected\n");
            }
            printf("Note: Saving the database will overwrite any already "
                   "saved databases\n");
            printf("Would you like to continue?\n");
            printf("> ");
            if(response_yes())
            {
                if(event_manager->runtime_mode == MODE_DEBUG)
                {
                    printf("DEBUG: User response yes\n");
                }
                save_database(event_manager);
            }else
            {
                if(event_manager->runtime_mode == MODE_DEBUG)
                {
                    printf("DEBUG: User response no\n");
                }
                printf("Exiting save attempt\n");
            }
            break;
        case 8:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Loading Database\n");
            }
            printf("Note: Loading a database will erase any data "
                   "already loaded in the database\n");
            printf("Would you like to continue?\n");
            printf("> ");
            if(response_yes())
            {
                if(event_manager->runtime_mode == MODE_DEBUG)
                {
                    printf("DEBUG: User response yes\n");
                }
                load_database(event_manager);
            }else
            {
                if(event_manager->runtime_mode == MODE_DEBUG)
                {
                    printf("DEBUG: User response no\n");
                }
                printf("Exiting load attempt\n");
            }
            break;
        case 9:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Log out selected\n");
            }
            printf("Logging out\n\n");
            return;
        default:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Invalid response '%i'\n", user_selection);
            }
            printf("Not a valid entry\n");
            break;
    }
    menu_admin(event_manager);
    return;
}

/**************************************************************
 * Function Name: menu_edit
 * Author(s): Tylar
 * Inputs: event_manager - Struct Pointer, event_num - Integer
 * Outputs: N/A
 * Description: Prints the edit menu and then gets the user input to determine 
 *              the following function. It will then recursively call itself 
 *              until the exit option is selected.
**************************************************************/

void menu_edit(event_manager_t* event_manager, int event_num)
{
    if(event_manager->runtime_mode == MODE_DEBUG)
    {
        printf("DEBUG: Edit Menu\n");
    }
    event_t* event = (event_t*) list_get(&event_manager->events, event_num)
            ->data;

    print_menu_edit(event->name);
    int user_selection = scan_int();
    switch (user_selection)
    {
        case 1:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Edit Name Chosen\n");
            }
            edit_name(event);
            break;
        case 2:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Edit Type Chosen\n");
            }
            edit_type(event);
            break;
        case 3:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Edit Location Chosen\n");
            }
            edit_location(event);
            break;
        case 4:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Edit Date Time Chosen\n");
            }
            edit_date_time(event);
            break;
        case 5:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Edit Staff Chosen\n");
            }
            edit_staff(event_manager, event_num);
            break;
        case 6:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Edit Patrons Chosen\n");
            }
            edit_patrons(event_manager, event_num);
            break;
        case 9:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Exit Chosen\n");
            }
            printf("Exiting edit menu\n");
            return;
        default:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Invalid response '%i'\n", user_selection);
            }
            printf("Invalid Input\n");
            break;
    }
    menu_edit(event_manager, event_num);
    return;
}
