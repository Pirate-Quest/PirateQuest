/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** collision.c
*/


#include "../../include/pirate_quest.h"
#include <stdio.h>

static void init_layer_line(pirate_quest_t *game, char *line, int y)
{
    char **tiles = my_str_to_word_array(line, ',');
    int tab_len;

    for (tab_len = 0; tiles[tab_len] != NULL; tab_len++);
    for (int x = 0; x < MAP_WIDTH; x++) {
        if (x < tab_len)
            game->collision[y][x] = my_getnbr(tiles[x]);
        else
            game->collision[y][x] = -1;
    }
    for (int i = 0; tiles[i] != NULL; i++)
        free(tiles[i]);
    free(tiles);
}

void init_collisions(pirate_quest_t *game)
{
    FILE *fd = fopen(COLLISION_FILEPATH, "r");
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
        init_layer_line(game, line, y);
    }
    fclose(fd);
}
