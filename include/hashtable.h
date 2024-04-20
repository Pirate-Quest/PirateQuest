/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

    #include <stdlib.h>

typedef struct values_node_s {
    int hash_key;
    char *key;
    void *value;
    struct values_node_s *next;
} values_node_t;

typedef struct values_s {
    values_node_t *nodes;
} values_t;

typedef struct table_entry_s {
    int hash_key;
    values_t *values;
} table_entry_t;

typedef struct hashtable_s {
    int len;
    int (*hash_method)(char *, int);
    table_entry_t **entries;
} hashtable_t;

int hash(char *key, int len);

hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
hashtable_t *ht_from_args(int len, ...);
void delete_hashtable(hashtable_t *ht);

int ht_insert(hashtable_t *ht, char *key, void *value);
int ht_delete(hashtable_t *ht, char *key);
void *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

void remove_value(table_entry_t *entry, char *key, int hash_key);

#endif /* HASHTABLE_H */
