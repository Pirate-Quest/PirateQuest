/*
** EPITECH PROJECT, 2024
** Pirate
** File description:
** game_menu_buttons
*/

#include "../../../include/pirate_quest.h"

void game_menu_resume_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_)
{
    if (button->text == NULL)
        return;
    game->current_gui = IN_GAME;
}

void game_menu_save_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_)
{
    if (button->text == NULL)
        return;
    // TODO save function
}

void game_menu_settings_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_)
{
    if (button->text == NULL)
        return;
    game->current_gui = SETTINGS_MENU;
}

void game_menu_exit_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_)
{
    if (button->text == NULL)
        return;
    game->current_gui = MAIN_MENU;
    game->state = GAME_STATE_MENU;
}