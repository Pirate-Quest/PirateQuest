/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** main_menu.c
*/

#include "../../../include/pirate_quest.h"

int show_main_menu_btns(pirate_quest_t *game,
    const button_builder_t *_, button_t *__)
{
    return game->state == GAME_STATE_MENU && game->current_gui == MAIN_MENU;
}

void main_menu_btns_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_)
{
    if (button->text == NULL)
        return;
    if (my_strcmp(button->text, "Play") == 0) {
        game->current_gui = SAVE_MENU;
    }
    if (my_strcmp(button->text, "Settings") == 0) {
        game->current_gui = SETTINGS_MENU;
    }
    if (my_strcmp(button->text, "Exit") == 0) {
        sfRenderWindow_close(game->window->window);
    }
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
    if (game->main_menu == NULL || game->state != GAME_STATE_MENU)
        return;
    sfRenderWindow_drawSprite(game->window->window,
        game->main_menu->background, NULL);
}
