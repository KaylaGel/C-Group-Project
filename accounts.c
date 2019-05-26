#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h" /* event_t, person_t */
#include "function_prototypes.h" /* get_new_user_* */

#define DEBUG

void create_new_user(event_manager_t event_manager, person_t *user)
{
    get_new_user_username(event_manager, user->username);
    get_new_user_password(user->password, list_count(event_manager.users));
    get_new_user_firstname(user->firstname);
    get_new_user_lastname(user->lastname);
    get_new_user_DOB(&user->DOB);
     
    return;
}

void account_creation(event_manager_t* event_manager)
{
    printf("Account Creation\n");
    person_t* user = malloc(sizeof(person_t));
    create_new_user(*event_manager, user);

    list_add(event_manager->users, (void*) user, sizeof(person_t));

    return;
}

int login(event_manager_t* event_manager)
{
    char username[MAX_NAME_LEN+1];
    char password[MAX_PASS_LEN+1];
    int i; 
    
    get_user_login(username, password);

    /* Test to see if admin details were supplied */
    person_t* admin = (person_t*) event_manager->users->data;
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

    for (i = 0; i < list_count(event_manager->users); i++)
    {
        person_t* user = (person_t*) list_get(event_manager->users, i)->data;
        if ( strcmp( user->username, username ) == 0 )
        {
            char ciphertext[MAX_NAME_LEN+1];
            caeser_cipher(i, password, ciphertext);

            #ifdef DEBUG /* For debugging */
                printf("DEBUG: Plaintext User Input: %s\n", password);
                printf("DEBUG: Encrypted User Input: %s\n", ciphertext);
                printf("DEBUG: Encrypted Account Password: %s\n", user->password);
            #endif
            
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