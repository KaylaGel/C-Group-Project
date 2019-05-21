/* Header file for event_manager.c structs */

#ifndef C_GROUP_PROJECT_STRUCTS_H
    #include "definitions.h" /* MAX_NAME_LEN, MAX_PATRONS, MAX_STAFF */
    #define C_GROUP_PROJECT_STRUCTS_H

    struct date
    {
        int year;
        int month;
        int day;
    };
    typedef struct date date_t;

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

    struct staff
    {
        int id;
        person_t personal;
    };
    typedef struct staff staff_t;

    struct coord
    {
        staff_t staff;
    };
    typedef struct coord coord_t;

    struct event
    {
        char name[MAX_NAME_LEN+1];
        person_t patrons[MAX_PATRONS];
        staff_t staff[MAX_STAFF];
        coord_t coordinator; /*possibly staff_t*/
        int num_patrons;
        int num_staff;
        date_t event_date;
        int free_event;
    };
    typedef struct event event_t;

    struct event_manager
    {
        person_t current_logged_in_user;

        event_t events[MAX_EVENTS];
        int num_events;

        person_t users[MAX_USERS];
        int num_users;

        person_t admin_account;
    };
    typedef struct event_manager event_manager_t;

#endif /*C_GROUP_PROJECT_STRUCTS_H*/