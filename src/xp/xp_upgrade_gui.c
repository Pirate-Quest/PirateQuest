/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** xp_upgrade_gui.c
*/

#include "../../include/pirate_quest.h"
#include <stdlib.h>

static void init_text(pirate_quest_t *game)
{
    char txt[50];

    sprintf(txt, "Upgrade Points: %d", game->player->data->upgrade_points);
    game->xp_upgrade_gui->upgrade_points = sfText_create();
    sfText_setFont(game->xp_upgrade_gui->upgrade_points, game->xp_gui->font);
    sfText_setCharacterSize(game->xp_upgrade_gui->upgrade_points, 35);
    sfText_setPosition(game->xp_upgrade_gui->upgrade_points,
        (sfVector2f){550, 200});
    sfText_setString(game->xp_upgrade_gui->upgrade_points, txt);
    sfText_setFillColor(game->xp_upgrade_gui->upgrade_points, sfBlack);
}

static void update_all(pirate_quest_t *game)
{
    char txt[50];

    sprintf(txt, "Upgrade Points: %d", game->player->data->upgrade_points);
    sfText_setString(game->xp_upgrade_gui->upgrade_points, txt);
}

static void init_stats_text(pirate_quest_t *game,
    sfText *text, char *str, sfVector2f pos)
{
    sfText_setFont(text, game->xp_gui->font);
    sfText_setCharacterSize(text, 25);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfText_setFillColor(text, sfBlack);
}

static sfIntRect get_rect(int level)
{
    sfIntRect rect = {0, 0, 1615, 231};

    rect.top = 231 * level;
    return rect;
}

static void init_sprite(pirate_quest_t *game,
    sfSprite *sprite, sfVector2f pos, sfTexture *texture)
{
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, (sfVector2f){0.2, 0.2});
}

void init_xp_upgrade_gui(pirate_quest_t *game)
{
    sfTexture *texture = sfTexture_createFromFile(
        "assets/upgrade_bar.png", NULL);

    game->xp_upgrade_gui = malloc(sizeof(xp_upgrade_gui_t));
    init_text(game);
    game->xp_upgrade_gui->resistance_upgrade = sfText_create();
    game->xp_upgrade_gui->strength_upgrade = sfText_create();
    init_stats_text(game, game->xp_upgrade_gui->resistance_upgrade,
        "Resistance", (sfVector2f){470, 300});
    init_stats_text(game, game->xp_upgrade_gui->strength_upgrade,
        "Strength", (sfVector2f){470, 450});
    game->xp_upgrade_gui->resistance_upgrade_sprite = sfSprite_create();
    init_sprite(game, game->xp_upgrade_gui->resistance_upgrade_sprite,
        (sfVector2f){470, 350}, texture);
    game->xp_upgrade_gui->strength_upgrade_sprite = sfSprite_create();
    init_sprite(game, game->xp_upgrade_gui->strength_upgrade_sprite,
        (sfVector2f){470, 500}, texture);
}

void draw_xp_upgrade_gui(pirate_quest_t *game)
{
    if (game->current_gui != UPGRADE_MENU)
        return;
    update_all(game);
    sfSprite_setTextureRect(game->xp_upgrade_gui->resistance_upgrade_sprite,
        get_rect(game->player->data->resistance_lvl));
    sfSprite_setTextureRect(game->xp_upgrade_gui->strength_upgrade_sprite,
        get_rect(game->player->data->strength_lvl));
    sfRenderWindow_drawSprite(game->window->window,
        game->game_menu->background, NULL);
    sfRenderWindow_drawText(game->window->window,
        game->xp_upgrade_gui->upgrade_points, NULL);
    sfRenderWindow_drawText(game->window->window,
        game->xp_upgrade_gui->resistance_upgrade, NULL);
    sfRenderWindow_drawText(game->window->window,
        game->xp_upgrade_gui->strength_upgrade, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->xp_upgrade_gui->resistance_upgrade_sprite, NULL);
    sfRenderWindow_drawSprite(game->window->window,
        game->xp_upgrade_gui->strength_upgrade_sprite, NULL);
}

void upgrade_btn_lvl_event1(pirate_quest_t *game,
    const button_builder_t *button_builder, button_t *button)
{
    if (button->text == NULL)
        return;
    if (game->player->data->upgrade_points <= 0)
        return;
    game->player->data->resistance_lvl += 1;
    game->player->data->upgrade_points -= 1;
}

void upgrade_btn_lvl_event2(pirate_quest_t *game,
    const button_builder_t *button_builder, button_t *button)
{
    if (button->text == NULL)
        return;
    if (game->player->data->upgrade_points <= 0)
        return;
    game->player->data->strength_lvl += 1;
    game->player->data->upgrade_points -= 1;
}

int show_upgrade_lvl_btn(pirate_quest_t *game,
    const button_builder_t *_, button_t *__)
{
    return game->state == GAME_STATE_PLAYING
        && game->current_gui == UPGRADE_MENU;
}
