/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** csfml_strlen.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>

int csfml_strlen(sfUint32 *content)
{
    int i = 0;

    while (content[i] != 0)
        i++;
    return i;
}

void csfml_replace_char(sfUint32 *str, sfUint32 find, sfUint32 replace)
{
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == find)
            str[i] = replace;
}

sfUint32 *csfml_strndup(sfUint32 *str, int n)
{
    sfUint32 *new_str = malloc(sizeof(sfUint32) * (n + 1));

    for (int i = 0; i < n; i++)
        new_str[i] = str[i];
    new_str[n] = 0;
    return new_str;
}
