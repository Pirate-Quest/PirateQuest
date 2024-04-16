/*
** EPITECH PROJECT, 2024
** commons
** File description:
** hashtable_delete.c
*/

#include <stdlib.h>
#include "../../../../include/hashtable.h"
#include "../../../../include/commons.h"

static int free_value(int hash_key, values_node_t *prev,
    values_node_t *current, table_entry_t *entry)
{
    if (hash_key == current->hash_key) {
        if (prev == NULL) {
            entry->values->nodes = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        return 1;
    }
    return 0;
}

void remove_value(table_entry_t *entry, char *key, int hash_key)
{
    values_t *values = entry->values;
    values_node_t *current = values->nodes;
    values_node_t *prev = NULL;

    while (current != NULL) {
        if (free_value(hash_key, prev, current, entry)) {
            break;
        }
        prev = current;
        current = current->next;
    }
}

int ht_delete(hashtable_t *ht, char *key)
{
    int hash_key;

    if (ht == NULL || key == NULL || my_strlen(key) == 0)
        return 84;
    hash_key = ht->hash_method(key, ht->len);
    if (ht_search(ht, key) == NULL)
        return 84;
    remove_value(ht->entries[hash_key % ht->len], key, hash_key);
    if (ht->entries[hash_key % ht->len]->values == NULL) {
        free(ht->entries[hash_key % ht->len]);
        ht->entries[hash_key % ht->len] = NULL;
    }
    return 0;
}
