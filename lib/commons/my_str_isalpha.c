/*
** EPITECH PROJECT, 2024
** commons
** File description:
** my_str_isalpha.c
*/

int my_char_isalpha(char c)
{
    if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
        return 0;
    return 1;
}

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!my_char_isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}
