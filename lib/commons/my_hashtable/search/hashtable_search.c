/*
** EPITECH PROJECT, 2024
** commons
** File description:
** hashtable_search.c
*/

#include "../../../../include/hashtable.h"
#include "../../../../include/commons.h"

void *ht_search(hashtable_t *ht, char *key)
{
    int hash_key;
    values_t *values;
    values_node_t *current;

    if (ht == NULL || key == NULL || my_strlen(key) == 0 ||
        ht->entries[ht->hash_method(key, my_strlen(key)) % ht->len] == NULL)
        return NULL;
    hash_key = ht->hash_method(key, my_strlen(key));
    values = ht->entries[hash_key % ht->len]->values;
    current = values->nodes;
    while (current != NULL) {
        if (current->hash_key == hash_key)
            return current->value;
        current = current->next;
    }
    return NULL;
}
