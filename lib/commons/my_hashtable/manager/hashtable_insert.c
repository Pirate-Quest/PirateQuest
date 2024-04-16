/*
** EPITECH PROJECT, 2024
** commons
** File description:
** hashtable_insert.c
*/

#include <stdlib.h>
#include "../../../../include/hashtable.h"
#include "../../../../include/commons.h"

void insert_value(table_entry_t *entry, char *key, void *value, int hash_key)
{
    values_t *values = entry->values;
    values_node_t *current = values->nodes;
    values_node_t *new_node = malloc(sizeof(values_node_t));

    while (current != NULL) {
        if (hash_key == current->hash_key) {
            remove_value(entry, key, hash_key);
        }
        current = current->next;
    }
    new_node->value = my_strdup(value);
    new_node->hash_key = hash_key;
    new_node->key = my_strdup(key);
    new_node->next = values->nodes;
    entry->values->nodes = new_node;
}

table_entry_t *create_entry(char *key, void *value, int hash_key)
{
    table_entry_t *new_node = malloc(sizeof(table_entry_t));

    new_node->hash_key = hash_key;
    new_node->values = malloc(sizeof(values_t));
    new_node->values->nodes = NULL;
    insert_value(new_node, key, value, hash_key);
    return new_node;
}

int ht_insert(hashtable_t *ht, char *key, void *value)
{
    int hash_key;

    if (ht == NULL || key == NULL || value == NULL || my_strlen(key) == 0 ||
        my_strlen(value) == 0)
        return 84;
    hash_key = ht->hash_method(key, my_strlen(key));
    if (ht->entries[hash_key % ht->len] != NULL) {
        insert_value(ht->entries[hash_key % ht->len], key, value, hash_key);
        return 0;
    }
    ht->entries[hash_key % ht->len] = create_entry(key, value, hash_key);
    return 0;
}
