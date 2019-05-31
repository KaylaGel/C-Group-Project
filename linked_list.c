#include <stdlib.h> /* free, malloc */

#include "linked_list.h" /* linked_list_t, node_t, init_node, 
list_last, list_first */

/**************************************************************
 * Function Name: 
 * Author(s): Dee-Jay
 * Inputs: list - List Pointer, data - Void Pointer, data_size
 * Outputs: N/A
 * Description: Takes the inputted data, creates an new linked list node and
 *              puts it at the end of the list 
**************************************************************/

void list_add(linked_list_t* list, const void* data, const size_t data_size)
{
    node_t* current_node = list->head;
    node_t* new_node = init_node(data, data_size);

    current_node = list_last(list);

    current_node->next = new_node;
    new_node->previous = current_node;
    return;
}

/**************************************************************
 * Function Name: list_remove
 * Author(s): Dee-Jay
 * Inputs: list - List Pointer, node - Node Pointer
 * Outputs: N/A
 * Description: Removes all references to the supplied node, changes the
 *              pointer for nodes adjacent to the new respective previous/next
 *              node, then frees up the memory.
**************************************************************/

void list_remove(linked_list_t* list, node_t* node)
{
    int first_node, last_node;
    first_node = node->previous == NULL;
     last_node = node->next     == NULL;


    if(first_node && !last_node)
    {
        /* If its the first node but not the last node */
        list->head = node->next;
        node->next->previous = NULL;
    }else
    if(!first_node && last_node)
    {
        /* If its the last node but not the first node */
        node->previous->next = NULL;
    }else
    if(first_node && last_node)
    {
        /* If its the first node and last node */
        list->head = NULL;
    }else
    if(!first_node && !last_node)
    {
        /* If its neither the first nor the last node */
        node->previous->next = node->next;
        node->next->previous = node->previous;
    }

    free(node->data);
    free(node);
    return;
}

/**************************************************************
 * Function Name: list_count
 * Author(s): Dee-Jay
 * Inputs: linked_list pointer
 * Outputs: integer
 * Description: Returns the count for the amount of nodes in the supplied list
**************************************************************/

int list_count(const linked_list_t* list)
{
    if(list->head == NULL)
    {
        return 0;
    }
    node_t* current_node = list->head;
    int count = 0;

    current_node = list_first(list);

    /* Crawl to the end of the linked list, counting each node */
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
        count++;
    }

    /* Count the final node*/
    count++;

    return count;
}

/**************************************************************
 * Function Name: init_node
 * Author(s): Dee-Jay
 * Inputs: data void pointer, data_size integer
 * Outputs: initialised node
 * Description: Allocates the memory required for a new node, allocates the
 *              memory required for the data, then copies the supplied data
 *              byte by byte to the newly allocated memory space
**************************************************************/

node_t* init_node(const void* data, const size_t data_size)
{
    node_t* new_node = malloc(sizeof(node_t));

    new_node->previous = NULL;
    new_node->next = NULL;

    new_node->data = malloc(data_size);

    /* Copy over data from supplied void pointer, byte by byte
     * (Assuming a char is one byte)*/
    int i;
    for (i = 0; i < data_size; i++)
    {
        *(char *)(new_node->data + i) = *(char *)(data + i);
    }
    return new_node;
}

/**************************************************************
 * Function Name: list_get
 * Author(s): Dee-Jay
 * Inputs: linked_list pointer, index integer
 * Outputs: node pointer
 * Description: Returns the node at the supplied index position in the
 *              supplied linked list
**************************************************************/

node_t* list_get(const linked_list_t* list, int index)
{
    node_t* current_node = list->head;

    int i;
    for (i = 0; i < index; i++)
    {
        if(current_node->next == NULL)
        {
            /* Reached the end of the list */
            return NULL;
        }
        current_node = current_node->next;
    }
    return current_node;
}

/**************************************************************
 * Function Name: list_first
 * Author(s): Dee-Jay
 * Inputs: linked_list pointer
 * Outputs: node pointer
 * Description: Returns the first node in a list
**************************************************************/

node_t* list_first(const linked_list_t* list)
{
    return list->head;
}

/**************************************************************
 * Function Name: list_last
 * Author(s): Dee-Jay
 * Inputs: linked_list pointer
 * Outputs: node pointer
 * Description: Returns the last node in a list
**************************************************************/

node_t* list_last(const linked_list_t* list)
{
    node_t* current_node = list->head;

    /* Crawl to the start of the linked list */
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    return current_node;
}