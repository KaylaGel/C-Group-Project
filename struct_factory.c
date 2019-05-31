#include <stdlib.h> /* malloc */
#include <stdio.h> /* printf */
#include <string.h> /* strcmp() */

#include "structs.h" /* event_manager_t, event_t, person_t */
#include "definitions.h" /* MIN_DAY, MIN_MONTH, MIN_YEAR */
#include "linked_list.h" /* init_node, list_add */
#include "function_prototypes.h" /* init_admin_account, get_new_event_name
get_new_event_free_status, get_new_event_type, get_new_event_location, get_new_event_date
init_event */


/**************************************************************
 * Function Name: init_event_manager
 * Author(s): Ryan
 * Inputs: event_manager - Struct Pointer
 * Outputs: initialised event_manager
 * Description: Initiallises the variables of the event_manager
**************************************************************/

void init_event_manager(event_manager_t* event_manager)
{
    init_admin_account(&event_manager->admin_account);

    event_manager->users.head = NULL;
    event_manager->events.head = NULL;
    return;
}

/**************************************************************
 * Function Name: init_event
 * Author(s): Ryan
 * Inputs: event - Struct Pointer, coordinator - Struct Pointer
 * Outputs: initialised events
 * Description: Initiallises the variables of the event
 *              Calls various helper functions to get user input for the values
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
 * Function Name: init_admin_account
 * Author(s): Ryan
 * Inputs: admin - Struct Pointer
 * Outputs: initialised admin
 * Description: Initiallises the variables of the admin account
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
 * Function Name: create_event
 * Author(s): Ryan
 * Inputs: event_manager - Struct Pointer, creator - Struct Pointer
 * Outputs: initialised event
 * Description: Creates a new event pointer and allocates memory for it.
 *              Calls the initialisation function for the event.
 *              Then either adds the event to the event linked list or 
 *              creates a new events linked list depending on whether it 
 *              exists or not
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