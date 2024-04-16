/*
** EPITECH PROJECT, 2023
** commons
** File description:
** my_list_provider.c
*/

#include <stdlib.h>
#include "../../../include/commons.h"

my_list_t *my_list_create(void (*free_value_handler)(void *value))
{
    my_list_t *list = malloc(sizeof(my_list_t));

    if (list == NULL)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->free_data_handler = free_value_handler;
    return list;
}

void my_list_destroy(my_list_t *list)
{
    my_list_node_t *current = list->head;
    my_list_node_t *next;

    while (current != NULL) {
        next = current->next;
        if (list->free_data_handler != NULL)
            list->free_data_handler(current->data);
        free(current);
        current = next;
    }
    free(list);
}

int my_list_size(my_list_t *list)
{
    return list->size;
}
