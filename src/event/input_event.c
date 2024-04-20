/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** input_event.c
*/

#include "../../include/pirate_quest.h"
#include "../../include/event.h"

void key_pressed_event(sfEvent event, pirate_quest_t *game)
{
    if (event.key.code == sfKeyEscape) {
        sfRenderWindow_close(game->window->window);
    }
}
