/*
** EPITECH PROJECT, 2024
** commons
** File description:
** my_strcpy.c
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; src[i] != '\0' && i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
