/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** xp_gui.c
*/

#include "../../include/pirate_quest.h"
#include <stdlib.h>
#include <string.h>

static void init_lvl_text(xp_gui_t *xp_gui)
{
    xp_gui->lvl_text = sfText_create();
    sfText_setFont(xp_gui->lvl_text, xp_gui->font);
    sfText_setCharacterSize(xp_gui->lvl_text, 20);
    sfText_setPosition(xp_gui->lvl_text, (sfVector2f){40, 12});
    sfText_setStyle(xp_gui->lvl_text, sfTextBold);
    xp_gui->lvl_bg = sfRectangleShape_create();
    sfRectangleShape_setSize(xp_gui->lvl_bg, (sfVector2f){100, 40});
    sfRectangleShape_setFillColor(xp_gui->lvl_bg, (sfColor){0, 0, 0, 180});
    sfRectangleShape_setPosition(xp_gui->lvl_bg, (sfVector2f){20, 10});
}

static void init_xp_bar(xp_gui_t *xp_gui)
{
    xp_gui->xp_bar_bg = sfRectangleShape_create();
    sfRectangleShape_setSize(xp_gui->xp_bar_bg, (sfVector2f){400, 40});
    sfRectangleShape_setFillColor(xp_gui->xp_bar_bg, (sfColor){0, 0, 0, 180});
    sfRectangleShape_setPosition(xp_gui->xp_bar_bg, (sfVector2f){140, 10});
    xp_gui->xp_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(xp_gui->xp_bar, (sfVector2f){400, 40});
    sfRectangleShape_setFillColor(xp_gui->xp_bar, sfGreen);
    sfRectangleShape_setPosition(xp_gui->xp_bar, (sfVector2f){140, 10});
}

void init_xp_gui(pirate_quest_t *game)
{
    xp_gui_t *xp_gui = malloc(sizeof(xp_gui_t));

    xp_gui->font = sfFont_createFromFile("assets/font/Roboto.ttf");
    xp_gui->xp_text = sfText_create();
    init_xp_bar(xp_gui);
    sfText_setFont(xp_gui->xp_text, xp_gui->font);
    sfText_setCharacterSize(xp_gui->xp_text, 20);
    sfText_setPosition(xp_gui->xp_text, (sfVector2f){0, 0});
    xp_gui->upgrade_points = sfText_create();
    sfText_setFont(xp_gui->upgrade_points, xp_gui->font);
    sfText_setCharacterSize(xp_gui->upgrade_points, 25);
    sfText_setPosition(xp_gui->upgrade_points, (sfVector2f){36, 74});
    init_lvl_text(xp_gui);
    game->xp_gui = xp_gui;
}

static void update_pos(xp_gui_t *xp_gui)
{
    sfFloatRect text_rect = sfText_getGlobalBounds(xp_gui->xp_text);

    sfText_setPosition(xp_gui->xp_text, (sfVector2f){
        (400 / 2.0 - text_rect.width / 2.0) + 140,
        (40 / 2.0 - text_rect.height / 2.0) + 5
    });
    sfText_setPosition(xp_gui->lvl_text, (sfVector2f){
        (100 / 2.0 - text_rect.width / 2.0) + 20,
        (40 / 2.0 - text_rect.height / 2.0) + 5
    });
}

void update_xp_gui(pirate_quest_t *game)
{
    xp_gui_t *xp_gui = game->xp_gui;
    char xp_str[50];
    char lvl_str[50];
    char xp_goal_str[50];

    if (game->state != GAME_STATE_PLAYING)
        return;
    sprintf(xp_str, "%d/%d", game->player->data->xp.current_xp, 100);
    sprintf(lvl_str, "LVL: %d", game->player->data->xp.current_lvl);
    sprintf(xp_goal_str, "Upgrade: %d", game->player->data->upgrade_points);
    sfText_setString(xp_gui->xp_text, xp_str);
    sfText_setString(xp_gui->lvl_text, lvl_str);
    sfText_setString(xp_gui->upgrade_points, xp_goal_str);
    sfRectangleShape_setSize(xp_gui->xp_bar, (sfVector2f){
        game->player->data->xp.current_xp * 4, 40});
    update_pos(xp_gui);
}

void draw_xp_gui(pirate_quest_t *game)
{
    sfRenderWindow *window = game->window->window;
    xp_gui_t *xp_gui = game->xp_gui;

    if (game->state != GAME_STATE_PLAYING)
        return;
    sfRenderWindow_drawRectangleShape(window, xp_gui->xp_bar_bg, NULL);
    sfRenderWindow_drawRectangleShape(window, xp_gui->xp_bar, NULL);
    sfRenderWindow_drawRectangleShape(window, xp_gui->lvl_bg, NULL);
    sfRenderWindow_drawText(window, xp_gui->xp_text, NULL);
    sfRenderWindow_drawText(window, xp_gui->lvl_text, NULL);
    sfRenderWindow_drawText(window, xp_gui->upgrade_points, NULL);
}

void upgrade_btn_event(pirate_quest_t *game,
    const button_builder_t *button_builder, button_t *button)
{
    game->current_gui = UPGRADE_MENU;
}

int show_upgrade_btn(pirate_quest_t *game,
    const button_builder_t *_, button_t *__)
{
    if (game->state != GAME_STATE_PLAYING)
        return 0;
    if (game->current_gui != IN_GAME)
        return 0;
    return 1;
}
