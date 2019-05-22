#include <stdio.h> /* printf() */
#include <string.h>

#include "structs.h" /* event_manager_t, event_t */
#include "function_prototypes.h" /* print_menu_login(), print_menu_main(), scan_int() */

void menu_login(event_manager_t* event_manager)
{
    print_menu_login();
    int user_selection = scan_int();
    switch(user_selection)
    {
        case 1:
            #ifdef DEBUG /* For debugging */
                printf("Login Selected\n");
            #endif
            switch(login(event_manager))
            {
                case 1:
                    menu_main(event_manager);
                    break;
                case 2:
                    menu_admin(event_manager);
                    break;
            }
            break;
        case 2:
            #ifdef DEBUG /* For debugging */
                printf("Create Account Selected\n");
            #endif
            account_creation(event_manager);
            break;



        case 9:
            #ifdef DEBUG /* For debugging */
                printf("Exit Selected\n");
            #endif
            printf("Exiting program\n");
            return;
        default:
            printf("Not a valid entry\n");
            break;
    }
    menu_login(event_manager);
    return;
}

void menu_main(event_manager_t* event_manager)
{
    print_menu_main(event_manager->current_logged_in_user.username);
    int user_selection = scan_int();
    switch(user_selection)
    {
        case 1:
            #ifdef DEBUG /* For debugging */
                printf("Add Event Selected\n");
            #endif
            create_event(event_manager, event_manager->current_logged_in_user);
            break;
        case 2:
            #ifdef DEBUG /* For debugging */
                printf("Edit Event Selected\n");
            #endif

            break;
        case 3:
            #ifdef DEBUG /* For debugging */
                printf("Join Event Selected\n");
            #endif

            break;



        case 9:
            #ifdef DEBUG /* For debugging */
                printf("Logout Selected\n");
            #endif
            printf("Logging out\n\n");
            return;
        default:
            printf("Not a valid entry\n");
            break;
    }
    menu_main(event_manager);
    return;
}

void menu_admin(event_manager_t* event_manager)
{
    print_menu_admin();
    int user_selection = scan_int();
    switch(user_selection)
    {
        case 1:
            list_all(*event_manager);
            break;
        case 2:
            list_event_names(*event_manager);
            break;
        case 9:
            printf("Logging out\n\n");
            return;
        default:
            printf("Not a valid entry\n");
            break;
    }
    menu_admin(event_manager);
    return;
}


void print_menu_login(void)
{
    printf("\nLogin Menu\n\n");
    printf("Please select an option from the following list\n");
    printf("1. Login\n");
    printf("2. Create Account\n");
    printf("9. Exit\n");
    printf("> ");
    return;
}

void print_menu_main(char* current_logged_in_username)
{
    printf("\nMain Menu\n\n");
    printf("Currently logged in as '%s'\n", current_logged_in_username);
    printf("Please select an option from the following list\n");
    printf("1. Add Event\n");
    printf("2. Edit Event\n");
    printf("3. Join Event\n");
    printf("9. Logout\n");
    printf("> ");
    return;
}

void print_menu_admin(void)
{
    printf("\nAdmin Menu\n\n");
    printf("1. List All\n");
    printf("2. List Events\n");
    printf("9. Logout\n");
    printf(">");
}


void list_event_names(event_manager_t event_manager)
{
    if(event_manager.num_events == 0)
    {
        printf("No events\n");
        return;
    }

    int i;
    for (i = 0; i < event_manager.num_events; i++)
    {
        event_t event = event_manager.events[i];
        print_event_name(event, i + 1);
    }
    return;
}

void list_all(event_manager_t event_manager)
{
    printf("Events\n\n");
    int i;
    for (i = 0; i < event_manager.num_events; i++)
    {
        event_t event = event_manager.events[i];
        print_event_details(event, i + 1);
    }

    /*TODO*/
    return;
}

/*******************************************************
 * Editing the Event
*******************************************************/

