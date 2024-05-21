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

static int vector_is_in_rect(sfVector2f pos, sfIntRect rect)
{
    if (pos.x >= rect.left && pos.x <= rect.left + rect.width
        && pos.y >= rect.top && pos.y <= rect.top + rect.height)
        return 1;
    return 0;
}

static int rect_is_in_rect(sfIntRect rect1, sfIntRect rect2)
{
    if (rect1.left >= rect2.left
        && rect1.left + rect1.width <= rect2.left + rect2.width
        && rect1.top >= rect2.top
        && rect1.top + rect1.height <= rect2.top + rect2.height)
        return 1;
    return 0;
}

int player_is_in_square(pirate_quest_t *game, int x, int y)
{
    sfVector2f square_pos = sfSprite_getPosition(game->square[0][y][x]);
    sfIntRect square = (sfIntRect){
        square_pos.x,
        square_pos.y,
        32 * game->camera->zoom,
        32 * game->camera->zoom
    };

    return vector_is_in_rect(game->player->pos, square);
}
