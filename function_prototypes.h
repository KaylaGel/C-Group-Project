/* Header file for event_manager.c function prototypes */

#ifndef C_GROUP_PROJECT_PROTOTYPES_H
    #include "structs.h" /* event_t */
    #define C_GROUP_PROJECT_PROTOTYPES_H

    /* menus.c */
    void menu_login(event_manager_t* event_manager);
    void menu_main(event_manager_t* event_manager);
    void menu_admin(event_manager_t* event_manager);
    void print_menu_login(void);
    void print_menu_main(char* current_logged_in_username);
    void print_menu_admin(void);
    void list_event_names(event_manager_t event_manager);
    void list_all(event_manager_t event_manager);

    /* data_validation.c */
    int valid_int(char* input);
    int convert_int(char* input);
    int username_taken(event_manager_t event_manager, char* username);

    /* user_input.c */
    void get_user_login(char* username, char* password);
    void get_event_login(int* event_id, char* event_password);
    int scan_int(void);
    int scan_int_min_max(int min_value, int max_value);
    void get_new_user_username(event_manager_t event_manager, char* username);
    void get_new_user_password(char* password, int user_index);
    void get_new_user_firstname(char* firstname);
    void get_new_user_lastname(char* lastname);
    void get_new_user_DOB(date_t* DOB);
    void get_new_event_name(char* event_name);
    void get_new_event_free_status(int* event_free_status);
    void get_new_event_type(char* event_type);

    /* login_and_accounts.c */
    void create_new_user(event_manager_t event_manager, person_t* user);
    void account_creation(event_manager_t* event_manager);
    int login(event_manager_t* event_manager);

    /* struct_factory.c */
    void init_event_manager(event_manager_t* event_manager);
    void init_event(event_t* event, person_t coordinator);
    void init_staff(event_t* event, person_t staff);
    void init_admin_account(person_t* admin);
    void create_event(event_manager_t* event_manager, person_t creator);

    /* print.c */
    void print_event_name(event_t event, int event_index);
    void print_event_details(event_t event, int event_index);

    /* edit event.c */
    void edit_event(event_manager_t* event_manager);
    int print_edit(void);
    void edit_name(event_manager_t* event_manager, int event_num);
    void edit_type(event_manager_t* event_manager, int event_num);
    void edit_location(event_manager_t* event_manager, int event_num);
    void edit_date_time(event_manager_t* event_manager, int event_num);
    void edit_staff(event_manager_t* event_manager, int event_num);
    void edit_patrons(event_manager_t* event_manager, int event_num);
    int search_event(event_manager_t* event_manager, char event_name[]);

    /* encrypt.c */
    void caeser_cipher(const int shift, const char* plaintext, char* ciphertext);
    int xor_encrypt_file(const char* key, const char* input_filename, const char* output_filename);

    /* TODO */
    void add_event(event_manager_t* event_manager);
    void display_event(event_manager_t* event_manager);
    void add_database(event_manager_t* event_manager);
    void load_database(event_manager_t* event_manager);
    /*Perhaps add more prototype functions if necessary,
    also need to put people on different tasks for these functions*/

#endif /*C_GROUP_PROJECT_PROTOTYPES_H*/
