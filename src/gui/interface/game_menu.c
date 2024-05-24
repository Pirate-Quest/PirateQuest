/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** game_menu.c
*/

#include "../../../include/pirate_quest.h"

int show_game_menu_btns(pirate_quest_t *game,
    const button_builder_t *_, button_t *__)
{
    if (game->current_gui != GAME_MENU || game->state != GAME_STATE_PLAYING)
        return 0;
    return 1;
}

void init_game_menu(pirate_quest_t *game)
{
    resolution_t res = get_resolution(game);
    const float scale = 0.3;

    game->game_menu = malloc(sizeof(main_menu_t));
    game->game_menu->background = sfSprite_create();
    game->game_menu->background_texture = sfTexture_createFromFile(
        "assets/game_menu_bg.png", NULL);
    sfSprite_setTexture(game->game_menu->background,
        game->game_menu->background_texture, sfTrue);
    sfSprite_setPosition(game->game_menu->background,
        (sfVector2f){(res.width / 2) - 1987 * scale / 2, (res.height / 2) - 2323 * scale / 2});
    sfSprite_setScale(game->game_menu->background, (sfVector2f){scale, scale});
}

void input_game_menu(pirate_quest_t *game)
{
    if (game->state != GAME_STATE_PLAYING)
        return;
    if (game->current_gui == GAME_MENU)
        game->current_gui = IN_GAME;
    if (game->current_gui == IN_GAME)
        game->current_gui = GAME_MENU;
}

void show_game_menu(pirate_quest_t *game)
{
    if (!game->game_menu || game->current_gui != GAME_MENU)
        return;
    sfRenderWindow_drawSprite(game->window->window,
        game->game_menu->background, NULL);
}
