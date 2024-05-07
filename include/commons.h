/*
** EPITECH PROJECT, 2024
** minishell_1
** File description:
** commons.h
*/

#ifndef COMMONS_H
    #define COMMONS_H

    #include "hashtable.h"

    #define TRUE 1
    #define FALSE 0

    #define INT_MAX 2147483647
    #define INT_MIN -2147483648

    #define UNSIGNED_INT_MAX 4294967295

int my_strlen(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_puterr(char const *str);
void my_put_nbr(int nb);
char *my_strdup(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char *s1, char *s2, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char **my_str_to_word_array(char const *str, char delimiter);
char **my_split_str(char const *str);
void free_array(char **array);
int my_getnbr(char const *str);
int char_to_int(char c);
char *my_rev_str(char *str);
char *my_strcat(char *dest, char const *src);
int count_args(char **args);
char *my_clean_str(char *str);
int my_char_isnum(char c);
int my_str_isnum(char const *str);
int my_char_isalpha(char c);
int my_str_isalpha(char const *str);
void *my_memset(void *ptr, int value, int num);

typedef struct my_list_node_s {
    void *data;
    struct my_list_node_s *next;
} my_list_node_t;

typedef struct my_list_s {
    my_list_node_t *head;
    my_list_node_t *tail;
    int size;
    void (*free_data_handler)(void *value);
} my_list_t;

my_list_t *my_list_create(void (*free_value_handler)(void *value));
void my_list_destroy(my_list_t *list);
void my_list_add(my_list_t *list, void *value);
void *my_list_get(my_list_t *list, int index);
void my_list_remove(my_list_t *list, void *value);
int my_list_size(my_list_t *list);
int my_list_contains(my_list_t *list, void *value);
char *my_itoa(int nb);

typedef struct vector_s {
    int x;
    int y;
} vector_t;

typedef enum {
    UP,
    LEFT,
    DOWN,
    RIGHT,
} direction_t;

#endif /* !COMMONS_H */
