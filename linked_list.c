#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

void list_add(node_t* list_node, void* data, size_t data_size)
{
    node_t* current_node = list_node;
    node_t* new_node = malloc(sizeof(current_node));
    init_node(new_node, data, data_size);

    /* Crawl to the end of the linked list */
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    new_node->previous = current_node;
    return;
}

void list_remove(node_t* node)
{
    /* If there is a previous node. ie. the node is not the first */
    if( !(node->previous == NULL) )
    {
        node->previous->next = node->next;
    }
    /* If there is a next node ie. the node is not the last */
    if( !(node->next == NULL) )
    {
        node->next->previous = node->previous;
    }
    /* If the node failed the last two checks, then it must be the last node
     * in the list, and can just be removed */
    free(node->data);
    free(node);
    return;
}

int list_count(node_t* node)
{
    node_t* current_node = node;
    int count = 0;

    /* Crawl to the start of the linked list */
    while(current_node->previous != NULL)
    {
        current_node = current_node->previous;
    }

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

void init_node(node_t* node, void* data, size_t data_size)
{
    node->previous = NULL;
    node->next = NULL;
    node->data = malloc(data_size);
    /* Copy over data from supplied void pointer, byte by byte
     * (Assuming a char is one byte)*/
    int i;
    for (i = 0; i < data_size; i++)
    {
        *(char *)(node->data + i) = *(char *)(data + i);
    }
    return;
}

node_t* list_get(node_t* list_node, int index)
{
    node_t* current_node = list_node;

    /* Crawl to the start of the linked list */
    while(current_node->previous != NULL)
    {
        current_node = current_node->previous;
    }

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

node_t* list_first(node_t* list_node)
{
    node_t* current_node = list_node;

    /* Crawl to the start of the linked list */
    while(current_node->previous != NULL)
    {
        current_node = current_node->previous;
    }
    return current_node;
}

node_t* list_last(node_t* list_node)
{
    node_t* current_node = list_node;

    /* Crawl to the start of the linked list */
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    return current_node;
}