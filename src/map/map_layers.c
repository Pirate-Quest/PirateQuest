/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** map_layers.c
*/

#include "../../include/map.h"
#include "../../include/commons.h"
#include <stdio.h>
#include <stddef.h>

layer_t layers[LAYER_COUNT] = {
    {
        .filepath = "assets/map/map_1.csv",
        .offset = 100
    },
    {
        .filepath = "assets/map/map_2.csv",
        .offset = 100
    },
    {
        .filepath = "assets/map/map_3.csv",
        .offset = 100
    },
    {
        .filepath = "assets/map/map_4.csv",
        .offset = 100
    },
    {
        .filepath = "assets/map/map_5.csv",
        .offset = 100
    },
    {
        .filepath = "assets/map/map_6.csv",
        .offset = 100
    },
    {
        .filepath = "assets/map/map_7.csv",
        .offset = 100
    },
    {
        .filepath = "assets/map/map_8.csv",
        .offset = 100
    },
    {
        .filepath = "assets/map/map_9.csv",
        .offset = 99
    },
    {
        .filepath = "assets/map/map_10.csv",
        .offset = 100
    }
};

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

static void init_tiles(char *filepath, int i)
{
    FILE *fd = fopen(filepath, "r");
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
    for (int i = 0; i < LAYER_COUNT; i++) {
        fill_layer(i);
        init_tiles(layers[i].filepath, i);
    }
}

layer_t *get_layers(void)
{
    return layers;
}

int get_tile_id(int i, int y, int x)
{
    if (x < 0 || y < 0 || x >= MAP_WIDTH || y >= MAP_HEIGHT)
        return 152;
    return layers[i].tiles[y][x];
}
