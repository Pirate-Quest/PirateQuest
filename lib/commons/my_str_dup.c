/*
** EPITECH PROJECT, 2024
** commons
** File description:
** my_str_dup.c
*/

#include <stdlib.h>
#include "../../include/commons.h"

char *my_strdup(char *str)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[i]) {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}

char *my_strndup(char *str, int n)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * (n + 1));

    while (str[i] && i < n) {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}

void replace_char(char *str, char find, char replace)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == find) {
            str[i] = replace;
        }
    }
}
