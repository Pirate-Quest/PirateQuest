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
    return game->current_gui == MAIN_MENU && game->state != GAME_STATE_MENU;
}

void back_btn_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_)
{
    if (button->text == NULL)
        return;
    if (my_strcmp(button->text, "Back") == 0) {
        game->current_gui = MAIN_MENU;
    }
}
