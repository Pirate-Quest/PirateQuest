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

void update_enemies_sprite_resolution(pirate_quest_t *game)
{
    my_list_node_t *node;
    my_list_node_t *temp;

    if (game->enemies == NULL)
        return;
    node = game->enemies->head;
    while (node) {
        temp = node;
        node = node->next;
        if ((enemy_t *)temp->data == NULL
            || ((enemy_t *)temp->data)->sprite == NULL)
            continue;
        sfSprite_setScale(((enemy_t *)temp->data)->sprite, (sfVector2f){
            2 * game->camera->zoom
            / 2.5, 2 * game->camera->zoom / 2.5});
    }
}
