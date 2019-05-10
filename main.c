#include <stdio.h> /* printf() */

#include "definitions.h" /* MAX_EVENTS */
#include "structs.h" /* event_t */
#include "function_prototypes.h" /* menu_login() */

int main(void)
{
    event_manager_t event_manager;
    event_manager.num_events = 0;

    printf("Welcome to EventManager v2.4\n"); /* TODO: make this temp welcome line better */
    menu_login(&event_manager);


    return 0;
}
