#include <stdio.h> /* printf() */
#include <string.h> /* strcmp() */

#include "structs.h" /* event_manager_t, event_t */
#include "function_prototypes.h" /* edit_event, print_edit, edit_name, 
 * edit_type, edit_location, edit_date_time, edit_staff, edit_patrons */

void edit_name(event_t* event)
{
    printf("Current Name: %s\n", event->name);
    printf("Would you like to edit this?\n");
    printf("> ");
    if(response_yes())
    {
        printf("What would you like to name the event?\n");
        printf("> ");
        scanf("%s", event->name);
    }else
    {
        printf("Keeping event name as '%s'\n", event->name);
    }
    return;
}

void edit_type(event_t* event)
{
    printf("Current Event Type: %s\n",
           event->event_type);
    printf("Would you like to edit this?\n");
    printf("> ");
    if (response_yes())
    {
        printf("What type of event would you like to set?\n");
        printf("> ");
        scanf("%s", event->event_type);
    } else
    {
        printf("Keeping event type as '%s'\n", event->event_type);
    }
}

void edit_location(event_t* event)
{
    printf("Current Location: %d %s, %s %s %d\n",
           event->location.street_num,
           event->location.street_name,
           event->location.suburb,
           event->location.state,
           event->location.postcode);
    printf("Would you like to edit this?\n");
    printf("> ");
    if (response_yes())
    {
        printf("Insert Location using the same format above: ");
        scanf("%d %s, %s %s %d",
              &event->location.street_num,
              event->location.street_name,
              event->location.suburb,
              event->location.state,
              &event->location.postcode);
    } else
    {
        printf("Keeping event location as '%d %s, %s %s %d'\n",
               event->location.street_num,
               event->location.street_name,
               event->location.suburb,
               event->location.state,
               event->location.postcode);
    }
}


void edit_date_time(event_t* event)
{
    printf("Current Date and Time: %d/%d/%d %d%d\n",
           event->event_date.day,
           event->event_date.month,
           event->event_date.year,
           event->event_date.hour,
           event->event_date.minute);
    printf("Would you like to edit this?\n");
    printf("> ");
    if (response_yes())
    {
        printf("Insert Event Date and Time as formatted above: ");
        scanf("%d/%d/%d %d%d",
              &event->event_date.day,
              &event->event_date.month,
              &event->event_date.year,
              &event->event_date.hour,
              &event->event_date.minute);
    } else
    {
        printf("\"Keeping event Date and Time as '%d/%d/%d %d%d'\n",
               event->event_date.day,
               event->event_date.month,
               event->event_date.year,
               event->event_date.hour,
               event->event_date.minute);
    }
}

void edit_staff(event_manager_t* event_manager, int event_num)
{
    print_menu_edit_staff();
    int user_selection = scan_int();
    switch (user_selection)
    {
        case 1:
            add_staff((event_t *) list_get(event_manager->events, event_num)->data,
                    event_manager);
            break;
        case 2:
            break;
        case 9:
            printf("Exiting edit menu\n\n");
            return;
        default:
            printf("Invalid Input\n");
            break;
    }
    edit_staff(event_manager, event_num);
}

void edit_patrons(event_manager_t* event_manager, int event_num)
{
    print_menu_edit_patrons();
    int user_selection = scan_int();
    switch (user_selection)
    {
        case 1:
            add_patron((event_t *) list_get(event_manager->events, event_num)->data,
                    event_manager);
            break;
        case 2:
            break;
        case 9:
            printf("Exiting edit menu\n\n");
            return;
        default:
            printf("Invalid Input\n");
            break;
    }
    edit_patrons(event_manager, event_num);
}

void add_patron_to_event(event_t* event, person_t* user)
{
    event->patrons[event->num_patrons] = *user;
    event->num_patrons++;
}

void add_staff_to_event(event_t* event, person_t* user)
{
    event->staff[event->num_staff] = *user;
    event->num_staff++;
}