#include <stdio.h>

#include "structs.h" /* event_t, person_t */
#include "function_prototypes.h" /* get_new_user_* */

void create_new_user(event_manager_t event_manager, person_t *user)
{
    get_new_user_username(event_manager, user->username);
    get_new_user_password(user->password);
    get_new_user_firstname(user->firstname);
    get_new_user_lastname(user->lastname);
     
    return;
    /* Test line here */
}

void account_creation(event_manager_t* event_manager)
{
    person_t user;
    create_new_user(*event_manager, &user);

    if(event_manager->num_events != 0)
    {
        /*heeelllllooooo*/
        printf("Please select the event you would like to join\n");
        list_event_names(*event_manager);
        int user_selection = scan_int_min_max(0, event_manager->num_events);
        /* TODO: continue this chain, get the event_t struct for the user requested event
         * TODO: request if they want to be a staff or patron */
    }else
    {
        printf("There are no events created yet\n");
        printf("Would you like to make one?\n");
        printf("> ");

        char user_response[MAX_RESPONSE_LEN];
        scanf("%s", user_response);
        if(user_response[0] == 'y' || user_response[0] == 'Y')
        {
            /* TODO: Create new event and assign created user as the coordinator */
            create_event(event_manager, user);
        }else
        {
            printf("Exiting account creation\n");
            return;
        }
    }

    return;
}