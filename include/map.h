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

typedef struct layer_s {
    char *filepath;
    char *tileset_path;
    int tiles[MAP_WIDTH][MAP_HEIGHT];
    int render_distance;
} layer_t;

void init_layers(void);

#endif /* !MAP_H */
