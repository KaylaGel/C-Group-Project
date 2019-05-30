/* Header file for event_manager.c function prototypes */

#ifndef C_GROUP_PROJECT_PROTOTYPES_H
    #include "structs.h" /* event_t */
    #define C_GROUP_PROJECT_PROTOTYPES_H

    /* menus.c */
    void menu_login(event_manager_t* event_manager);
    void menu_main(event_manager_t* event_manager);
    void menu_admin(event_manager_t* event_manager);
    void menu_edit(event_manager_t* event_manager, const int event_num);
    void print_menu_login(void);
    void print_menu_main(const char* current_logged_in_username);
    void print_menu_admin(void);

    /* data_validation.c */
    int valid_int(const char* input);
    int convert_int(const char* input);
    int username_taken(const event_manager_t* event_manager,
                       const char* username);

    /* user_input.c */
    void get_user_login(char* username, char* password);
    int scan_int(void);
    int scan_int_min_max(const int min_value, const int max_value);
    int response_yes(void);
    void join_event(event_manager_t* event_manager);
    void edit_event(event_manager_t* event_manager);
    void add_patron(event_t* event, const event_manager_t* event_manager);
    void add_staff(event_t* event, const event_manager_t* event_manager);
    void remove_patron(event_t* event, const event_manager_t* event_manager);
    void remove_staff(event_t* event, const event_manager_t* event_manager);

    /* user_factory.c */
    void get_new_user_username(const event_manager_t* event_manager,
                               char* username);
    void get_new_user_password(char* password, const int user_index);
    void get_new_user_firstname(char* firstname);
    void get_new_user_lastname(char* lastname);
    void get_new_user_DOB(date_t* DOB);

    /* event_factory.c */
    void get_new_event_name(char* event_name);
    void get_new_event_free_status(int* event_free_status);
    void get_new_event_type(char* event_type);
    void get_new_event_location(address_t* address);
    void get_new_event_date(date_t* date);

    /* accounts.c */
    void create_new_user(const event_manager_t* event_manager, person_t* user);
    void account_creation(event_manager_t* event_manager);
    int login(event_manager_t* event_manager);

    /* struct_factory.c */
    void init_event_manager(event_manager_t* event_manager);
    void init_event(event_t* event, person_t* coordinator);
    void init_staff(event_t* event, person_t* staff);
    void init_admin_account(person_t* admin);
    void create_event(event_manager_t* event_manager, person_t* creator);

    /* print.c */
    void print_event_name(const event_t* event, const int event_index);
    void print_event_details(const event_t* event, const int event_index);
    void list_events(const event_manager_t* event_manager);
    void print_user_details(const person_t* user, const int user_index);
    void list_all(const event_manager_t* event_manager);
    void list_events_detail(const event_manager_t* event_manager);
    void list_users_detail(const event_manager_t* event_manager);
    void print_menu_login(void);
    void print_menu_main(const char* current_logged_in_username);
    void print_menu_admin(void);
    void print_menu_edit(const char* event_name);
    void print_menu_edit_staff(void);
    void print_menu_edit_patrons(void);
    void print_info(void);

    /* edit_event.c */
    void edit_name(event_t* event);
    void edit_type(event_t* event);
    void edit_location(event_t* event);
    void edit_date_time(event_t* event);
    void edit_staff(event_manager_t* event_manager, const int event_num);
    void edit_patrons(event_manager_t* event_manager, const int event_num);

    /* encrypt.c */
    void caeser_cipher(const int shift, const char* plaintext,
                                              char* ciphertext);
    int xor_encrypt_file(const char* key, FILE* input, FILE* output);

    /* search.c */
    int search_event(const linked_list_t* list, const char* event_name);
    int search_event_edit(const linked_list_t* list);
    int search_event_join(const linked_list_t* list);
    int search_user(const linked_list_t* list, const char* username);
    int search_user_add(const linked_list_t* list);
    int search_user_remove(const linked_list_t* list);

    /* display.c */
    void display_event(const event_t* events, const int event_count);

    /* database.c */
    int save_database(const event_manager_t* event_manager);
    int load_database(event_manager_t* event_manager);

    /* TODO
    void add_event(event_manager_t* event_manager);
    void display_event(event_manager_t* event_manager);
    void add_database(event_manager_t* event_manager);
    void load_database(event_manager_t* event_manager);
    Perhaps add more prototype functions if necessary,
    also need to put people on different tasks for these functions*/

#endif /*C_GROUP_PROJECT_PROTOTYPES_H*/
