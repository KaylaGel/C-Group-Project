#include <stdio.h> /* printf() */

#include "definitions.h" /* MAX_EVENTS */
#include "structs.h" /* event_t */
#include "function_prototypes.h" /* menu_login() */

int main(void)
{
    event_t events[MAX_EVENTS];
    int event_count = 0;

    printf("Welcome to EventManager v2.4\n"); /* TODO: make this temp welcome line better */
    menu_login(events, &event_count);


    return 0;
}
