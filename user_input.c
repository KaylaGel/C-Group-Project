#include <stdio.h> /* scanf(), printf() */
#include <stdlib.h> /* malloc() */
#include <string.h>

#include "definitions.h" /* MAX_INT_LEN */
#include "function_prototypes.h" /* valid_int(), convert_int() */

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
        printf("%i is not between %i and %i\n", value, min_value, max_value);
        printf("Please input a valid number between %i and %i\n", min_value, max_value);
        printf("> ");
        return scan_int_min_max (min_value, max_value);
    }
    return value;
}

void get_new_user_username(event_manager_t event_manager, char* username)
{
    printf("Please enter your chosen username\n");
    printf("> ");

    scanf("%s", username);

    if(username_taken(event_manager, username))
    {
        printf("Username already taken\n");
        get_new_user_username(event_manager, username);
        return;
    }
    return;
}

void get_new_user_password(char* password)
{
    printf("Please enter your chosen password\n");
    printf("> ");

    scanf("%s", password);

    if(strlen(password) < MIN_PASS_LEN || strlen(password) > MAX_PASS_LEN)
    {
        printf("Password should be between %i and %i characters long\n", MIN_PASS_LEN, MAX_PASS_LEN);
        printf("Your password was %i characters long\n", (int) strlen(password));
        get_new_user_password(password);
        return;
    }
    return;
}

void get_new_user_firstname(char* firstname)
{
    printf("Please enter your first name\n");
    printf("> ");

    scanf("%s", firstname);

    if(strlen(firstname) > MAX_NAME_LEN)
    {
        printf("First name should be less than %i characters long\n", MAX_NAME_LEN);
        printf("Your inputted name was %i characters long\n", (int) strlen(firstname));
        get_new_user_firstname(firstname);
        return;
    }
    return;
}

void get_new_user_lastname(char* lastname)
{
    printf("Please enter your last name\n");
    printf("> ");

    scanf("%s", lastname);

    if(strlen(lastname) > MAX_NAME_LEN)
    {
        printf("Last name should be less than %i characters long\n", MAX_NAME_LEN);
        printf("Your inputted name was %i characters long\n", (int) strlen(lastname));
        get_new_user_lastname(lastname);
        return;
    }
    return;
}