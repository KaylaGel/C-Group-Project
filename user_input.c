#include <stdio.h> /* scanf(), printf() */
#include <stdlib.h> /* malloc() */
#include <string.h> /* strlen() */

#include "definitions.h" /* MAX_INT_LEN */
#include "function_prototypes.h" /* valid_int(), convert_int() */

/**************************************************************
 * Function Name: get_user_login
 * Author(s): Ryan
 * Inputs: username - Character Pointer, password - Character Pointer
 * Outputs: Username, Password
 * Description: Helper function for user login.
 *              Gets user input
**************************************************************/

void get_user_login(char* username, char* password)
{
    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);
    return;
}

/**************************************************************
 * Function Name: scan_int
 * Author(s): Ryan
 * Inputs: N/A
 * Outputs: Integer
 * Description: Gets user input for an integer.
 *              Checks whether its a valid int or not and converts it if 
 *              it is, and requests a new number if it isn't
**************************************************************/

int scan_int(void)
{
    char *input = malloc(MAX_INT_LEN + 1);
    scanf("%s", input);
    if (valid_int(input))
    {
        return convert_int(input);
    } else
    {
        printf("Not a valid number\n");
        printf("Please input a valid number: \n");
        printf("> ");
        return scan_int();
    }
}

/**************************************************************
 * Function Name: scan_int_min_max
 * Author(s): Ryan, Tylar
 * Inputs: min_value - Integer, max_value - Integer
 * Outputs: value
 * Description: Gets an integer from the user and validates it based 
 *              on defined criteria
**************************************************************/

int scan_int_min_max(int min_value, int max_value)
{
    int value = scan_int();
    if(value < min_value || value > max_value)
    {
        printf("\n%i is not between %i and %i\n", value, min_value, max_value);
        printf("Please input a valid number between %i and %i\n", min_value,
                max_value);
        printf("> ");
        return scan_int_min_max (min_value, max_value);
    }
    return value;
}

/**************************************************************
 * Function Name: response_yes
 * Author(s): Tylar
 * Inputs: N/A
 * Outputs: Boolean
 * Description: Gets yes/no input and converts it to boolean
**************************************************************/

int response_yes(void)
{
    char user_response[MAX_RESPONSE_LEN];
    scanf("%s", user_response);
    switch(user_response[0])
    {
        /* 'yes' & 'no' is not needed here because in the switch, we are
         * getting the very first character of the users response and only
         * dealing with that (user_response[0]) */
        case 'y':
        case 'Y':
            return 1;
        case 'n':
        case 'N':
            return 0;
        default:
            printf("Invalid input\n");
            printf("Please enter yes/no\n");
            printf("> ");
            break;
    }
    return response_yes();
}

/**************************************************************
 * Function Name: join_event
 * Author(s): Kayla
 * Inputs: event_manager - Struct Pointer
 * Outputs: N/A
 * Description: Adds the currently logged in user to the user requested event
**************************************************************/

void join_event(event_manager_t* event_manager)
{
    int event_num = search_event_join(&event_manager->events);
    if (event_num == -1)
    {
        printf("Not a valid event\n");
        return;
    }

    event_t* event = (event_t*) list_get(&event_manager->events, event_num)
            ->data;

    printf("Are you sure you want to join '%s'?\n", event->name);
    if(response_yes())
    {
        printf("Joining '%s'\n", event->name);

        if(event->patrons.head == NULL)
        {
            event->patrons.head =
                    init_node(event_manager->current_logged_in_user,
                              sizeof(person_t));
        }else
        {
            list_add(&event->patrons,
                     (void*) event_manager->current_logged_in_user,
                     sizeof (person_t));
        }
    }else
    {
        printf("Exiting event join\n");
    }
    return;
}

/**************************************************************
 * Function Name: edit_event
 * Author(s): Kayla
 * Inputs: event_manager - Struct Pointer
 * Outputs: N/A
 * Description: Requests a user input of which event to edit and 
 *              calls the menu_edit function for that event
**************************************************************/

