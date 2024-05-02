/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** map.h
*/

#ifndef MAP_H
    #define MAP_H

    #include <SFML/Graphics.h>

    #define TILE_SIZE 32
    #define MAP_WIDTH 200
    #define MAP_HEIGHT 300

    #define DEFAULT_EMPTY_TILE_ID 10

    #define RENDER_WIDTH 18
    #define RENDER_HEIGHT 11

    #define LAYER_COUNT 17

    #define COLLISION_FILEPATH "assets/map/map_collision.csv"

typedef struct layer_s {
    char *filepath;
    int offset;
    int tiles[MAP_HEIGHT][MAP_WIDTH];
} layer_t;

void init_layers(void);

layer_t *get_layers(void);

int get_tile_id(int i, int y, int x);

#endif /* !MAP_H */
