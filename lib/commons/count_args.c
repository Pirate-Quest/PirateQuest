/*
** EPITECH PROJECT, 2024
** commons
** File description:
** count_args.c
*/

#include <unistd.h>

int count_args(char **args)
{
    int i = 0;

    for (; args[i] != NULL; i++);
    return i;
}
