/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** game_menu.c
*/

#include "../../../include/pirate_quest.h"

void init_game_menu(pirate_quest_t *game)
{
    resolution_t res = get_resolution(game);

    game->game_menu = malloc(sizeof(main_menu_t));
    game->game_menu->background = sfSprite_create();
    game->game_menu->background_texture = sfTexture_createFromFile(
        "assets/game_menu_bg.png", NULL);
    sfSprite_setTexture(game->game_menu->background,
        game->game_menu->background_texture, sfTrue);
    sfSprite_setPosition(game->game_menu->background,
        (sfVector2f){res.width / 4, 0});
    sfSprite_setScale(game->game_menu->background, (sfVector2f){
        (float) res.width / 3840, (float) res.height / 2160});
}

void input_game_menu(pirate_quest_t *game)
{
    if (game->current_gui == GAME_MENU)
        game->current_gui = IN_GAME;
    else
        game->current_gui = GAME_MENU;
}

void show_game_menu(pirate_quest_t *game)
{
    printf("game->current_gui state : %d\n", game->current_gui);
    if (!game->game_menu || game->current_gui != GAME_MENU)
        return;
    printf("GAME MENU\n");
    sfRenderWindow_drawSprite(game->window->window,
        game->game_menu->background, NULL);
}
