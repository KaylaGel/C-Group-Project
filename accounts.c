#include <stdio.h>
#include <string.h>

#include "structs.h" /* event_t, person_t */
#include "function_prototypes.h" /* get_new_user_* */

void create_new_user(event_manager_t event_manager, person_t *user)
{
    get_new_user_username(event_manager, user->username);
    get_new_user_password(user->password);
    get_new_user_firstname(user->firstname);
    get_new_user_lastname(user->lastname);
    get_new_user_lastname(user->DOB->day); /* Fix!!!!!!!!!!!!!!!!! */
    
     
    return;
}

void account_creation(event_manager_t* event_manager)
{
    printf("Account Creation\n");
    person_t user;
    create_new_user(*event_manager, &user);

    /* Assign the current user to the next available user slot */
    event_manager->users[event_manager->num_users] = user;
    event_manager->num_users++;

    return;
}

int login(event_manager_t* event_manager)
{
    char username[MAX_NAME_LEN+1];
    char password[MAX_PASS_LEN+1];
    int i; 
    
    get_user_login(username, password);

    /* Test to see if admin details were supplied */
    if( strcmp( event_manager->admin_account.username, username ) == 0 )
    {
        if( strcmp( event_manager->admin_account.password, password ) == 0 )
        {
            event_manager->current_logged_in_user = event_manager->admin_account;
            printf("Successfully logged in as '%s'\n\n", event_manager->current_logged_in_user.username);
            return 2;
        }
    }

    for (i = 0; i < event_manager->num_users; i++)
    {
        if ( strcmp( event_manager->users[i].username, username ) == 0 )
        {
            /*username exists*/
            if( strcmp( event_manager->users[i].password, password ) == 0 )
            {
                /* correct password */
                /* Set current logged in user as the found user */
                event_manager->current_logged_in_user = event_manager->users[i];
                printf("Successfully logged in as '%s'\n", event_manager->current_logged_in_user.username);
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