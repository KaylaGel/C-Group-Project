#include <stdio.h> /* scanf(), printf() */
#include <stdlib.h> /* malloc() */
#include <string.h> /* strlen() */

#include "definitions.h" /* MAX_INT_LEN */
#include "function_prototypes.h" /* valid_int(), convert_int() */

#define DEBUG

void get_user_login(char* username, char* password)
{
    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);
    return;
}

void get_event_login(int* event_id, char* event_password)
{
    printf("Event ID: ");
    scanf("%i", event_id);

    printf("Password: ");
    scanf("%s", event_password);
    return;
}


int scan_int(void)
{
    char* input = malloc(MAX_INT_LEN + 1);
    while(1)
    {
        /* TODO: account for spaces in user input */
        scanf("%s", input);
        if( valid_int(input) )
        {
            return convert_int(input);
        }else
        {
            printf("Not a valid number\n");
            printf("Please input a valid number: \n");
            printf("> ");
            return scan_int();
        }
    }
}

int scan_int_min_max(int min_value, int max_value)
{
    int value = scan_int();
    if(value < min_value || value > max_value)
    {
        printf("\n%i is not between %i and %i\n", value, min_value, max_value);
        printf("Please input a valid number between %i and %i\n", min_value,
                max_value);
        printf("> ");
        return scan_int_min_max (min_value, max_value);
    }
    return value;
}

int response_yes(void)
{
    char user_response[MAX_RESPONSE_LEN];
    scanf("%s", user_response);
    switch(user_response[0])
    {
        case 'y':
        case 'Y':
            return 1;
        case 'n':
        case 'N':
            return 0;
        default:
            printf("Invalid input\n");
            printf("Please enter yes/no\n");
            printf("> ");
            break;
    }
    return response_yes();
}


