#include <stdio.h> /* printf() */
#include <string.h> /* strcmp() */

#include "structs.h" /* event_manager_t, event_t */
#include "linked_list.h" /* list_get */
#include "function_prototypes.h" /* response_yes, print_menu_edit_staff, 
add_staff, remove_staff, edit_staff, scan_int, add_patron, remove_patron, 
edit_patrons, print_menu_edit_patrons*/


/**************************************************************
 * Function Name: edit_name
 * Author(s): Jacob
 * Inputs: event - Pointer
 * Outputs: N/A
 * Description: Requests if the user would like to change the name and 
 *              if given consent then it will change the event name to the
 *              name that the user supplies
**************************************************************/
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

/**************************************************************
 * Function Name: edit_type
 * Author(s): Jacob
 * Inputs: event - Pointer
 * Outputs: N/A
 * Description: Requests if the user would like to change the event type and 
 *              if given consent then it will change the event type to the
 *              type that the user supplies
**************************************************************/
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
    return;
}

/**************************************************************
 * Function Name: 
 * Author(s): Kayla
 * Inputs: event - Pointer
 * Outputs: N/A
 * Description: Requests if the user would like to change the event location 
 *              and if given consent then it will change the event location 
 *              to the location that the user supplies
**************************************************************/
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
    return;
}

/**************************************************************
 * Function Name: 
 * Author(s): Kayla
 * Inputs: event - Pointer
 * Outputs: N/A
 * Description: Requests if the user would like to change the event time and
 *              if given consent then it will change the event time to the
 *              time that the user supplies
**************************************************************/

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
        printf("\"Keeping event Date and Time as '%d/%d/%d %d:%d'\n",
               event->event_date.day,
               event->event_date.month,
               event->event_date.year,
               event->event_date.hour,
               event->event_date.minute);
    }
    return;
}

/**************************************************************
 * Function Name: 
 * Author(s): Dee-Jay, Tylar
 * Inputs: event_manager(pointer), event_num
 * Outputs: N/A
 * Description: The function asks whether the user would like to add or
 *              remove staff and will call the respective functions.
**************************************************************/

void edit_staff(event_manager_t* event_manager, int event_num)
{
    print_menu_edit_staff();
    int user_selection = scan_int();
    switch (user_selection)
    {
        case 1:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: 'Add Staff' chosen\n");
            }
            add_staff((event_t *) list_get(&event_manager->events,
                    event_num)->data, event_manager);
            break;
        case 2:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: 'Remoce Staff' chosen\n");
            }
            remove_staff((event_t *) list_get(&event_manager->events,
                    event_num)->data, event_manager);
            break;
        case 9:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: 'Exit' chosen\n");
            }
            printf("Exiting edit menu\n\n");
            return;
        default:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Invalid input '%i' chosen\n", user_selection);
            }
            printf("Invalid Input\n");
            break;
    }
    edit_staff(event_manager, event_num);
}

/**************************************************************
 * Function Name: 
 * Author(s): Dee-Jay, Tylar
 * Inputs: event_manager(pointer), event_num
 * Outputs: N/A
 * Description: The function asks whether the user would like to add or
 *              remove patrons and will call the respective functions.
**************************************************************/

void edit_patrons(event_manager_t* event_manager, int event_num)
{
    print_menu_edit_patrons();
    int user_selection = scan_int();
    switch (user_selection)
    {
        case 1:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: 'Add Patron' chosen\n");
            }
            add_patron((event_t *) list_get(&event_manager->events,
                    event_num)->data, event_manager);
            break;
        case 2:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: 'Remove Patron' chosen\n");
            }
            remove_patron((event_t *) list_get(&event_manager->events,
                    event_num)->data, event_manager);
            break;
        case 9:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: 'Exit Menu' chosen\n");
            }
            printf("Exiting edit menu\n\n");
            return;
        default:
            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Invalid input '%i' chosen\n", user_selection);
            }
            printf("Invalid Input\n");
            break;
    }
    edit_patrons(event_manager, event_num);
}