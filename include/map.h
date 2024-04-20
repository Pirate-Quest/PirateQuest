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
    #define MAP_HEIGHT 200

    #define RENDER_WIDTH 18
    #define RENDER_HEIGHT 11

    #define LAYER_COUNT 1

typedef struct layer_s {
    char *filepath;
    char *tileset_path;
    int tiles[MAP_WIDTH][MAP_HEIGHT];
} layer_t;

void init_layers(void);

layer_t *get_layers(void);

int get_tile_id(int i, int y, int x);

#endif /* !MAP_H */
