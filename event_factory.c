#include <stdio.h>
#include <string.h>

#include "definitions.h"
#include "structs.h"
#include "function_prototypes.h"

void get_new_event_name(char* event_name)
{
    printf("Please enter the event name\n");
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
void get_new_event_free_status(int* event_free_status)
{
    char user_response[MAX_RESPONSE_LEN];

    printf("Would you like this event to be free? (yes/no)\n");
    printf(">");

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

void get_new_event_type(char* event_type)
{
    return;
}