void edit_event(event_t events, int event_count)
{
	char event_name;
	int event_num;
    int toggle;

	toggle = 1;
	printf("Enter the event name you would like to edit:\n");
	scanf("%s", event_name);
	if (search_event(events, event_count, event_name) >= 0)
	{
		event_num = search_event(events, event_count, event_name);
		while (toggle == 1)
		{
			switch(print_edit())
            {
				case 1:
					edit_name(events, event_num);
					break;
				case 2:
					edit_type(events, event_num);
					break;
				case 3:
					edit_location(events, event_num);
					break;
				case 4:
					edit_date_time(events, event_num);
					break;
				case 5:
					edit_staff(events, event_num);
					break;
				case 6:
					edit_patrons(events, event_num);
					break;
				case 7:
					toggle = 0;
					break;
				default:
					printf("Invalid Input\n");
            }
		}
	}
	else
	{
		printf("Invalid Event");
	}
}



int print_edit(void)
{
	int edit_num;
	printf("Which aspect of the event would you like to edit\n");
	printf("\n"
	"--------------------\n"
	"1 - Event Name\n"
	"2 - Event Type\n"
	"3 - Event Location\n"
	"4 - Event Time\n"
	"5 - Event Staff\n"
	"6 - Event Patrons\n"
	"7 - Exit\n"
	"--------------------\n");
	scanf("%d", edit_num);
	return edit_num;
}

void edit_name(event_t events, int event_num)
{
	char answer;
	int toggle = 1;
	while (toggle == 1)
	{
		printf("Current Name: %s\n", events[event_num].name);
		printf("Would you like to edit this? (Y/N)\n");

		scanf("%c", answer)
		if (answer == 'Y' || answer == 'y')
		{
			printf("Insert Name: ");
      scanf("%s", events[event_num].name);
			toggle = 0;
		}
		else if (answer == 'N' || answer == 'n')
		{
      printf("\n");
			toggle = 0;
		}
	}
}

void edit_type(event_t events, int event_num)
{
	char answer;
	int toggle = 1;
	while (toggle == 1)
	{
		printf("Current Event Type: %s\n", events[event_num].event_type);
		printf("Would you like to edit this? (Y/N)\n");

		scanf("%c", answer)
		if (answer == 'Y' || answer == 'y')
		{
			printf("Insert Event Type: ");
      scanf("%s", events[event_num].event_type);
			toggle = 0;
		}
		else if (answer == 'N' || answer == 'n')
		{
      printf("\n");
			toggle = 0;
		}
	}
}

void edit_location(event_t events, int event_num)
{
	char answer;
	int toggle = 1;
	while (toggle == 1)
	{
		printf("Current Location: %d %s, %s %s %d\n", events[event_num].location.street_num, events[event_num].location.street_name, events[event_num].location.suburb, events[event_num].location.state, events[event_num].location.postcode);
		printf("Would you like to edit this? (Y/N)\n");

		scanf("%c", answer)
		if (answer == 'Y' || answer == 'y')
		{
			printf("Insert Location using the same format above: ");
      scanf("%d %s, %s %s %d", &events[event_num].location.street_num, events[event_num].location.street_name, events[event_num].location.suburb, events[event_num].location.state, &events[event_num].location.postcode);
			toggle = 0;
		}
		else if (answer == 'N' || answer == 'n')
		{
      printf("\n");
			toggle = 0;
		}
	}
}

void edit_date_time(event_t events, int event_num);
{
	char answer;
	int toggle = 1;
	while (toggle == 1)
	{
		printf("Current Date and Time: %d/%d/%d %d%d\n", events[event_num].event_date.day, events[event_num].event_date.month, events[event_num].event_date.year, events[event_num].event_date.hour, events[event_num].event_date.minute);
		printf("Would you like to edit this? (Y/N)\n");

		scanf("%c", answer)
		if (answer == 'Y' || answer == 'y')
		{
			printf("Insert Event Date and Time as formatted above: ");
			scanf("%d/%d/%d %d%d", events[event_num].event_date.day, events[event_num].event_date.month, events[event_num].event_date.year, events[event_num].event_date.hour, events[event_num].event_date.minute);
			toggle = 0;
		}
		else if (answer == 'N' || answer == 'n')
		{
			printf("\n");
			toggle = 0;
		}
	}
}

void edit_staff(event_t events, int event_num)
{

}

void edit_patrons(event_t events, int event_num)
{

}
