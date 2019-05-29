#include <stdio.h> /* printf() */
#include <string.h>

#include "definitions.h" /* MAX_EVENTS */
#include "structs.h" /* event_t */
#include "function_prototypes.h" /* menu_login() */

/* lines within the code surrounded by #ifdef DEBUG
 * will only run if the following line is not commented out*/
/* #define DEBUG */

/**************************************************************
 * Function Name: 
 * Author(s):
 * Inputs:
 * Outputs: 
 * Description: 
**************************************************************/

int main(int argc, char *argv[])
{
    event_manager_t event_manager;
    init_event_manager(&event_manager);
    


    if (argc == 2)
    {
        if(strcmp(argv[1], "Debug") == 0 || strcmp(argv[1], "debug") == 0)
        {
            event_manager.runtime_mode = MODE_DEBUG;
        }else
        if(argv[1][0] == 'i' || argv[1][0] == 'I')
        {
            event_manager.runtime_mode = MODE_INFO;
        }else
        {
            event_manager.runtime_mode = MODE_NORMAL;
        }
    }else
    {
        event_manager.runtime_mode = MODE_NORMAL;
    }

    if(event_manager.runtime_mode == MODE_DEBUG)
    {
        printf("DEBUG: Debug Mode Enabled\n");
    }else
    if(event_manager.runtime_mode == MODE_INFO)
    {
        print_info();
        return;
    }


    printf("\n---- Welcome to EventManager v2.4 ----\n\n");
    printf("Description: This program is specifically designed to help event organisers\n");
    printf("and event attenders access event information and join them if they please.\n");
    printf("Note: All private information entered by you, the user, will be saved in an encrypted and compressed format.\n");
    menu_login(&event_manager);

    return 0;
}
