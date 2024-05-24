/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** square_tile_from_pos.c
*/

#include "../../include/pirate_quest.h"

static square_tile_t *get_square_from_pos2(pirate_quest_t *game,
    sfVector2f pos, int i)
{
    square_tile_t *square;

    for (int j = game->camera->map_position.x - 1;
        j < game->camera->map_position.x + 2; j++) {
        square = game->square[i][0][j];
        if (pos_is_in_square(game, j, i, pos))
            return square;
    }
    return NULL;
}

square_tile_t *get_square_from_pos(pirate_quest_t *game, sfVector2f pos)
{
    square_tile_t *square;

    for (int i = game->camera->map_position.y - 1;
        i < game->camera->map_position.y + 2; i++) {
        square = get_square_from_pos2(game, pos, i);
        if (square)
            return square;
    }
    return NULL;
}
