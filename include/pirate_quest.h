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

typedef struct pirate_quest_s {
    render_window_t *window;
} pirate_quest_t;

typedef struct asset_s {
    char *key;
    char *path;
} asset_t;

// map/rect_from_id.c
sfVector2u rect_from_id(int id);

#endif /* PIRATE_QUEST_H */
