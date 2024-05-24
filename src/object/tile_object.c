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
        .id = 307,
        .rect = (sfIntRect){192, 0, 32 * 3, 4 * 32},
        .origin = (sfVector2f){32, 32 * 3},
    },
    {
        .id = 2656,
        .rect = (sfIntRect){1760, 768, 32 * 3, 32 * 3},
        .origin = (sfVector2f){32, 32 * 2},
    },
    {
        .id = 1201,
        .rect = (sfIntRect){0, 288, 32 * 3, 32 * 4},
        .origin = (sfVector2f){32, 32 * 3},
    },
    {
        .id = 1204,
        .rect = (sfIntRect){96, 288, 32 * 3, 32 * 4},
        .origin = (sfVector2f){32, 32 * 3},
    },
    {
        .id = 2188,
        .rect = (sfIntRect){2752, 544, 32 * 4, 32 * 5},
        .origin = (sfVector2f){32 * 2, 32 * 4},
    },
    {
        .id = 2192,
        .rect = (sfIntRect){2880, 544, 32 * 4, 32 * 5},
        .origin = (sfVector2f){32 * 2, 32 * 4},
    },
    {
        .id = 2196,
        .rect = (sfIntRect){3008, 576, 32 * 4, 32 * 4},
        .origin = (sfVector2f){32 * 2, 32 * 3},
    },
    {
        .id = 4934,
        .rect = (sfIntRect){1056, 1504, 32 * 2, 32 * 3},
        .origin = (sfVector2f){32, 32 * 2},
    },
    {
        .id = 5252,
        .rect = (sfIntRect){1664, 1632, 32 * 2, 32 * 2},
        .origin = (sfVector2f){0, 32},
    },
    {
        .id = 5038,
        .rect = (sfIntRect){1184, 1504, 32 * 3, 32 * 3},
        .origin = (sfVector2f){32, 32 * 3},
    },
    {
        .id = 4935,
        .rect = (sfIntRect){1120, 1504, 32 * 2, 32 * 2},
        .origin = (sfVector2f){0, 64},
    },
    {
        .id = 3651,
        .rect = (sfIntRect){1632, 1120, 32, 32},
        .origin = (sfVector2f){0, 32},
    },
    {
        .id = 3650,
        .rect = (sfIntRect){1600, 1120, 32, 32 },
        .origin = (sfVector2f){0, 32},
    },
    {
        .id = 8622,
        .rect = (sfIntRect){672, 2624, 32 * 4, 32 * 4},
        .origin = (sfVector2f){32, 128},
    },
    {
        .id = 8632,
        .rect = (sfIntRect){992, 2624, 32 * 3, 32 * 4},
        .origin = (sfVector2f){32, 128},
    },
    {
        .id = 8622,
        .rect = (sfIntRect){672, 2624, 32 * 4, 32 * 4},
        .origin = (sfVector2f){32, 128},
    },
    {
        .id = 8628,
        .rect = (sfIntRect){864, 2624, 32 * 4, 32 * 4},
        .origin = (sfVector2f){32, 128},
    },
    {
        .id = 6607,
        .rect = (sfIntRect){224, 2048, 32 * 2, 32 * 2},
        .origin = (sfVector2f){0, 64},
    },
    {
        .id = 9096,
        .rect = (sfIntRect){3040, 2794, 32 * 4, 32 * 4},
        .origin = (sfVector2f){32, 70},
    },
    {
        .id = 9575,
        .rect = (sfIntRect){2400, 3008, 32 * 2, 32 * 2},
        .origin = (sfVector2f){0, 32},
    },
    {
        .id = 9573,
        .rect = (sfIntRect){2336, 3008, 32 * 2, 32 * 2},
        .origin = (sfVector2f){0, 32},
    },
    {
        .id = 8296,
        .rect = (sfIntRect){3072, 2528, 32 * 2, 32 * 3},
        .origin = (sfVector2f){0, 96},
    },
    {
        .id = 8292,
        .rect = (sfIntRect){2944, 2560, 32 * 3, 32 * 2},
        .origin = (sfVector2f){0, 64},
    },
    {
        .id = 8298,
        .rect = (sfIntRect){3036, 2560, 32 * 2, 32 * 3},
        .origin = (sfVector2f){96, 32},
    },
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
