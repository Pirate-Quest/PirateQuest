/*
** EPITECH PROJECT, 2024
** commons
** File description:
** my_strcmp.c
*/

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1 != 0; i++) {
        if (s1[i] > s2[i]) {
            return 1;
        }
        if (s1[i] < s2[i]) {
            return -1;
        }
        if (s1[i] == '\0') {
            return 0;
        }
    }
    return 0;
}

int my_strncmp(char *s1, char *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] > s2[i]) {
            return 1;
        }
        if (s1[i] < s2[i]) {
            return -1;
        }
        if (s1[i] == '\0') {
            return 0;
        }
    }
    return 0;
}
