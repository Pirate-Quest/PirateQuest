/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** texture_util.c
*/

#include <SFML/Graphics.h>

void move_rect(sfIntRect *rect, int offset, int start, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value) {
        rect->left = start;
    }
}
