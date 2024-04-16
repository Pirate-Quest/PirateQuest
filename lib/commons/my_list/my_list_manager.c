/*
** EPITECH PROJECT, 2023
** commons
** File description:
** my_list_manager.c
*/

#include <stdlib.h>
#include "../../../include/commons.h"

static void free_element(void (*free_data_handler)(void *value), void *element)
{
    if (free_data_handler != NULL)
        free_data_handler(element);
}

void my_list_add(my_list_t *list, void *value)
{
    my_list_node_t *node = malloc(sizeof(my_list_node_t));

    if (node == NULL)
        return;
    node->data = value;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void *my_list_get(my_list_t *list, int index)
{
    my_list_node_t *current = list->head;
    int i;

    if (index < 0 || index >= list->size)
        return NULL;
    for (i = 0; i < index; i++)
        current = current->next;
    return current->data;
}

void my_list_remove(my_list_t *list, void *value)
{
    my_list_node_t *current = list->head;
    my_list_node_t *prev = NULL;

    while (current != NULL) {
        if (current->data != value) {
            prev = current;
            current = current->next;
            continue;
        }
        if (prev == NULL)
            list->head = current->next;
        else
            prev->next = current->next;
        if (current == list->tail)
            list->tail = prev;
        free_element(list->free_data_handler, current->data);
        free(current);
        list->size--;
        return;
    }
}

int my_list_contains(my_list_t *list, void *value)
{
    my_list_node_t *current = list->head;

    while (current != NULL) {
        if (current->data == value)
            return 1;
        current = current->next;
    }
    return 0;
}
