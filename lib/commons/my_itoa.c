/*
** EPITECH PROJECT, 2024
** commons
** File description:
** my_itoa.c
*/

#include <stdlib.h>

static int get_size(int nb)
{
    int size = 1;

    while (nb >= 10) {
        nb = nb / 10;
        size += 1;
    }
    return size;
}

char *my_itoa(int nb)
{
    int lenght = get_size(nb);
    char *str = malloc(sizeof(char) * lenght + 1);

    str[lenght] = '\0';
    lenght = lenght - 1;
    for (; lenght >= 0; lenght--) {
        str[lenght] = (nb % 10) + 48;
        nb = nb / 10;
    }
    return str;
}
