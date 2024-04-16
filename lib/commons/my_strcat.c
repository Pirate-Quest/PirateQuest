/*
** EPITECH PROJECT, 2024
** commons
** File description:
** my_strcat.c
*/

char *my_strcat(char *dest, char const *src)
{
    int i;
    int size = 0;

    while (dest[size] != '\0') {
        size++;
    }
    for (i = 0; src[i] != '\0'; i++) {
        dest[size + i] = src[i];
    }
    dest[size + i] = '\0';
    return dest;
}
