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

    struct card {
        int card_num;
        date_t exp;
        int cvv;
        char name;
    };

    struct person
    {
        char firstname[MAX_NAME_LEN];
        char lastname[MAX_NAME_LEN];
        char password[MAX_PASS_LEN];
        date_t DOB;
    };
    typedef struct person person_t;

    struct patron
    {
        person_t personal;
    };
    typedef struct patron patron_t;

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
        char name[MAX_NAME_LEN];
        patron_t patrons[MAX_PATRONS];
        staff_t staffs[MAX_STAFF];
        coord_t coordinator;
    };
    typedef struct event event_t;

#endif /*C_GROUP_PROJECT_STRUCTS_H*/
