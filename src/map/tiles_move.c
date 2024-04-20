/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** tiles_move.c
*/

#include "../../include/render.h"
#include "../../include/pirate_quest.h"

static void move_tiles_right(pirate_quest_t *game, square_t temp_square, int i)
{
    for (int y = 0; y < RENDER_HEIGHT; y++)
        for (int x = 0; x < RENDER_WIDTH; x++)
            temp_square[i][y][x] = game->square[i][y][x];
    for (int y = 0; y < RENDER_HEIGHT; y++)
        for (int x = 0; x < RENDER_WIDTH; x++)
            game->square[i][y][x] = temp_square[i][y][(x + 1) % RENDER_WIDTH];
}

static void move_tiles_left(pirate_quest_t *game, square_t temp_square, int i)
{
    for (int y = 0; y < RENDER_HEIGHT; y++)
        for (int x = 0; x < RENDER_WIDTH; x++)
            temp_square[i][y][x] = game->square[i][y][x];
    for (int y = 0; y < RENDER_HEIGHT; y++)
        for (int x = 0; x < RENDER_WIDTH; x++)
            game->square[i][y][x] = temp_square[i][y][(x - 1) % RENDER_WIDTH];
}

static void move_tiles_up(pirate_quest_t *game, square_t temp_square, int i)
{
    for (int y = 0; y < RENDER_HEIGHT; y++)
        for (int x = 0; x < RENDER_WIDTH; x++)
            temp_square[i][y][x] = game->square[i][y][x];
    for (int y = 0; y < RENDER_HEIGHT; y++)
        for (int x = 0; x < RENDER_WIDTH; x++)
            game->square[i][y][x] = temp_square[i][(y - 1) % RENDER_HEIGHT][x];
}

static void move_tiles_down(pirate_quest_t *game, square_t temp_square, int i)
{
    for (int y = 0; y < RENDER_HEIGHT; y++)
        for (int x = 0; x < RENDER_WIDTH; x++)
            temp_square[i][y][x] = game->square[i][y][x];
    for (int y = 0; y < RENDER_HEIGHT; y++)
        for (int x = 0; x < RENDER_WIDTH; x++)
            game->square[i][y][x] = temp_square[i][(y + 1) % RENDER_HEIGHT][x];
}

void move_tiles(pirate_quest_t *game, sfVector2i direction)
{
    square_t temp_square;

    if (direction.x == 1) {
        for (int i = 0; i < LAYER_COUNT; i++)
            move_tiles_right(game, temp_square, i);
    }
    if (direction.x == -1) {
        for (int i = 0; i < LAYER_COUNT; i++)
            move_tiles_left(game, temp_square, i);
    }
    if (direction.y == 1) {
        for (int i = 0; i < LAYER_COUNT; i++)
            move_tiles_down(game, temp_square, i);
    }
    if (direction.y == -1) {
        for (int i = 0; i < LAYER_COUNT; i++)
            move_tiles_up(game, temp_square, i);
    }
}
