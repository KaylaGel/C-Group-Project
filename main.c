#include <stdio.h> /* printf() */

#include "definitions.h" /* MAX_EVENTS */
#include "structs.h" /* event_t */
#include "function_prototypes.h" /* menu_login() */

/* lines within the code surrounded by #ifdef DEBUG
 * will only run if the following line is not commented out*/
/* #define DEBUG */


int main(void)
{
    #ifdef DEBUG /* For debugging */
        printf("Debug mode enabled\n");
    #endif

    event_manager_t event_manager;
    init_event_manager(&event_manager);

    printf("\n---- Welcome to EventManager v2.4 ----\n\n");
    printf("Description: This program is specifically designed to help event organisers\n");
    printf("and event attenders access event information and join them if they please.\n");
    printf("Note: All private information entered by you, the user, will be saved in an encrypted and compressed format.\n");
    menu_login(&event_manager);

    return 0;
}
