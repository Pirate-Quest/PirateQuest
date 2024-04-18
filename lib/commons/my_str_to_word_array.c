/*
** EPITECH PROJECT, 2024
** commons
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>

int my_strlen_word(char const *str, char separator)
{
    int i;

    for (i = 0; str[i] != separator && str[i] != '\0'; i++);
    return i;
}

int my_strlen_size(char const *str, char separator)
{
    int i = 0;
    int x = 0;

    for (; str[i]; i++)
        if (str[i] == '\0' || str[i] == separator || str[i] == '\n')
            x++;
    return x;
}

char **my_str_to_word_array(char const *str, char separator)
{
    int size = my_strlen_size(str, separator) + 2;
    char **r = malloc(sizeof(char *) * size);
    int i;
    int x;
    int y;

    for (i = 0; str[i] == separator; i++);
    for (x = 0; str[i] != '\0'; x++) {
        r[x] = malloc(sizeof(char) * (my_strlen_word(&str[i], separator) + 1));
        for (y = 0; str[i] != separator && str[i] != '\0';) {
            r[x][y] = str[i];
            y++;
            i++;
        }
        r[x][y] = '\0';
        for (; (str[i] == separator) && str[i]; i++);
    }
    r[x] = NULL;
    return r;
}
