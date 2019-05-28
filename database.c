#include <stdio.h>
#include <stdlib.h>

#include "structs.h"
#include "function_prototypes.h"

#define DATABASE_FILENAME "database.sav"


int save_database(event_manager_t* event_manager)
{
    FILE* plaintext;
    FILE* database;

    plaintext = tmpfile();
    database = fopen(DATABASE_FILENAME, "w");



    printf("Saving Database\n");

    int num_events;
    int num_users;
    num_events = list_count(&event_manager->events);
    num_users = list_count(&event_manager->users);
    fprintf(plaintext, "%i ", num_users);
    fprintf(plaintext, "|"); /* Separator */
    fprintf(plaintext, "%i ", num_events);
    fprintf(plaintext, "\n");

    int i;
    for (i = 0; i < num_users; i++)
    {
        person_t* user = (person_t*) list_get(&event_manager->users, i)->data;
        fprintf(plaintext, "%s \t", user->username);
        fprintf(plaintext, "%s \t", user->password);
        fprintf(plaintext, "%s \t", user->firstname);
        fprintf(plaintext, "%s \t", user->lastname);
        fprintf(plaintext, "%i \t", user->DOB.day);
        fprintf(plaintext, "%i \t", user->DOB.month);
        fprintf(plaintext, "%i \t", user->DOB.year);

        fprintf(plaintext, "\n");
    }

    for (i = 0; i < num_events; i++)
    {
        event_t* event = list_get(&event_manager->events, i)->data;

        fprintf(plaintext, "%s ", event->name);
        fprintf(plaintext, "%s ", event->event_type);

        fprintf(plaintext, "%i | ", event->free_event);

        fprintf(plaintext, "%i ", event->event_date.year);
        fprintf(plaintext, "%i ", event->event_date.month);
        fprintf(plaintext, "%i ", event->event_date.day);
        fprintf(plaintext, "%i ", event->event_date.hour);
        fprintf(plaintext, "%i ", event->event_date.minute);

        fprintf(plaintext, "%s ", event->location.state);
        fprintf(plaintext, "%i ", event->location.postcode);
        fprintf(plaintext, "%s ", event->location.suburb);
        fprintf(plaintext, "%s ", event->location.street_name);
        fprintf(plaintext, "%i ", event->location.street_num);

        person_t* coordinator = event->coordinator;
        int coordinator_index = search_user(&event_manager->users,
                coordinator->username);
        fprintf(plaintext, "%i ||", coordinator_index);

        int num_patrons;
        int num_staff;
        num_patrons = list_count(&event->patrons);
        num_staff = list_count(&event->staff);

        fprintf(plaintext, "%i ", num_patrons);
        fprintf(plaintext, "|"); /* Separator */
        fprintf(plaintext, "%i ", num_staff);
        fprintf(plaintext, "|"); /* Separator */


        int j;
        for (j = 0; j < num_patrons; j++)
        {
            person_t* patron = (person_t*) list_get(&event->patrons, j)->data;

            /* This is the patron's index in the master list of all users */
            int user_index = search_user(&event_manager->users,
                                         patron->username);
            fprintf(plaintext, "%i |", user_index);
        }
        for (j = 0; j < num_staff; j++)
        {
            person_t* staff = (person_t*) list_get(&event->staff, j)->data;

            /* This is the staff's index in the master list of all users */
            int user_index = search_user(&event_manager->users,
                                         staff->username);
            fprintf(plaintext, "%i |", user_index);
        }
        fprintf(plaintext, "\n");
    }
    fprintf(plaintext, "\n");

    printf("Saved Database\n");

    char key[MAX_RESPONSE_LEN+1];
    printf("Please enter a password you would like to encrypt the database "
           "with\n");
    printf("> ");
    scanf("%s", key);
    xor_encrypt_file(key, plaintext, database);
    printf("Database encrypted with key '%s'\n", key);

    fclose(plaintext);
    fclose(database);

    return 0;
}
int load_database(event_manager_t* event_manager)
{
    init_event_manager(event_manager);

    FILE* plaintext;
    FILE* database;

    plaintext = tmpfile();
    database = fopen(DATABASE_FILENAME, "r");


    char key[MAX_RESPONSE_LEN+1];
    printf("Please enter the database password to decrypt\n");
    printf("> ");
    scanf("%s", key);
    xor_encrypt_file(key, database, plaintext);
    printf("Database decrypted with key '%s'\n", key);
    fclose(database);

    printf("Loading Database\n");

    int num_events;
    int num_users;

    fscanf(plaintext, "%i ", &num_users);
    fscanf(plaintext, "|"); /* Separator */
    fscanf(plaintext, "%i ", &num_events);
    fscanf(plaintext, "\n");

    int i;
    for (i = 0; i < num_users; i++)
    {
        person_t user;

        fscanf(plaintext, "%s \t", user.username);
        fscanf(plaintext, "%s \t", user.password);
        fscanf(plaintext, "%s \t", user.firstname);
        fscanf(plaintext, "%s \t", user.lastname);

        fscanf(plaintext, "%i \t", &user.DOB.day);
        fscanf(plaintext, "%i \t", &user.DOB.month);
        fscanf(plaintext, "%i \t", &user.DOB.year);

        fscanf(plaintext, "\n");

        if(event_manager->users.head == NULL)
        {
            event_manager->users.head = init_node(&user, sizeof(person_t));
        }else
        {
            list_add(&event_manager->users, (void *) &user, sizeof(person_t));
        }
    }

    for (i = 0; i < num_events; i++)
    {
        event_t* event = malloc(sizeof(event_t));

        fscanf(plaintext, "%s ", event->name);
        fscanf(plaintext, "%s ", event->event_type);

        fscanf(plaintext, "%i | ", &event->free_event);

        fscanf(plaintext, "%i ", &event->event_date.year);
        fscanf(plaintext, "%i ", &event->event_date.month);
        fscanf(plaintext, "%i ", &event->event_date.day);
        fscanf(plaintext, "%i ", &event->event_date.hour);
        fscanf(plaintext, "%i ", &event->event_date.minute);

        fscanf(plaintext, "%s ", event->location.state);
        fscanf(plaintext, "%i ", &event->location.postcode);
        fscanf(plaintext, "%s ", event->location.suburb);
        fscanf(plaintext, "%s ", event->location.street_name);
        fscanf(plaintext, "%i ", &event->location.street_num);


        int coordinator_index;
        fscanf(plaintext, "%i ||", &coordinator_index);
        event->coordinator = (person_t*) list_get(&event_manager->users,
                                                 coordinator_index)->data;

        int num_patrons;
        int num_staff;

        fscanf(plaintext, "%i ", &num_patrons);
        fscanf(plaintext, "|"); /* Separator */
        fscanf(plaintext, "%i ", &num_staff);
        fscanf(plaintext, "|"); /* Separator */

        int j;
        for (j = 0; j < num_patrons; j++)
        {
            person_t* patron;

            /* This is the patron's index in the master list of all users */
            int user_index;
            fscanf(plaintext, "%i |", &user_index);

            patron = (person_t*) list_get(&event_manager->users,
                                          user_index)->data;
            if(event->patrons.head == NULL)
            {
                event->patrons.head = init_node(patron, sizeof(person_t));
            }else
            {
                list_add(&event->patrons, (void*) patron, sizeof(person_t));
            }

        }
        for (j = 0; j < num_staff; j++)
        {
            person_t* staff;

            /* This is the staff's index in the master list of all users */
            int user_index;
            fscanf(plaintext, "%i |", &user_index);

            staff = (person_t*) list_get(&event_manager->users,
                                          user_index)->data;
            if(event->staff.head == NULL)
            {
                event->staff.head = init_node(staff, sizeof(person_t));
            }else
            {
                list_add(&event->staff, (void*) staff, sizeof(person_t));
            }
        }


        if(event_manager->events.head == NULL)
        {
            event_manager->events.head = init_node((void*) event, sizeof
            (event_t));
        }else
        {
            list_add(&event_manager->events, (void*) event, sizeof(event_t));
        }

        fscanf(plaintext, "\n");
    }
    fscanf(plaintext, "\n");

    printf("Loaded Database\n");

    fclose(plaintext);

    return 0;
}