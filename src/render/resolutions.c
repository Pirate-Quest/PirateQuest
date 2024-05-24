/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** resolutions.c
*/

#include "../../include/render.h"
#include "../../include/pirate_quest.h"
#include <SFML/Graphics.h>

const resolution_t resolutions[2] = {
    {.width = 1280, .height = 720, .zoom = 2.5},
    {.width = 1920, .height = 1080, .zoom = 3.75}
};

static float get_zoom(sfVector2u v)
{
    return resolutions[0].zoom * (v.x / 1280.0);
}

resolution_t get_resolution(pirate_quest_t *game)
{
    if (game->settings->resolution == 2)
        return ((resolution_t) {
            sfRenderWindow_getSize(game->window->window).x,
            sfRenderWindow_getSize(game->window->window).y,
            get_zoom(sfRenderWindow_getSize(game->window->window))
        });
    return (resolutions[game->settings->resolution]);
}

int get_resolutions_count(void)
{
    return (sizeof(resolutions) / sizeof(resolution_t));
}

sfVideoMode get_sfvideo_mode(int index)
{
    resolution_t res = resolutions[index];

    return (sfVideoMode) {res.width, res.height, 32};
}
