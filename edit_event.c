#include <stdio.h> /* printf() */

#include "structs.h" /* event_manager_t, event_t */
#include "function_prototypes.h" /* edit_event, print_edit, edit_name, edit_type, edit_location, edit_date_time,
edit_staff, edit_patrons */

void edit_event(event_manager_t* event_manager)
{
	char event_name;
	int event_num;
	toggle = 1;
	printf("Enter the event name you would like to edit:\n");
	scanf("%s", event_name);
	if (search_event(event_manager, event_name) >= 0)
	{
		event_num = search_event(event_manager, event_name);
		while (toggle == 1)
		{
			switch(print_edit())
			{
				case 1:
					edit_name(event_manager, event_num);
					break;
				case 2:
					edit_type(event_manager, event_num);
					break;
				case 3:
					edit_location(event_manager, event_num);
					break;
				case 4:
					edit_date_time(event_manager, event_num);
					break;
				case 5:
					edit_staff(event_manager, event_num);
					break;
				case 6:
					edit_patrons(event_manager, event_num);
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

void edit_name(event_manager_t* event_manager)
{
	char answer;
	int toggle = 1;
	while (toggle == 1)
	{
		printf("Current Name: %s\n", event_manager->events[event_num].name);
		printf("Would you like to edit this? (Y/N)\n");

		scanf("%c", answer)
		if (answer == 'Y' || answer == 'y')
		{
			printf("Insert Name: ");
      scanf("%s", event_manager->events[event_num].name);
			toggle = 0;
		}
		else if (answer == 'N' || answer == 'n')
		{
      printf("\n");
			toggle = 0;
		}
	}
}

void edit_type(event_manager_t* event_manager)
{
	char answer;
	int toggle = 1;
	while (toggle == 1)
	{
		printf("Current Event Type: %s\n", event_manager->events[event_num].event_type);
		printf("Would you like to edit this? (Y/N)\n");

		scanf("%c", answer);
		if (answer == 'Y' || answer == 'y')
		{
			printf("Insert Event Type: ");
      scanf("%s", event_manager->events[event_num].event_type);
			toggle = 0;
		}
		else if (answer == 'N' || answer == 'n')
		{
      printf("\n");
			toggle = 0;
		}
	}
}

void edit_location(event_manager_t* event_manager)
{
	char answer;
	int toggle = 1;
	while (toggle == 1)
	{
		printf("Current Location: %d %s, %s %s %d\n", event_manager->events[event_num].location.street_num, event_manager->events[event_num].location.street_name, event_manager->events[event_num].location.suburb, event_manager->events[event_num].location.state, event_manager->events[event_num].location.postcode);
		printf("Would you like to edit this? (Y/N)\n");

		scanf("%c", answer)
		if (answer == 'Y' || answer == 'y')
		{
			printf("Insert Location using the same format above: ");
      scanf("%d %s, %s %s %d", &event_manager->events[event_num].location.street_num, event_manager->events[event_num].location.street_name, event_manager->events[event_num].location.suburb, event_manager->events[event_num].location.state, &event_manager->events[event_num].location.postcode);
			toggle = 0;
		}
		else if (answer == 'N' || answer == 'n')
		{
      printf("\n");
			toggle = 0;
		}
	}
}

void edit_date_time(event_manager_t* event_manager);
{
	char answer;
	int toggle = 1;
	while (toggle == 1)
	{
		printf("Current Date and Time: %d/%d/%d %d%d\n", event_manager->events[event_num].event_date.day, event_manager->events[event_num].event_date.month, event_manager->events[event_num].event_date.year, event_manager->events[event_num].event_date.hour, event_manager->events[event_num].event_date.minute);
		printf("Would you like to edit this? (Y/N)\n");

		scanf("%c", answer)
		if (answer == 'Y' || answer == 'y')
		{
			printf("Insert Event Date and Time as formatted above: ");
			scanf("%d/%d/%d %d%d", event_manager->events[event_num].event_date.day, event_manager->events[event_num].event_date.month, event_manager->events[event_num].event_date.year, event_manager->events[event_num].event_date.hour, event_manager->events[event_num].event_date.minute);
			toggle = 0;
		}
		else if (answer == 'N' || answer == 'n')
		{
			printf("\n");
			toggle = 0;
		}
	}
}

void edit_staff(event_manager_t* event_manager)
{

}

void edit_patrons(event_manager_t* event_manager)
{

}

void search_event(event_manager_t* event_manager, char[] event_name)
{
	
}
