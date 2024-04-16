/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** pirate_quest.h
*/

#ifndef PIRATE_QUEST_H
    #define PIRATE_QUEST_H

    #include <stddef.h>
    #include "commons.h"
    #include <SFML/Graphics.h>

const int BACKGROUND_GRID[200][200];

typedef struct asset_s {
    char *key;
    char *path;
} asset_t;

// map/rect_from_id.c
sfVector2u rect_from_id(int id);

#endif /* PIRATE_QUEST_H */
