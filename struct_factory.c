#include "structs.h" /* event_manager_t, event_t */

#include <stdio.h>

void init_event_manager(event_manager_t* event_manager)
{
    event_manager->num_events = 0;
    return;
}

void init_event(event_t* event, person_t coordinator)
{
    event->num_patrons = 0;
    event->num_staff = 0;

    event->coordinator.staff.id = 0; /* Why does the coordinator need an id? */
    event->coordinator.staff.personal = coordinator;

    return;
}


void create_event(event_manager_t* event_manager, person_t creator)
{
    /* Create an event struct */
    event_t event;
    /* Initialise the event structs values */
    init_event(&event, &creator);

    /* Assign the created event to the next free array index
     * ie; there are 2 events that already exist, so access event array
     * index 2, or the 3rd event struct */
    event_manager->events[event_manager->num_events] = event;

    /* Increment event counter */
    event_manager->num_events++;

    return;
}