/* Header file for event_manager.c function prototypes */

#ifndef C_GROUP_PROJECT_PROTOTYPES_H
    #include "structs.h" /* event_t */
    #define C_GROUP_PROJECT_PROTOTYPES_H

    /* event_menu.c */
    void menu_login(event_manager_t* event_manager);
    void menu_main(event_manager_t* event_manager);
    void print_menu_login(void);
    void print_menu_main(void);
    void list_event_names(event_manager_t event_manager);

    /* data_validation.c */
    int valid_int(char* input);
    int convert_int(char* input);
    int username_taken(event_manager_t event_manager, char* username);

    /* user_input.c */
    void get_user_login(char* username, char* password);
    void get_event_login(int* event_id, char* event_password);
    int scan_int(void);
    void get_new_user_username(event_manager_t event_manager, char* username);
    void get_new_user_password(char* password);
    void get_new_user_firstname(char* firstname);
    void get_new_user_lastname(char* lastname);

    /* accounts.c */
    void create_new_user(event_manager_t event_manager, person_t* user);

    /* struct_factory.c */
    void init_event_manager(event_manager_t* event_manager);
    void init_event(event_t* event);

    /* TODO */
    void add_event(event_manager_t* event_manager);
    void display_event(event_manager_t* event_manager);
    void edit_event(event_manager_t* event_manager);
    void add_database(event_manager_t* event_manager);
    void load_database(event_manager_t* event_manager);
    /*Perhaps add more prototype functions if necessary,
    also need to put people on different tasks for these functions*/

#endif /*C_GROUP_PROJECT_PROTOTYPES_H*/
