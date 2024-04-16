/*
** EPITECH PROJECT, 2024
** commons
** File description:
** my_str_utils.c
*/

#include "../../include/commons.h"
#include <unistd.h>
#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i] != '\0'; i++);
    return i;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    if (str == NULL)
        return;
    write(1, str, my_strlen(str));
}

void my_puterr(char const *str)
{
    if (str == NULL)
        return;
    write(2, str, my_strlen(str));
}

static void append_char(char *result, int *j, char c)
{
    result[*j] = c;
    (*j)++;
}

static void append_one_space(int bool, char *result, int *j, int *space_seen)
{
    if (bool) {
        append_char(result, j, ' ');
        *space_seen = 1;
    }
}

char *my_clean_str(char *str)
{
    int len = my_strlen(str);
    char *result = (char *)malloc(len + 1);
    int i = 0;
    int j = 0;
    int space_seen = 0;

    while (i < len) {
        if (str[i] == ' ' || str[i] == '\t') {
            append_one_space(!space_seen, result, &j, &space_seen);
        } else {
            append_char(result, &j, str[i]);
            space_seen = 0;
        }
        i++;
    }
    result[j] = '\0';
    return result;
}
