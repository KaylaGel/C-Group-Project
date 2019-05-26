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

    void list_add(node_t* list_node, void* data, size_t data_size);
    void list_remove(node_t* node);
    int list_count(node_t* node);
    node_t* init_node(void* data, size_t data_size);
    node_t* list_get(node_t* list_node, int index);
    node_t* list_first(node_t* list_node);
    node_t* list_last(node_t* list_node);

#endif /*C_GROUP_PROJECT_LINKED_LIST_H*/
