/*
** EPITECH PROJECT, 2024
** a-maze-d
** File description:
** my_memset.c
*/

void *my_memset(void *ptr, int value, int num)
{
    unsigned char *p = ptr;
    int i;

    for (i = 0; i < num; i++)
        p[i] = (unsigned char)value;
    return ptr;
}
