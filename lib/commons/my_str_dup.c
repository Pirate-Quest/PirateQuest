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
