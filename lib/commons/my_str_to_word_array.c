/*
** EPITECH PROJECT, 2024
** commons
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include "../../include/commons.h"

static int my_strlen_word(char const *str, char delimiter)
{
    int i;

    for (i = 0; str[i] != delimiter && str[i] != '\0'; i++);
    return i;
}

static int my_strlen_size(char const *str, char delimiter)
{
    int i = 0;
    int x = 0;

    for (; str[i]; i++)
        if (str[i] == '\0' || str[i] == delimiter || str[i] == '\n' ||
            str[i] == '\t')
            x++;
    return x;
}

char *remove_consecutive_delimiters(char const *str, char delimiter)
{
    int len = my_strlen(str);
    char *new_str = malloc(len + 1);
    int j = 0;
    int last_was_delimiter = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] != delimiter || !last_was_delimiter) {
            new_str[j] = str[i];
            j++;
        }
        last_was_delimiter = (str[i] == delimiter);
    }
    new_str[j] = '\0';
    return new_str;
}

char **my_str_to_word_array(char const *str, char regex)
{
    char *new_str = remove_consecutive_delimiters(str, regex);
    int size = my_strlen_size(new_str, regex) + 2;
    char **r = malloc(sizeof(char *) * size);
    int i;
    int x;
    int y;

    for (i = 0; new_str[i] == regex; i++);
    for (x = 0; new_str[i] != '\0'; x++) {
        r[x] = malloc(sizeof(char) * (my_strlen_word(&new_str[i], regex) + 1));
        for (y = 0; new_str[i] != regex && new_str[i] != '\0';) {
            r[x][y] = new_str[i];
            y++;
            i++;
        }
        r[x][y] = '\0';
        for (; new_str[i] == regex && new_str[i]; i++);
    }
    r[x] = NULL;
    return r;
}

void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
