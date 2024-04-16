/*
** EPITECH PROJECT, 2024
** commons
** File description:
** hashtable_dump.c
*/

#include "../../../../include/hashtable.h"
#include "../../../../include/commons.h"

static void print_entry(int position, table_entry_t *entry, int len)
{
    values_node_t *current;

    my_putchar('[');
    my_put_nbr(position);
    my_putstr("]:");
    if (entry == NULL) {
        my_putchar('\n');
        return;
    } else {
        current = entry->values->nodes;
    }
    while (current != NULL) {
        my_putstr("\n> ");
        my_put_nbr(current->hash_key);
        my_putstr(" - ");
        my_putstr(current->value);
        current = current->next;
    }
    my_putchar('\n');
}

void ht_dump(hashtable_t *ht)
{
    table_entry_t *entry;

    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; i++) {
        entry = ht->entries[i];
        if (entry == NULL) {
            print_entry(i, NULL, ht->len);
            continue;
        }
        print_entry(i, entry, ht->len);
    }
}
