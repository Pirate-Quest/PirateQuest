/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** resolutions.c
*/

#include "../../include/render.h"
#include "../../include/pirate_quest.h"
#include <SFML/Graphics.h>

const resolution_t resolutions[3] = {
    {1280, 720},
    {1920, 1080},
    {800, 600}
};

resolution_t get_resolution(pirate_quest_t *game)
{
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
