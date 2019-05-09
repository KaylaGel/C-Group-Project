#include <stdio.h>

#include "definitions.h"
#include "structs.h"
#include "function_prototypes.h"

#include "event_menu.c"
#include "user_input.c"

int main(void)
{
    event_t events[MAX_EVENTS];
    int event_count = 0;

    print_menu_login();
    print_menu_main();
    char test;
    scanChar(&test);
    if (validInt(&test)) {
        int testInt = convertInt(&test);
        printf("Int: %i\n", testInt);
    } else
    {
        printf("Char: %c\n", test);
    }
    char testString[11];
    scanString(testString, 10);
    if (validInt(testString)) {
        int testInt = convertInt(testString);
        printf("Int: %i\n", testInt);
    } else
    {
        printf("String: %s\n", testString);
    }

    return 0;
}
