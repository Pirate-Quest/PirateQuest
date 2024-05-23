/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** back_button.c
*/

#include "../../../include/pirate_quest.h"

int show_back_btn(pirate_quest_t *game,
    const button_builder_t *_, button_t *__)
{
    return game->current_gui == SAVE_MENU || game->current_gui == SETTINGS_MENU
        && game->state != GAME_STATE_MENU;
}

void back_btn_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_)
{
    if (button->text == NULL)
        return;
    if (game->current_gui == SETTINGS_MENU && game->state == GAME_STATE_MENU)
        game->current_gui = MAIN_MENU;
    if (game->current_gui == SETTINGS_MENU)
        game->current_gui = GAME_MENU;
    if (game->current_gui == SAVE_MENU)
        game->current_gui = MAIN_MENU;
}
