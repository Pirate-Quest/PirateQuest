/*
** EPITECH PROJECT, 2024
** Pirate
** File description:
** settings_menu
*/

#include "../../../include/pirate_quest.h"

int show_settings_menu_btns(pirate_quest_t *game,
    const button_builder_t *_, button_t *__)
{
    if (game->current_gui != SETTINGS_MENU ||
        game->state == GAME_STATE_TRANSITION)
        return 0;
    return 1;
}

static void change_key_bind(pirate_quest_t *game, int setting_nb)
{
    // setting nb : 1 UP, 2 Down, 3 Left, 4 Right, 5 Attack, 6 Resolution

}

void settings_menu_btns_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_)
{
    if (button->text == NULL || game->current_gui == SETTINGS_MENU)
        return;
    if (my_strcmp(button->text, "Up") == 0)
       change_key_bind(game, 1);
    if (my_strcmp(button->text, "Down") == 0)
       change_key_bind(game, 2);
    if (my_strcmp(button->text, "Left") == 0)
       change_key_bind(game, 3);
    if (my_strcmp(button->text, "Right") == 0)
       change_key_bind(game, 4);
    if (my_strcmp(button->text, "Attack") == 0)
       change_key_bind(game, 5);
    if (my_strcmp(button->text, "Resolution") == 0)
       change_key_bind(game, 6);
}

void init_settings_menu(pirate_quest_t *game)
{
    resolution_t resolution = get_resolution(game);

    game->settings_menu = malloc(sizeof(main_menu_t));
    game->settings_menu->background = sfSprite_create();
    game->settings_menu->background_texture = sfTexture_createFromFile(
        "assets/background.png", NULL);
    sfSprite_setTexture(game->settings_menu->background,
        game->settings_menu->background_texture, sfTrue);
    sfSprite_setPosition(game->settings_menu->background, (sfVector2f){0, 0});
    sfSprite_setScale(game->settings_menu->background, (sfVector2f){
        (float) resolution.width / 1920, (float) resolution.height / 1080});
}

void update_settings_menu(pirate_quest_t *game)
{
    if (!game->settings_menu || game->current_gui != SETTINGS_MENU)
        return;
    sfRenderWindow_drawSprite(game->window->window,
        game->game_menu->background, NULL);
}
