/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** pirate_quest.h
*/

#ifndef PIRATE_QUEST_H
    #define PIRATE_QUEST_H

    #include <stddef.h>
    #include <SFML/Graphics.h>
    #include "commons.h"
    #include "render.h"
    #include "map.h"

typedef sfSprite* square_t[LAYER_COUNT][RENDER_HEIGHT][RENDER_WIDTH];

typedef struct pirate_quest_s {
    render_window_t *window;
    camera_t *camera;
    square_t square;
} pirate_quest_t;

typedef struct asset_s {
    char *key;
    char *path;
} asset_t;

// map/rect_from_id.c
sfIntRect rect_from_id(int id);

// main.c
int get_tile_id(int i, int y, int x);

void move_tiles(pirate_quest_t *game, sfVector2i direction);

void init_squares(pirate_quest_t *game);
void update_layer(pirate_quest_t *game, int i);

#endif /* PIRATE_QUEST_H */