void edit_event(event_manager_t* event_manager)
{
    int event_num = search_event_edit(&event_manager->events);

    if (event_num == -1)
    {
        printf("Not a valid Event\n");
        return;
    }
    event_t* event = (event_t* ) list_get(&event_manager->events, event_num)
            ->data;

    if ( strcmp( event_manager->current_logged_in_user->username,
                 event->coordinator->username) != 0)
    {
        printf("You are not the coordinator for this event\n");
        return;
    }

    menu_edit(event_manager, event_num);
    return;
}

/**************************************************************
 * Function Name: add_patron
 * Author(s): Kayla
 * Inputs: event_manager - Struct Pointer, event - Struct Pointer
 * Outputs: N/A
 * Description: Gets user input of the patron to add and adds them 
 *              to the supplied event
**************************************************************/

void add_patron(event_t* event, event_manager_t* event_manager)
{
    int user_num = search_user_add(&event_manager->users);
    if (user_num == -1)
    {
        printf("Not a valid user\n");
        return;
    }

    person_t* user = (person_t*) list_get(&event_manager->users, user_num)
            ->data;

    printf("Are you sure you want to add '%s'?\n", user->username);
    printf("> ");
    if(response_yes())
    {
        printf("Adding '%s'\n", user->username);
        if(event->patrons.head == NULL)
        {
            event->patrons.head = init_node(user, sizeof(person_t));
        }else
        {
            list_add(&event->patrons, (void*) user, sizeof(person_t));
        }
    }else
    {
        printf("Exiting event join\n");
    }
    return;
}

/**************************************************************
 * Function Name: add_staff
 * Author(s): Kayla
 * Inputs: event_manager - Struct Pointer, event - Struct Pointer
 * Outputs: N/A
 * Description: Gets user input of the staff to add and adds them to 
 *              the supplied event
**************************************************************/

void add_staff(event_t* event, event_manager_t* event_manager)
{
    int user_num = search_user_add(&event_manager->users);
    if (user_num == -1)
    {
        printf("Not a valid user\n");
        return;
    }

    person_t* user = (person_t*) list_get(&event_manager->users, user_num)
            ->data;

    printf("Are you sure you want to add '%s' as a staff?\n", user->username);
    printf("> ");
    if(response_yes())
    {
        printf("Adding '%s'\n", user->username);

        if(event->staff.head == NULL)
        {
            event->staff.head = init_node(user, sizeof(person_t));
        }else
        {
            list_add(&event->staff, (void*) user, sizeof(person_t));
        }
    }else
    {
        printf("Exiting event join\n");
    }
    return;
}

/**************************************************************
 * Function Name: remove_patron
 * Author(s): Kayla
 * Inputs: event_manager - Struct Pointer, event - Struct Pointer
 * Outputs: N/A
 * Description: Gets user input of the patron to remove and removes them 
 *              from the supplied event
**************************************************************/

void remove_patron(event_t* event, event_manager_t* event_manager)
{
    int user_num = search_user_remove(&event->patrons);
    if (user_num == -1)
    {
        printf("Not a valid user\n");
        return;
    }

    person_t* user = (person_t*) list_get(&event->patrons, user_num)->data;

    printf("Are you sure you want to remove '%s'?\n", user->username);
    printf("> ");
    if(response_yes())
    {
        printf("Adding '%s'\n", user->username);
        list_remove(&event->patrons, list_get(&event->patrons, user_num));

    }else
    {
        printf("Exiting event join\n");
    }
    return;
}

/**************************************************************
 * Function Name: remove_staff
 * Author(s): Kayla
 * Inputs: event_manager - Struct Pointer, event - Struct Pointer
 * Outputs: N/A
 * Description: Gets user input of the staff to remove and removes 
 *              them from the supplied event
**************************************************************/

void remove_staff(event_t* event, event_manager_t* event_manager)
{
    int user_num = search_user_remove(&event->staff);
    if (user_num == -1)
    {
        printf("Not a valid user\n");
        return;
    }

    person_t* user = (person_t*) list_get(&event->staff, user_num)->data;

    printf("Are you sure you want to remove '%s' from the staff?\n",
            user->username);
    printf("> ");
    if(response_yes())
    {
        printf("Removing '%s'\n", user->username);
        list_remove(&event->staff, list_get(&event->staff, user_num));

    }else
    {
        printf("Exiting event join\n");
    }
    return;
}