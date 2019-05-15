/* Header file for event_manager.c #defines */

#ifndef C_GROUP_PROJECT_DEFINITIONS_H
    #define C_GROUP_PROJECT_DEFINITIONS_H

    #define MAX_INT_LEN 10 /* eg: 2,147,483,647; MAX_INT = 10 digits */

    #define MAX_NAME_LEN 20
    #define MAX_PASS_LEN 24
    #define MIN_PASS_LEN 8
    #define MAX_RESPONSE_LEN 10

    #define YEAR_LEN 4
    #define MIN_MONTH 1
    #define MAX_MONTH 12
    #define MIN_DAY 1
    #define MAX_DAY 31

    /* 200 patrons, 50 staff and a coordinator = 251 users per event */
    /* 10 events * 251 users = 2510 total users. 3000 gives headroom */
    #define MAX_USERS 3000
    #define MAX_PATRONS 200
    #define MAX_STAFF 50
    #define MAX_EVENTS 10

#endif /*C_GROUP_PROJECT_DEFINITIONS_H*/
