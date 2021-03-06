/* Header file for linked_lists */

#ifndef C_GROUP_PROJECT_LINKED_LIST_H
    #include <stdlib.h> /* size_t */
    #define C_GROUP_PROJECT_LINKED_LIST_H

    struct node
    {
        /* Pointer to the previous node in the list */
        struct node* previous;
        /* Pointer to the next node in the list */
        struct node* next;

        /* Void pointer to the data contained in the list node */
        void* data;
    };
    typedef struct node node_t;

    struct linked_list
    {
        node_t* head;
    };
    typedef struct linked_list linked_list_t;

    void list_add(linked_list_t* list, const void* data,
                                       const size_t data_size);
    void list_remove(linked_list_t* list, node_t* node);
    int list_count(const linked_list_t* list);
    node_t* init_node(const void* data, const size_t data_size);
    node_t* list_get(const linked_list_t* list, const int index);
    node_t* list_first(const linked_list_t* list);
    node_t* list_last(const linked_list_t* list);

#endif /*C_GROUP_PROJECT_LINKED_LIST_H*/
