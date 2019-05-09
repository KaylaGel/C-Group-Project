/* Header file for event_manager.c function prototypes */

#ifndef C_GROUP_PROJECT_PROTOTYPES_H
    #define C_GROUP_PROJECT_PROTOTYPES_H

    void print_menu(void);
    void add_event(event_t* events, int* event_count);
    void display_event(event_t events, int event_count);
    void edit_event(event_t* events);
    void add_database(event_t* events, int event_count);
    void load_database(event_t* events, int* event_count);
    /*Perhaps add more prototype functions if necessary,
    also need to put people on different tasks for these functions*/

#endif /*C_GROUP_PROJECT_PROTOTYPES_H*/
