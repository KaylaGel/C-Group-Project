#include "stdlib.h"

#include "structs.h" /* event_t, person_t */
#include "function_prototypes.h" /* get_new_user_*,  */

void create_new_user(event_t* events, person_t *user)
{
    get_new_user_username(events, user->username);
    get_new_user_password(user->password);
    get_new_user_firstname(user->firstname);
    get_new_user_lastname(user->lastname);

    return;
}