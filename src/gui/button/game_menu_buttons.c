/*
** EPITECH PROJECT, 2024
** Pirate
** File description:
** game_menu_buttons
*/

#include "../../../include/pirate_quest.h"

void game_menu_resume(pirate_quest_t *game,
    const button_builder_t *button, button_t *_)
{
    game->current_gui = IN_GAME;
}

void game_menu_save(pirate_quest_t *game,
    const button_builder_t *button, button_t *_)
{
    game->current_gui = SAVE_MENU;
}

void game_menu_settings(pirate_quest_t *game,
    const button_builder_t *button, button_t *_)
{
    game->current_gui = SETTINGS_MENU;
}

void game_menu_exit(pirate_quest_t *game,
    const button_builder_t *button, button_t *_)
{
    game->current_gui = MAIN_MENU;
    game->state = GAME_STATE_MENU;
}