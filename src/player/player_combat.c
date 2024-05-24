/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** player_combat.c
*/

#include "../../include/pirate_quest.h"

void inflict_enemy_damage(pirate_quest_t *game, enemy_t *enemy, float damage)
{
    enemy->health -= damage * game->player->data->strength_lvl;
    sfSprite_setColor(enemy->sprite, sfRed);
    if (enemy->health <= 0) {
        unregister_task(game, enemy->task);
        my_list_remove(game->enemies, enemy);
    }
}

void attack_enemies(pirate_quest_t *game, float damage)
{
    my_list_node_t *node;
    my_list_node_t *temp;

    if (game->enemies == NULL)
        return;
    if (my_list_size(game->enemies) < 1)
        return;
    node = game->enemies->head;
    while (node) {
        temp = node;
        node = node->next;
        if (distance_between_points(sfSprite_getPosition(
            ((enemy_t *)temp->data)->sprite),
            sfSprite_getPosition(game->player->sprite)) > 32
            * game->camera->zoom * 1.2)
            continue;
        inflict_enemy_damage(game, (enemy_t *)temp->data, damage);
    }
}
