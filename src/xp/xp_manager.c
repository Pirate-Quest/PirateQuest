/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** xp_manager.c
*/

#include "../../include/pirate_quest.h"

void add_xp(pirate_quest_t *game, unsigned int amount)
{
    game->player->data->xp.current_xp += amount;
    if (game->player->data->xp.current_xp >= 100) {
        game->player->data->xp.current_xp -= 100;
        game->player->data->xp.current_lvl++;
        game->player->data->upgrade_points += 2;
    }
}
