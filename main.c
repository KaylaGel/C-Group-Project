#include <stdio.h>

#include "definitions.h"
#include "structs.h"
#include "function_prototypes.h"

#include "event_menu.c"

int main(void)
{
    event_t events[MAX_EVENTS];
    int event_count = 0;

    print_menu_login();
    print_menu_main();


    return 0;
}
