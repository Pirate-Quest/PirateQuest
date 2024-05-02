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
        .rect = (sfIntRect){96, 0, 32 * 3, 4 * 32},
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

static void draw_tile_object(pirate_quest_t *game, tile_object_t tile_object,
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

static void draw_tile_objects(pirate_quest_t *game, int id, int x, int y)
{
    for (int j = 0; j < sizeof(tile_objects) / sizeof(tile_object_t); j++) {
        if (tile_objects[j].id != id)
            continue;
        draw_tile_object(game, tile_objects[j],
            calculate_position(x, y, game));
    }
}

void draw_front_tiles_object(pirate_quest_t *game, int layer, int y)
{
    int id;

    for (int x = 0; x < RENDER_WIDTH; x++) {
        if (y < RENDER_HEIGHT / 2 || (y == RENDER_HEIGHT / 2 &&
            game->camera->pos_in_tile.y < 0))
            continue;
        id = get_tile_id(layer, game->camera->map_position.y +
            (y - RENDER_HEIGHT / 2),
            game->camera->map_position.x + (x - RENDER_WIDTH / 2));
        if (id == -1)
            continue;
        draw_tile_objects(game, id, x, y);
    }
}

void draw_back_tiles_object(pirate_quest_t *game, int layer, int y)
{
    int id;

    for (int x = 0; x < RENDER_WIDTH; x++) {
        if (y > RENDER_HEIGHT / 2 ||
            (y == RENDER_HEIGHT / 2 && game->camera->pos_in_tile.y > 0))
            continue;
        id = get_tile_id(layer, game->camera->map_position.y +
            (y - RENDER_HEIGHT / 2),
            game->camera->map_position.x + (x - RENDER_WIDTH / 2));
        if (id == -1)
            continue;
        draw_tile_objects(game, id, x, y);
    }
}
