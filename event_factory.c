#include <stdio.h> /* printf, scanf */
#include <string.h> /* strlen */

#include "definitions.h" /* MAX_NAME_LEN, MAX_RESPONSE_LEN */
#include "structs.h" /* date_t, address_t */
#include "function_prototypes.h" /* get_new_event_name,
                                    get_new_event_free_status,
                                    get_new_event_type, scan_int_min_max */

/**************************************************************
 * Function Name: get_new_event_name
 * Author(s): Jacob
 * Inputs: event_name - String Pointer
 * Outputs: event_name string
 * Description: Scans the user input and checks if its within the criteria
**************************************************************/
void get_new_event_name(char* event_name)
{
    printf("\nPlease enter the event name\n");
    printf(">");

    scanf("%s", event_name);

    if(strlen(event_name) > MAX_NAME_LEN)
    {
        printf("Event name should be less than %i characters long\n",
               MAX_NAME_LEN);
        printf("Your inputted name was %i characters long\n",
               (int) strlen(event_name));
        get_new_event_name(event_name);
        return;
    }
    return;
}

/**************************************************************
 * Function Name: get_new_event_free_status
 * Author(s): Jacob
 * Inputs: event_free_status - Integer Pointer
 * Outputs: event_free_status Integer
 * Description: Scans the user input and checks if its within the criteria
**************************************************************/
void get_new_event_free_status(int* event_free_status)
{
    char user_response[MAX_RESPONSE_LEN];

    printf("Would you like this event to be free? (yes/no)\n");
    printf("> ");

    scanf("%s", user_response);

    switch(user_response[0])
    {
        case 'y':
        case 'Y':
            printf("Event will be set to free entry\n");
            *event_free_status = 1;
            break;
        case 'n':
        case 'N':
            printf("Event will be set to paid entry\n");
            *event_free_status = 0;
            break;
        default:
            printf("Invalid input\n");
            printf("Please enter yes/no\n");
            get_new_event_free_status(event_free_status);
            break;
    }

    return;
}

/**************************************************************
 * Function Name: get_new_event_type
 * Author(s): Jacob
 * Inputs: event_type - String Pointer
 * Outputs: event_type String
 * Description: Scans the user input and checks if its within the criteria
**************************************************************/

void get_new_event_type(char* event_type)
{
    printf("What type of event is it?\n");
    printf("> ");

    scanf("%s", event_type);

    if(strlen(event_type) > MAX_NAME_LEN)
    {
        printf("Event type should be less than %i characters long\n",
               MAX_NAME_LEN);
        printf("Your inputted type was %i characters long\n",
               (int) strlen(event_type));
        get_new_event_type(event_type);
        return;
    }
    return;
}

/**************************************************************
 * Function Name: get_new_event_location
 * Author(s): Jacob
 * Inputs: address - Struct Pointer
 * Outputs: address struct
 * Description: Scans the user input and checks if its within the criteria
**************************************************************/

void get_new_event_location(address_t* address)
{
    printf("Where is the event going to be located?\n");

    printf("State> ");
    scanf("%s", address->state);

    printf("Postcode> ");
    address->postcode = scan_int();

    printf("Suburb> ");
    scanf("%s", address->suburb);

    printf("Street Name> ");
    scanf("%s", address->street_name);

    printf("Street Number> ");
    address->street_num = scan_int();
    return;
}

/**************************************************************
 * Function Name: get_new_event_date
 * Author(s): Jacob
 * Inputs: date - Struct Pointer
 * Outputs: data struct
 * Description: Scans the user input and checks if its within the criteria
**************************************************************/

void get_new_event_date(date_t* date)
{
    printf("When is the event going to be?\n");

    printf("Year> ");
    date->year = scan_int_min_max(MIN_YEAR, MAX_YEAR);

    printf("Month> ");
    date->month = scan_int_min_max(MIN_MONTH, MAX_MONTH);

    printf("Day> ");
    date->day = scan_int_min_max(MIN_DAY, MAX_DAY);

    printf("Hour> ");
    date->hour = scan_int_min_max(MIN_HOUR, MAX_HOUR);

    printf("Minute> ");
    date->minute = scan_int_min_max(MIN_MINUTE, MAX_MINUTE);

    return;
}