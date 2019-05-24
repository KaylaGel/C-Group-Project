#include <stdio.h> /* scanf(), printf() */
#include <stdlib.h> /* malloc() */
#include <string.h> /* strlen() */

#include "definitions.h" /* MAX_INT_LEN */
#include "function_prototypes.h" /* valid_int(), convert_int() */

#define DEBUG

void get_user_login(char* username, char* password)
{
    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);
    return;
}

void get_event_login(int* event_id, char* event_password)
{
    printf("Event ID: ");
    scanf("%i", event_id);

    printf("Password: ");
    scanf("%s", event_password);
    return;
}


int scan_int(void)
{
    char* input = malloc(MAX_INT_LEN + 1);
    while(1)
    {
        /* TODO: account for spaces in user input */
        scanf("%s", input);
        if( valid_int(input) )
        {
            return convert_int(input);
        }else
        {
            printf("Not a valid number\n");
            printf("Please input a valid number: \n");
            printf("> ");
            return scan_int();
        }
    }
}

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

int response_yes(void)
{
    char user_response[MAX_RESPONSE_LEN];
    scanf("%s", user_response);
    switch(user_response[0])
    {
        case 'y':
        case 'Y':
        case 'Yes':
        case 'yes':
            return 1;
        case 'n':
        case 'N':
        case 'No':
        case 'no':
            return 0;
        default:
            printf("Invalid input\n");
            printf("Please enter yes/no\n");
            printf("> ");
            break;
    }
    return response_yes();
}

void join_event(event_manager_t* event_manager)
{
    int event_num = search_event_join(event_manager);
    if (event_num == -1)
    {
        printf("Not a valid event\n");
        return;
    }

    event_t* event = &event_manager->events[event_num];

    printf("Are you sure you want to join '%s'?\n", event->name);
    if(response_yes())
    {
        printf("Joining '%s'\n", event->name);
        add_patron_to_event(event, &event_manager->current_logged_in_user);
    }else
    {
        printf("Exiting event join\n");
    }
    return;
}

void edit_event(event_manager_t* event_manager)
{
    int event_num = search_event_edit(event_manager);

    if (event_num == -1)
    {
        printf("Not a valid Event\n");
        return;
    }

    menu_edit(event_manager, event_num);
    return;
}

void add_patron(event_t* event, event_manager_t* event_manager)
{
    int user_num = search_user_add(event_manager);
    if (user_num == -1)
    {
        printf("Not a valid user\n");
        return;
    }

    person_t* user = &event_manager->users[user_num];

    printf("Are you sure you want to add '%s'?\n", user->username);
    if(response_yes())
    {
        printf("Adding '%s'\n", user->username);
        add_patron_to_event(event, user);
    }else
    {
        printf("Exiting event join\n");
    }
    return;
}

void add_staff(event_t* event, event_manager_t* event_manager)
{
    int user_num = search_user_add(event_manager);
    if (user_num == -1)
    {
        printf("Not a valid user\n");
        return;
    }

    person_t* user = &event_manager->users[user_num];

    printf("Are you sure you want to add '%s' as a staff?\n", user->username);
    if(response_yes())
    {
        printf("Adding '%s'\n", user->username);
        add_staff_to_event(event, user);
    }else
    {
        printf("Exiting event join\n");
    }
    return;
}