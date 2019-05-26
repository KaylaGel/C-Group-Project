#include <stdio.h>

#include "structs.h"

#define EVENT_DATABASE_FILE_NAME "Event_Database.txt"
#define USER_DATABASE_FILE_NAME "Event_Database.txt"

/* To Do */

/*
 * The name of every event
 * The free/paid status of every event
 * The event type of every event
 * Which users are attending for each event
 * Which users are staff for each event
 * Which users are coordinators for each event
 * The number of staff for each event
 * The number of patrons for each event
 * The address of each event
 * The date of each event
 *
 * The number of events
 * The number of users
 *
 * NOTE xor_encrypt_file() has been created and can be used to xor encrypt
 * files
 * Could use for the database after it has been saved and before it is loaded
 * Could possibly ask user for a database password that is used as the xor
 * key to save and load the database
 * Wrong password when loading would result in incorrect data loading
*

/************************************************************************


EVENT DATABASE WRITING/APPENDING


************************************************************************/
void add_database(event_manager_t* event_manager)
{
    /*write all event details to add_database*/
    /*write all logins to database*/
    int i;
    FILE *fp = NULL;

    fp = fopen(EVENT_DATABASE_FILE_NAME, "+w");
    if (fp == NULL)
    {
        printf("Write error\n");
        return;
    }

    /* Event database */
    for (i = 0; i <= event_manager->num_events; i++)
    {
        /* For Event Export might have to change some things due to encryption*/
        fprintf(fp, "%s",
                event_manager->events[i]); /*What other variables need to be saved to the file*/
    }


    fclose(fp);

    /************************************************************************
    

    USER DATABASE WRITING/APPENDING
    

    ************************************************************************/

    FILE *fp = NULL;

    fp = fopen(USER_DATABASE_FILE_NAME, "+w");
    if (fp == NULL)
    {
        printf("Write error\n");
        return;
    }

    /* User database */
    for (i = 0; i <= MAX_USERS - 1; i++)
    {
        /* For User Export might have to change some things due to encryption*/
        fprintf(fp, "%s", event_manager->users[i]);
        /* The username & password of every user
         * The first & last name of every user
         * The DOB of every user
        */

    }

    fclose(fp);


    return;


}
