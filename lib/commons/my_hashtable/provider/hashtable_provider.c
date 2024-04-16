/*
** EPITECH PROJECT, 2024
** commons
** File description:
** hashtable_provider.c
*/

#include <stdlib.h>
#include "../../../../include/hashtable.h"

hashtable_t *new_hashtable(int (*hash_method)(char *, int), int len)
{
    hashtable_t *result = malloc(sizeof(hashtable_t));
    table_entry_t **entries = malloc(sizeof(table_entry_t) * len + 1);

    if (hash_method == NULL || len <= 0)
        return NULL;
    result->len = len;
    result->hash_method = hash_method;
    for (int i = 0; i < len; i++) {
        entries[i] = NULL;
    }
    entries[len] = NULL;
    result->entries = entries;
    return result;
}

static void free_ht(hashtable_t *ht)
{
    free(ht->entries);
    free(ht);
}

void delete_hashtable(hashtable_t *ht)
{
    values_node_t *value_current;
    values_node_t *value_next;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; i++) {
        if (ht->entries[i] == NULL)
            continue;
        value_current = ht->entries[i]->values->nodes;
        while (value_current != NULL) {
            value_next = value_current->next;
            free(value_current->value);
            free(value_current->key);
            free(value_current);
            value_current = value_next;
        }
        free(ht->entries[i]->values);
        free(ht->entries[i]);
    }
    free_ht(ht);
}
