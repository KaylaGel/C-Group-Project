#include "structs.h" /* event_manager_t, event_t */

void init_event_manager(event_manager_t* event_manager)
{
    event_manager->num_events = 0;
    return;
}

void init_event(event_t* event)
{
    event->num_patrons = 0;
    event->num_staff = 0;
    return;
}