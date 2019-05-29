#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "structs.h" /* event_t, person_t */
#include "function_prototypes.h" /* get_new_user_* */

#define DEBUG

/**************************************************************
 * Function Name: create_new_user
 * Author(s): Dee-Jay, Ryan
 * Inputs: event_manager, user(pointer)
 * Outputs: Initialised User
 * Description: Calls various helper functions to get the user input on what 
 *              the initialised user's variables should be.
**************************************************************/


void create_new_user(event_manager_t event_manager, person_t *user) 
{
    get_new_user_username(event_manager, user->username);

    if(event_manager.runtime_mode == MODE_DEBUG)
    {
        printf("DEBUG: Username '%s'\n", user->username);
    }
    get_new_user_password(user->password, list_count(&event_manager.users));

    if(event_manager.runtime_mode == MODE_DEBUG)
    {
        printf("DEBUG: Password '%s'\n", user->password);
    }
    get_new_user_firstname(user->firstname);

    if(event_manager.runtime_mode == MODE_DEBUG)
    {
        printf("DEBUG: First Name '%s'\n", user->firstname);
    }
    get_new_user_lastname(user->lastname);

    if(event_manager.runtime_mode == MODE_DEBUG)
    {
        printf("DEBUG: Last Name '%s'\n", user->lastname);
    }
    get_new_user_DOB(&user->DOB); /*why &, because a pointer is needed for
 * the function to actually edit the value passed, and not just a local copy
 * made by the function, the others dont need it because they are pointers
 * already, strings are just char pointers*/

    if(event_manager.runtime_mode == MODE_DEBUG)
    {
        printf("DEBUG: DOB '%i/%i/%i'\n", user->DOB.day,
                                          user->DOB.month,
                                          user->DOB.year);
    }
    
    /* To Do */
    /*Print all the new users details together */

    return;
}

/**************************************************************
 * Function Name: account_creation
 * Author(s): Dee-Jay, Jacob
 * Inputs: event_manager(pointer)
 * Outputs: N/A
 * Description: Creates a new user at end of the "users" linked list 
 *              in event_manager
**************************************************************/

void account_creation(event_manager_t* event_manager)
{
    printf("\nAccount Creation\n");
    person_t* user = malloc(sizeof(person_t)); /* Allocates memory which is the size of person_t */
    create_new_user(*event_manager, user); /* This function calls functions withi itself to collect all the data required from the user e.g. Username, Password ect. */


    if(event_manager->users.head == NULL)
    {
        if(event_manager->runtime_mode == MODE_DEBUG)
        {
            printf("DEBUG: User linked list == NULL\n");
            printf("DEBUG: Initialising new linked list\n");
        }
        event_manager->users.head = init_node(user, sizeof(person_t));
    }else
    {
        if(event_manager->runtime_mode == MODE_DEBUG)
        {
            printf("DEBUG: User linked list exists\n");
            printf("DEBUG: Adding user to linked list\n");
        }
        list_add(&event_manager->users, (void *) user, sizeof(person_t));
    }

    return;
}

/**************************************************************
 * Function Name: login
 * Author(s): Dee-Jay
 * Inputs: event_manager(pointer)
 * Outputs: Integer
 * Description: Returns a 0 if the login failed.
 *              Returns a 1 if the login succeeded as a user
 *              Returns a 2 if the login succeeded as an admin
 *              The function loops through each user and compares their 
 *              information with the supplied user input which was recieved 
 *              from the get_user_login function
**************************************************************/

int login(event_manager_t* event_manager)
{
    char username[MAX_NAME_LEN+1];
    char password[MAX_PASS_LEN+1];
    int i; 
    
    get_user_login(username, password);

    /* Test to see if admin details were supplied */
    person_t* admin = &event_manager->admin_account;
    if( strcmp( admin->username, username ) == 0 )
    {
        if( strcmp( admin->password, password ) == 0 )
        {
            event_manager->current_logged_in_user = admin;
            printf("Successfully logged in as '%s'\n\n",
                    event_manager->current_logged_in_user->username);
            return 2;
        }
    }

    for (i = 0; i < list_count(&event_manager->users); i++)
    {
        person_t* user = (person_t*) list_get(&event_manager->users, i)->data;

        if(event_manager->runtime_mode == MODE_DEBUG)
        {
            printf("DEBUG: Username Attempt: '%s' | '%s'\n", username,
                                                             user->username);
        }

        if ( strcmp( user->username, username ) == 0 )
        {
            char ciphertext[MAX_NAME_LEN+1];
            caeser_cipher(i + 1, password, ciphertext);

            if(event_manager->runtime_mode == MODE_DEBUG)
            {
                printf("DEBUG: Plaintext User Input:       %s\n", password);
                printf("DEBUG: Encrypted User Input:       %s\n", ciphertext);
                printf("DEBUG: Encrypted Account Password: %s\n",
                       user->password);
            }

            if( strcmp( user->password, ciphertext ) == 0 )
            {
                event_manager->current_logged_in_user = user;
                printf("Successfully logged in as '%s'\n",
                        event_manager->current_logged_in_user->username);
                return 1;
            }else
            {
                printf("Incorrect Password\n");
                return 0;
            }
        }
    }
    printf("Incorrect Username\n");
    return 0;
}