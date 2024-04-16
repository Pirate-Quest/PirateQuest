/*
** EPITECH PROJECT, 2024
** commons
** File description:
** my_str_isnum.c
*/

int my_char_isnum(char c)
{
    if (c < '0' || c > '9')
        return 0;
    return 1;
}

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_char_isnum(str[i])) {
            return 0;
        }
    }
    return 1;
}
