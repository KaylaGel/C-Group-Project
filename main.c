#include <stdio.h> /* printf */
#include <string.h> /* strcmp */

#include "structs.h" /* event_manager_t*/
#include "function_prototypes.h" /* init_event_manager, print_info, menu_login*/

/* lines within the code surrounded by #ifdef DEBUG
 * will only run if the following line is not commented out*/
/* #define DEBUG */

/**************************************************************
 * Function Name: main 
 * Author(s): Everyone
 * Inputs: argc - Integer, argv - String array
 * Outputs: int
 * Description: Main function of the program. 
 *              Initialises the event_manager and adjusts the runtime mode 
 *              based on the arguments supplied. It will then either call the 
 *              menu_login function to continue with the rest of the program 
 *              or it will call the print_info function depending on the 
 *              runtime mode.
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
        return 0;
    }


    printf("\n---- Welcome to Event Hub v2.4 ----\n\n");
    printf("Description: This program is specifically designed to help event "
           "organisers\n");
    printf("and patrons access event information and join them if they please."
           "\n");
    printf("Note: All private information entered by you, the user, will be "
           "saved in an encrypted format.\n");
    menu_login(&event_manager);

    return 0;
}
