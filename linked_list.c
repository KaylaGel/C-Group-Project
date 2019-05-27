#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

void list_add(linked_list_t* list, void* data, size_t data_size)
{
    node_t* current_node = list->head;
    node_t* new_node = init_node(data, data_size);

    /* Crawl to the end of the linked list */
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    new_node->previous = current_node;
    return;
}

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

int list_count(linked_list_t* list)
{

    if(list->head == NULL)
    {
        return 0;
    }
    node_t* current_node = list->head;
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

node_t* init_node(void* data, size_t data_size)
{
    node_t* new_node = malloc(sizeof(node_t));

    new_node->previous = malloc(sizeof(node_t*));
    new_node->previous = NULL;
    new_node->next = malloc(sizeof(node_t*));
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

node_t* list_get(linked_list_t* list, int index)
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

node_t* list_first(linked_list_t* list)
{
    return list->head;
}

node_t* list_last(linked_list_t* list)
{
    node_t* current_node = list->head;

    /* Crawl to the start of the linked list */
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    return current_node;
}