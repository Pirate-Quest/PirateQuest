/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** input_event2
*/

#include "../../include/pirate_quest.h"

int is_other_pressed(pirate_quest_t *game)
{
    if (sfKeyboard_isKeyPressed(game->settings->up) == 1
        || sfKeyboard_isKeyPressed(game->settings->down) == 1
        || sfKeyboard_isKeyPressed(game->settings->left) == 1
        || sfKeyboard_isKeyPressed(game->settings->right) == 1
        || sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
        return 1;
    return 0;
}

int reset_move(pirate_quest_t *game, sfEvent event)
{
    if (game->current_gui == IN_GAME && event.key.code == game->settings->up
        || event.key.code == game->settings->down
        || event.key.code == game->settings->left
        || event.key.code == game->settings->right)
        return 1;
    return 0;
}
