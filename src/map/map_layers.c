/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** map_layers.c
*/

#include "../../include/map.h"
#include "../../include/commons.h"
#include <stdio.h>

layer_t layers[1] = {
    {
        .filepath = "assets/map/background_layer.csv",
        .tileset_path = "assets/map/background_layer_tiles.png",
        .render_distance = 10
    }
};
const int layer_count = sizeof(layers) / sizeof(layer_t);


static void init_layer_line(char *line, int i, int y)
{
    char **tiles = my_str_to_word_array(line, ',');
    int tab_len;

    for (tab_len = 0; tiles[tab_len] != NULL; tab_len++);
    for (int x = 0; x < MAP_WIDTH; x++) {
        if (x < tab_len)
            layers[i].tiles[y][x] = my_getnbr(tiles[x]);
        else
            layers[i].tiles[y][x] = -1;
    }
    for (int i = 0; tiles[i] != NULL; i++)
        free(tiles[i]);
    free(tiles);
}

void init_tiles(int i)
{
    FILE *fd = fopen(layers[i].filepath, "r");
    char *line = NULL;
    size_t len = 0;
    size_t size;

    if (fd == NULL)
        return;
    for (int y = 0; y < MAP_HEIGHT; y++) {
        size = getline(&line, &len, fd);
        if (size == -1)
            break;
        line[size - 1] = '\0';
        if (my_strcmp(line, "") == 0)
            break;
        init_layer_line(line, i, y);
    }
    fclose(fd);
}

static void fill_layer(int i)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
        for (int x = 0; x < MAP_WIDTH; x++)
            layers[i].tiles[y][x] = '\0';
}

void init_layers(void)
{
    for (int i = 0; i < layer_count; i++) {
        fill_layer(i);
        init_tiles(i);
    }
}
