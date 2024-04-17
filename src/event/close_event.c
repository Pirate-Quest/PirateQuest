/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** close_event.c
*/

#include <SFML/Graphics.h>
#include "../../include/pirate_quest.h"

void close_event(sfEvent _, pirate_quest_t *game)
{
    sfRenderWindow_close(game->window->window);
}
