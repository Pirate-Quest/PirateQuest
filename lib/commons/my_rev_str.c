/*
** EPITECH PROJECT, 2024
** commons
** File description:
** my_rev_str.c
*/

#include "../../include/commons.h"

char *my_rev_str(char *str)
{
    char cache;
    int char1 = 0;
    int char2 = my_strlen(str) - 1;

    while (char1 < char2) {
        cache = str[char1];
        str[char1] = str[char2];
        str[char2] = cache;
        char1 = char1 + 1;
        char2 = char2 - 1;
    }
    return str;
}
