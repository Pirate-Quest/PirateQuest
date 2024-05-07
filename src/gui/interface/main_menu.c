/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** main_menu.c
*/

#include <SFML/Graphics.h>
#include "../../../include/pirate_quest.h"

int show_main_menu_btns(pirate_quest_t *game,
    const button_builder_t *_, button_t *__)
{
    return game->state == GAME_STATE_MENU;
}

void init_main_menu(pirate_quest_t *game)
{
    resolution_t resolution = get_resolution(game);

    game->main_menu = malloc(sizeof(main_menu_t));
    game->main_menu->background = sfSprite_create();
    game->main_menu->background_texture = sfTexture_createFromFile(
        "assets/background.png", NULL);
    sfSprite_setTexture(game->main_menu->background,
        game->main_menu->background_texture, sfTrue);
    sfSprite_setPosition(game->main_menu->background, (sfVector2f){0, 0});
    sfSprite_setScale(game->main_menu->background, (sfVector2f){
        (float) resolution.width / 1920, (float) resolution.height / 1080});
}

void update_main_menu(pirate_quest_t *game)
{
    sfRenderWindow_drawSprite(game->window->window,
        game->main_menu->background, NULL);
}
