#include <stdio.h>
#include <string.h>

#include "definitions.h"
#include "structs.h"
#include "function_prototypes.h"

/**************************************************************
 * Function Name: 
 * Author(s):
 * Inputs:
 * Outputs: 
 * Description: 
**************************************************************/

void get_new_user_username(event_manager_t event_manager, char* username)
{
    printf("Please enter your chosen username\n");
    printf("> ");

    scanf("%s", username);
    if(username_taken(&event_manager, username))
    {
        printf("Username already taken\n");
        get_new_user_username(event_manager, username);
        return;
    }
    return;
}

/**************************************************************
 * Function Name: 
 * Author(s):
 * Inputs:
 * Outputs: 
 * Description: 
**************************************************************/

void get_new_user_password(char* password, int user_index)
{
    printf("Please enter your chosen password\n");
    printf("> ");

    char plaintext[MAX_PASS_LEN+1];

    scanf("%s", plaintext);

    if(strlen(plaintext) < MIN_PASS_LEN || strlen(plaintext) > MAX_PASS_LEN)
    {
        printf("Password should be between %i and %i characters long\n",
               MIN_PASS_LEN, MAX_PASS_LEN);
        printf("Your password was %i characters long\n",
               (int) strlen(plaintext));
        get_new_user_password(password, user_index);
        return;
    }

    caeser_cipher(user_index + 1, plaintext, password);


    strcpy(plaintext, " ");

    return;
}

/**************************************************************
 * Function Name: 
 * Author(s):
 * Inputs:
 * Outputs: 
 * Description: 
**************************************************************/

void get_new_user_firstname(char* firstname)
{
    printf("\nPlease enter your first name\n");
    printf("> ");

    scanf("%s", firstname);

    if(strlen(firstname) > MAX_NAME_LEN)
    {
        printf("First name should be less than %i characters long\n",
               MAX_NAME_LEN);
        printf("Your inputted name was %i characters long\n",
               (int) strlen(firstname));
        get_new_user_firstname(firstname);
        return;
    }
    return;
}

/**************************************************************
 * Function Name: 
 * Author(s):
 * Inputs:
 * Outputs: 
 * Description: 
**************************************************************/

void get_new_user_lastname(char* lastname)
{
    printf("\nPlease enter your last name\n");
    printf("> ");

    scanf("%s", lastname);

    if(strlen(lastname) > MAX_NAME_LEN)
    {
        printf("Last name should be less than %i characters long\n",
               MAX_NAME_LEN);
        printf("Your inputted name was %i characters long\n",
               (int) strlen(lastname));
        get_new_user_lastname(lastname);
        return;
    }
    return;
}

/**************************************************************
 * Function Name: 
 * Author(s):
 * Inputs:
 * Outputs: 
 * Description: 
**************************************************************/

void get_new_user_DOB(date_t* DOB)
{
    printf("\nPlease enter your date of birth\n");

    printf("Day");
    printf(">");
    DOB->day = scan_int_min_max(MIN_DAY, MAX_DAY);

    printf("Month");
    printf(">");
    DOB->month = scan_int_min_max(MIN_MONTH, MAX_MONTH);

    printf("Year");
    printf(">");
    DOB->year = scan_int_min_max(MIN_YEAR, MAX_YEAR);

    return;
}