/* Header file for event_manager.c function prototypes */

#ifndef C_GROUP_PROJECT_PROTOTYPES_H
    #define C_GROUP_PROJECT_PROTOTYPES_H

    void print_menu_login(void);
    void print_menu_main(void);

    void scan_char(char* input);
    void scan_string(char* input, int len);
    int valid_int(char* input);
    int convert_int(char* input);

    void add_event(event_t* events, int* event_count);
    void display_event(event_t events, int event_count);
    void edit_event(event_t* events);
    void add_database(event_t* events, int event_count);
    void load_database(event_t* events, int* event_count);
    /*Perhaps add more prototype functions if necessary,
    also need to put people on different tasks for these functions*/

#endif /*C_GROUP_PROJECT_PROTOTYPES_H*/
