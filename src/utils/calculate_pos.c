/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** calculate_pos.c
*/

#include <SFML/Graphics.h>
#include "../../include/pirate_quest.h"

sfVector2f calculate_position(int x, int y, pirate_quest_t *game)
{
    sfVector2f position;

    position.x = x * 32 * game->camera->zoom + get_resolution(game).width / 2
        - (RENDER_WIDTH * 32 * game->camera->zoom / 2)
        + (game->camera->pos_in_tile.x * 32);
    position.y = y * 32 * game->camera->zoom + get_resolution(game).height / 2
        - (RENDER_HEIGHT * 32 * game->camera->zoom / 2)
        + (game->camera->pos_in_tile.y * 32);
    return position;
}
