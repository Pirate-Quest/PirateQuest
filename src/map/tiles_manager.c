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
    game->square[i][loc.y][loc.x] = sfSprite_create();
    sfSprite_setTexture(game->square[i][loc.y][loc.x], texture, sfTrue);
    sfSprite_setTextureRect(game->square[i][loc.y][loc.x], rect_from_id(
        get_tile_id(0, game->camera->map_position.y +
            (loc.y - RENDER_HEIGHT / 2),
        game->camera->map_position.x + (loc.x - RENDER_WIDTH / 2)),
        get_layers()[i].offset)
    );
    sfSprite_setScale(game->square[i][loc.y][loc.x], (sfVector2f){2.5, 2.5});
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
            sfSprite_setPosition(game->square[i][y][x], (sfVector2f){(x * 32 *
                game->camera->zoom) + squares_final_width +
                (game->camera->pos_in_tile.x * 32), (y * 32 *
                game->camera->zoom) + squares_final_height +
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

void update_layer(pirate_quest_t *game, int i)
{
    for (int y = 0; y < RENDER_HEIGHT; y++) {
        for (int x = 0; x < RENDER_WIDTH; x++) {
            sfSprite_setTextureRect(game->square[i][y][x], rect_from_id(
                get_tile_id(i, game->camera->map_position.y + (y -
                RENDER_HEIGHT / 2), game->camera->map_position.x + (x -
                RENDER_WIDTH / 2)), get_layers()[i].offset)
            );
            sfSprite_setPosition(game->square[i][y][x], (sfVector2f){(x * 32 *
                game->camera->zoom) + get_resolution(game).width / 2 -
                (RENDER_WIDTH * 32 * game->camera->zoom / 2) +
                (game->camera->pos_in_tile.x * 32), (y * 32 *
                game->camera->zoom) + get_resolution(game).height / 2 -
                (RENDER_HEIGHT * 32 * game->camera->zoom / 2) +
                (game->camera->pos_in_tile.y * 32)}
            );
            sfRenderWindow_drawSprite(game->window->window,
                game->square[i][y][x], NULL);
        }
    }
}
