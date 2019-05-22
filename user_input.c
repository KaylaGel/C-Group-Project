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
    /* TODO: handle the password in a way that incorporates encryption/hashing ie. dont store passwords in plaintext */
    printf("Please enter your chosen password\n");
    printf("> ");

    char plaintext[MAX_PASS_LEN+1];

    scanf("%s", plaintext);

    if(strlen(plaintext) < MIN_PASS_LEN || strlen(plaintext) > MAX_PASS_LEN)
    {
        printf("Password should be between %i and %i characters long\n", MIN_PASS_LEN, MAX_PASS_LEN);
        printf("Your password was %i characters long\n", (int) strlen(password));
        get_new_user_password(password);
        return;
    }

    encrypt_plaintext(plaintext, password);
    #ifdef DEBUG /* For debugging */
            printf("Plaintext Password: %s\n", password);
            printf("Encrypted Password: %s\n", password);
    #endif


    strcpy(plaintext, " ");

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

void get_new_user_DOB(date_t* DOB)
{
    printf("Please enter your date of birth\n");

    printf("Day");
    printf(">");
    DOB->day = scan_int_min_max(MIN_DAY, MAX_DAY);

    printf("Month");
    printf(">");
    DOB->month = scan_int_min_max(MIN_MONTH, MAX_MONTH);

    printf("Year");
    printf(">");
    DOB->year = scan_int_min_max(MIN_YEAR, MAX_YEAR);

    #ifdef DEBUG /* For debugging */
        printf("Inputted DOB is\n");
        printf("Day: %i\n", DOB->day);
        printf("Month: %i\n", DOB->month);
        printf("Year: %i\n", DOB->year);
    #endif

    return;
}

void get_new_event_name(char* event_name)
{
    printf("Please enter the event name\n");
    printf(">");

    scanf("%s", event_name);

    if(strlen(event_name) > MAX_NAME_LEN)
    {
        printf("Event name should be less than %i characters long\n", MAX_NAME_LEN);
        printf("Your inputted name was %i characters long\n", (int) strlen(event_name));
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
    }

    return;
}

void get_new_event_type(char* event_type)
{
    return;
}