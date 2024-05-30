/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** healthbar.c
*/

#include "../../include/pirate_quest.h"

void init_healthbar(pirate_quest_t *game, xp_gui_t *xp_gui)
{
    xp_gui->health_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(xp_gui->health_bar,
        (sfVector2f){200, 40});
    sfRectangleShape_setFillColor(xp_gui->health_bar, sfRed);
    sfRectangleShape_setPosition(xp_gui->health_bar,
        (sfVector2f){550, 10});
    xp_gui->health_bar_bg = sfRectangleShape_create();
    sfRectangleShape_setSize(xp_gui->health_bar_bg,
        (sfVector2f){200, 40});
    sfRectangleShape_setFillColor(xp_gui->health_bar_bg, sfBlack);
    sfRectangleShape_setPosition(xp_gui->health_bar_bg,
        (sfVector2f){550, 10});
}

static void update_healthbar(pirate_quest_t *game)
{
    sfRectangleShape_setSize(game->xp_gui->health_bar,
        (sfVector2f){game->player->health * 2, 40});
}

void draw_healthbar(pirate_quest_t *game)
{
    if (game == NULL)
        return;
    update_healthbar(game);
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->xp_gui->health_bar_bg, NULL);
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->xp_gui->health_bar, NULL);
}
