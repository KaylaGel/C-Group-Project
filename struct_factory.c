#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "structs.h" /* event_manager_t, event_t */
#include "function_prototypes.h" /* init_admin_account() */

/**************************************************************
 * Function Name: 
 * Author(s):
 * Inputs:
 * Outputs: 
 * Description: 
**************************************************************/

void init_event_manager(event_manager_t* event_manager)
{
    init_admin_account(&event_manager->admin_account);

    event_manager->users.head = NULL;
    event_manager->events.head = NULL;
    return;
}

/**************************************************************
 * Function Name: 
 * Author(s):
 * Inputs:
 * Outputs: 
 * Description: 
**************************************************************/

void init_event(event_t* event, person_t* coordinator)
{
    event->patrons.head = NULL;
    event->staff.head = NULL;
    get_new_event_name(event->name);
    get_new_event_free_status(&event->free_event);
    get_new_event_type(event->event_type);
    get_new_event_location(&event->location);
    get_new_event_date(&event->event_date);

    event->coordinator = coordinator;

    return;
}

/**************************************************************
 * Function Name: 
 * Author(s):
 * Inputs:
 * Outputs: 
 * Description: 
**************************************************************/

void init_admin_account(person_t* admin)
{
    strcpy(admin->username, "Admin");
    strcpy(admin->password, "Password");
    strcpy(admin->firstname, "Admin");
    strcpy(admin->lastname, "Account");
    admin->DOB.day = MIN_DAY;
    admin->DOB.month = MIN_MONTH;
    admin->DOB.year = MIN_YEAR;
}

/**************************************************************
 * Function Name: 
 * Author(s):
 * Inputs:
 * Outputs: 
 * Description: 
**************************************************************/

void create_event(event_manager_t* event_manager, person_t* creator)
{
    if(event_manager->runtime_mode == MODE_DEBUG)
    {
        printf("DEBUG: Creating event\n");
    }
    /* Create an event struct */
    event_t* event = malloc(sizeof(event_t));
    /* Initialise the event structs values */
    init_event(event, creator);
    if(event_manager->events.head == NULL)
    {
        event_manager->events.head = init_node(event, sizeof(event_t));
    }else
    {
        list_add(&event_manager->events, (void*) event, sizeof(event_t));
    }
    return;
}