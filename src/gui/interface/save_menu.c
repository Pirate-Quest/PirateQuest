/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** save_menu.c
*/

#include "../../../include/pirate_quest.h"

int show_save_menu_btns(pirate_quest_t *game,
    const button_builder_t *_, button_t *__)
{
    return game->state == GAME_STATE_MENU && game->current_gui == SAVE_MENU;
}

void save_menu_btns_event(pirate_quest_t *game,
    button_builder_t *button, button_t *_)
{
    if (button->text == NULL)
        return;
    load_game(game, button->text);
}
