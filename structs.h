/* Header file for event_manager.c structs */

#ifndef C_GROUP_PROJECT_STRUCTS_H
    #include "definitions.h" /* MAX_NAME_LEN, MAX_PATRONS, MAX_STAFF */
    #include "linked_list.h" /* node_t */
    #define C_GROUP_PROJECT_STRUCTS_H

    struct date
    {
        int year;
        int month;
        int day;
        int hour;
        int minute;
    };
    typedef struct date date_t;

    struct address
    {
        int street_num;
        char street_name[MAX_NAME_LEN+1];
        char suburb[MAX_NAME_LEN+1];
        int postcode;
        char state[MAX_NAME_LEN+1];
    };
    typedef struct address address_t;

    struct card
    {
        int card_num;
        date_t exp;
        int cvv;
        char name;
    };

    struct person
    {
        char firstname[MAX_NAME_LEN+1];
        char lastname[MAX_NAME_LEN+1];
        char username[MAX_NAME_LEN+1];
        char password[MAX_PASS_LEN+1];

        date_t DOB;
    };
    typedef struct person person_t;

    struct event
    {
        char name[MAX_NAME_LEN+1];
        char event_type[MAX_NAME_LEN+1];
        person_t patrons[MAX_PATRONS];
        person_t staff[MAX_STAFF];
        person_t coordinator;
        int num_patrons;
        int num_staff;
        address_t location;
        date_t event_date;
        int free_event;
    };
    typedef struct event event_t;

    struct event_manager
    {
        person_t* current_logged_in_user;

        node_t events[MAX_EVENTS];
        node_t users[MAX_USERS];
    };
    typedef struct event_manager event_manager_t;

#endif /*C_GROUP_PROJECT_STRUCTS_H*/
