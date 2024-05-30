/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** player_combat.c
*/

#include "../../include/pirate_quest.h"

static void kill_bos(pirate_quest_t *game)
{
    game->player->data->have_killed_boss = 1;
    save_game(game, game->save);
    add_item(game, WHEEL_ITEM);
}

static void kill_rat(pirate_quest_t *game)
{
    game->player->data->have_killed_rat = 1;
    save_game(game, game->save);
}

void inflict_enemy_damage(pirate_quest_t *game, enemy_t *enemy, float damage)
{
    game->player->is_attacking = 1;
    game->player->rect.left = 0;
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    enemy->health -= damage * (game->player->data->strength_lvl + 1);
    sfSprite_setColor(enemy->sprite, sfRed);
    apply_knockback(game, enemy);
    if (enemy->health <= 0) {
        if (enemy->type == RAT) {
            kill_rat(game);
            return;
        }
        if (enemy->type == BOSS) {
            kill_bos(game);
            return;
        }
        unregister_task(game, enemy->task);
        my_list_remove(game->enemies, enemy);
        add_xp(game, 15);
        enemy->health = 0;
    }
}

void inflict_player_damage(pirate_quest_t *game, float damage)
{
    sfVector2i pos = get_pos_from_phase(game->player->data->phase);

    game->player->health -= damage / (game->player->data->resistance_lvl + 1);
    sfSprite_setColor(game->player->sprite, sfRed);
    if (game->player->health <= 0) {
        game->player->health = 0;
        game->camera->pos_in_tile = (sfVector2f) {0, 0};
        game->camera->map_position = pos;
        update_healthbar(game);
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
