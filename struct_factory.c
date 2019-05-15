#include "structs.h" /* event_manager_t, event_t */

void init_event_manager(event_manager_t* event_manager)
{
    event_manager->num_events = 0;
    return;
}

void init_event(event_t* event, person_t coordinator)
{
    /* TODO: get user input to assign the event name */
    event->num_patrons = 0;
    event->num_staff = 0;
    event->free_event = 0; /* TODO: get user input to ask the coordinator whether the event is free or not */

    event->coordinator.staff.id = 0; /* Why does the coordinator need an id? */
    event->coordinator.staff.personal = coordinator;

    return;
}

void init_staff(event_t* event, staff_t staff)
{
    /* Set the staff id to how many staff there were before them
     * ie; the first staff will have id:0, second will have id:1
     * fifteenth will have id:14, etc...*/
    staff.id = event->num_staff;
    /* Set the next available staff array spot to the provided staff struct */
    event->staff[event->num_staff] = staff;
    /* Increment the staff counter */
    event->num_staff++;
    return;
}


void create_event(event_manager_t* event_manager, person_t creator)
{

    /* Create an event struct */
    event_t event;
    /* Initialise the event structs values */
    init_event(&event, creator);

    /* Assign the created event to the next free array index
     * ie; there are 2 events that already exist, so access event array
     * index 2, or the 3rd event struct */
    event_manager->events[event_manager->num_events] = event;

    /* Increment event counter */
    event_manager->num_events++;

    return;
}