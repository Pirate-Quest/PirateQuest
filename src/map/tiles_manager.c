/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** tiles_manager.c
*/

#include "../../include/render.h"
#include "../../include/pirate_quest.h"

void init_square_sprite(int i, sfVector2i loc, pirate_quest_t *game,
    sfTexture *texture)
{
    square_tile_t *square = malloc(sizeof(square_tile_t));

    square->pos = loc;
    square->sprite = sfSprite_create();
    game->square[i][loc.y][loc.x] = square;
    sfSprite_setTexture(
        game->square[i][loc.y][loc.x]->sprite, texture, sfTrue);
    sfSprite_setTextureRect(game->square[i][loc.y][loc.x]->sprite,
        rect_from_id(get_tile_id(0, game->camera->map_position.y +
            (loc.y - RENDER_HEIGHT / 2),
        game->camera->map_position.x + (loc.x - RENDER_WIDTH / 2)),
        get_layers()[i].offset)
    );
    sfSprite_setScale(game->square[i][loc.y][loc.x]->sprite,
        (sfVector2f){game->camera->zoom, game->camera->zoom});
}

static void init_square(pirate_quest_t *game, int i, sfTexture *texture)
{
    float squares_final_width;
    float squares_final_height;

    for (int y = 0; y < RENDER_HEIGHT; y++)
        for (int x = 0; x < RENDER_WIDTH; x++) {
            init_square_sprite(i, (sfVector2i){x, y}, game, texture);
            squares_final_width = get_resolution(game).width / 2 -
                (RENDER_WIDTH * 32 * game->camera->zoom / 2);
            squares_final_height = get_resolution(game).height / 2 -
                (RENDER_HEIGHT * 32 * game->camera->zoom / 2);
            sfSprite_setPosition(game->square[i][y][x]->sprite,
                (sfVector2f){(x * 32 * game->camera->zoom) +
                squares_final_width + (game->camera->pos_in_tile.x * 32),
                (y * 32 * game->camera->zoom) + squares_final_height +
                (game->camera->pos_in_tile.y * 32)}
            );
        }
}

void init_squares(pirate_quest_t *game)
{
    for (int i = 0; i < LAYER_COUNT; i++) {
        init_square(
            game,
            i,
            game->tileset
        );
    }
}

static square_tile_t *get_square_3(pirate_quest_t *game, sfVector2i pos,
    int i, int y)
{
    for (int x = 0; x < RENDER_WIDTH; x++) {
        if (game->square[i][y][x]->pos.x == pos.x &&
            game->square[i][y][x]->pos.y == pos.y)
            return game->square[i][y][x];
    }
    return NULL;
}

static square_tile_t *get_square2(pirate_quest_t *game, sfVector2i pos, int i)
{
    square_tile_t *square;

    for (int y = 0; y < RENDER_HEIGHT; y++) {
        square = get_square_3(game, pos, i, y);
        if (square != NULL)
            return square;
    }
    return NULL;
}

square_tile_t *get_square(pirate_quest_t *game, sfVector2i pos)
{
    square_tile_t *square;

    for (int i = 0; i < LAYER_COUNT; i++) {
        square = get_square2(game, pos, i);
        if (square != NULL)
            return square;
    }
    return NULL;
}

void set_texture_rect(pirate_quest_t *game, int i, int x, int y)
{
    sfSprite_setTextureRect(game->square[i][y][x]->sprite,
        rect_from_id(get_tile_id(i, game->camera->map_position.y + (y -
        RENDER_HEIGHT / 2), game->camera->map_position.x + (x -
        RENDER_WIDTH / 2)), get_layers()[i].offset)
    );
}

void update_layer(pirate_quest_t *game, int i)
{
    for (int y = 0; y < RENDER_HEIGHT; y++) {
        for (int x = 0; x < RENDER_WIDTH; x++) {
            game->square[i][y][x]->pos = (sfVector2i){
                game->camera->map_position.x + (x - RENDER_WIDTH / 2),
                game->camera->map_position.y + (y - RENDER_HEIGHT / 2)
            };
            set_texture_rect(game, i, x, y);
            sfSprite_setPosition(game->square[i][y][x]->sprite,
                (sfVector2f){(x * 32 * game->camera->zoom) +
                get_resolution(game).width / 2 - (RENDER_WIDTH * 32 *
                game->camera->zoom / 2) +
                (game->camera->pos_in_tile.x * 32), (y * 32 *
                game->camera->zoom) + get_resolution(game).height / 2 -
                (RENDER_HEIGHT * 32 * game->camera->zoom / 2) +
                (game->camera->pos_in_tile.y * 32)}
            );
            sfRenderWindow_drawSprite(game->window->window,
                game->square[i][y][x]->sprite, NULL);
        }
    }
}
