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

        list_add(&event->patrons,
                (void*) event_manager->current_logged_in_user,
                 sizeof (person_t));
    }else
    {
        printf("Exiting event join\n");
    }
    return;
}

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