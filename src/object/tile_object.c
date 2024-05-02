/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** tile_object.c
*/

#include "../../include/pirate_quest.h"

const tile_object_t tile_objects[] = {
    {
        .id = 304,
        .rect = (sfIntRect){96, 0, 32 * 3, 32 * 4},
        .origin = (sfVector2f){32, 32 * 3},
    },
    {
        .id = 401,
        .rect = (sfIntRect){0, 0, 32 * 3, 5 * 32},
        .origin = (sfVector2f){32, 32 * 4},
    },
    {
        .id = 2656,
        .rect = (sfIntRect){1760, 768, 32 * 3, 32 * 3},
        .origin = (sfVector2f){32, 32 * 2},
    }
};

void draw_tile_object(pirate_quest_t *game, tile_object_t tile_object,
    sfVector2f pos)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, game->tileset, sfTrue);
    sfSprite_setTextureRect(sprite, tile_object.rect);
    sfSprite_setOrigin(sprite, tile_object.origin);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, (sfVector2f){game->camera->zoom,
        game->camera->zoom});
    sfRenderWindow_drawSprite(game->window->window, sprite, NULL);
    sfSprite_destroy(sprite);
}

void draw_front_tiles_object(pirate_quest_t *game)
{
    for (int i = 0; i < LAYER_COUNT; i++) {
        for (int y = 0; y < RENDER_HEIGHT; y++) {
            for (int x = 0; x < RENDER_WIDTH; x++) {
                if (y < RENDER_HEIGHT / 2 || (y == RENDER_HEIGHT / 2 && game->camera->pos_in_tile.y < 0))
                    continue;
                int id = get_tile_id(i, game->camera->map_position.y +
                    (y - RENDER_HEIGHT / 2),
                    game->camera->map_position.x + (x - RENDER_WIDTH / 2));
                if (id == -1)
                    continue;
                for (int j = 0; j < sizeof(tile_objects) / sizeof(tile_object_t);
                    j++) {
                    if (tile_objects[j].id == id) {
                        draw_tile_object(game, tile_objects[j], (sfVector2f){
                            x * 32 * game->camera->zoom + get_resolution(0).width / 2 - (RENDER_WIDTH * 32 * game->camera->zoom / 2) + (game->camera->pos_in_tile.x * 32),
                            y * 32 * game->camera->zoom + get_resolution(0).height / 2 - (RENDER_HEIGHT * 32 * game->camera->zoom / 2) + (game->camera->pos_in_tile.y * 32)
                        });
                    }
                }
            }
        }
    }
}

    void draw_back_tiles_object(pirate_quest_t *game)
{
    for (int i = 0; i < LAYER_COUNT; i++) {
        for (int y = 0; y < RENDER_HEIGHT; y++) {
            for (int x = 0; x < RENDER_WIDTH; x++) {
                if (y > RENDER_HEIGHT / 2 || (y == RENDER_HEIGHT / 2 && game->camera->pos_in_tile.y > 0))
                    continue;
                int id = get_tile_id(i, game->camera->map_position.y +
                    (y - RENDER_HEIGHT / 2),
                    game->camera->map_position.x + (x - RENDER_WIDTH / 2));
                if (id == -1)
                    continue;
                for (int j = 0; j < sizeof(tile_objects) / sizeof(tile_object_t);
                    j++) {
                    if (tile_objects[j].id == id) {
                        draw_tile_object(game, tile_objects[j], (sfVector2f){
                            x * 32 * game->camera->zoom + get_resolution(0).width / 2 - (RENDER_WIDTH * 32 * game->camera->zoom / 2) + (game->camera->pos_in_tile.x * 32),
                            y * 32 * game->camera->zoom + get_resolution(0).height / 2 - (RENDER_HEIGHT * 32 * game->camera->zoom / 2) + (game->camera->pos_in_tile.y * 32)
                        });
                    }
                }
            }
        }
    }
}
