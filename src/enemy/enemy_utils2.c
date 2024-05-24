/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** enemy_utils2.c
*/

#include "../../include/pirate_quest.h"

void apply_knockback(pirate_quest_t *game, enemy_t *enemy)
{
    sfVector2f pos = sfSprite_getPosition(enemy->sprite);
    sfVector2f pos_goal = sfSprite_getPosition(game->player->sprite);
    sfVector2f diff = {pos_goal.x - pos.x, pos_goal.y - pos.y};

    if (diff.x > 0.0)
        enemy->pos_in_tile.x -= 16 * game->camera->zoom;
    if (diff.x < 0.0)
        enemy->pos_in_tile.x += 16 * game->camera->zoom;
    if (diff.y > 0.0)
        enemy->pos_in_tile.y -= 16 * game->camera->zoom;
    if (diff.y < 0.0)
        enemy->pos_in_tile.y += 16 * game->camera->zoom;
}
