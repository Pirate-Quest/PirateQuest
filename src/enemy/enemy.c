/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** enemy.c
*/

#include "../../include/pirate_quest.h"

const task_builder_t enemy_task = {
    .on_tick = &on_enemy_tick,
    .on_end = NULL,
    .second_interval = 0.1,
    .execution_count = -1
};

int on_enemy_tick(pirate_quest_t *game, void *data, int _)
{
    enemy_t *enemy = (enemy_t *)data;

    if (sfSprite_getColor(enemy->sprite).r == 255)
        sfSprite_setColor(enemy->sprite, sfWhite);
    if (enemy->is_moving == 0) {
        enemy->direction = get_best_attack_direction(game, enemy);
        move_rect(&enemy->rect, 192, 192, 192 * 6);
        sfSprite_setTextureRect(enemy->sprite, enemy->rect);
        return 0;
    }
    move_rect(&enemy->rect, 64, 64, 64 * 9);
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    return 0;
}

static void init_enemy_sprite(pirate_quest_t *game, enemy_t *enemy)
{
    enemy->sprite = sfSprite_create();
    sfSprite_setOrigin(enemy->sprite, (sfVector2f){32, 32 + 15});
    sfSprite_setTexture(enemy->sprite, game->enemy_texture, sfTrue);
    sfSprite_setScale(enemy->sprite, (sfVector2f){2 * game->camera->zoom
        / 2.5, 2 * game->camera->zoom / 2.5});
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    sfSprite_setPosition(enemy->sprite, enemy->pos);
}

enemy_t *init_enemy(pirate_quest_t *game)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    enemy->square_pos = get_random_pos(game);
    enemy->pos_in_tile = (sfVector2f){0, 0};
    enemy->pos = sfSprite_getPosition(
        get_square(game, enemy->square_pos)->sprite);
    enemy->super_pos_goal = (sfVector2i){-1, -1};
    enemy->pos_goal = (sfVector2i){-1, -1};
    update_pos_goal(game, enemy);
    enemy->is_moving = 0;
    enemy->attacking = 0;
    enemy->rect = (sfIntRect){0, 0, 64, 64};
    init_enemy_sprite(game, enemy);
    enemy->task = register_task(game, &enemy_task, enemy);
    enemy->direction = RIGHT;
    enemy->health = 100;
    my_list_add(game->enemies, enemy);
    return enemy;
}

static void update_attack(pirate_quest_t *game, enemy_t *enemy)
{
    enemy->rect.left = 0;
    enemy->is_moving = 0;
    enemy->rect.width = 192;
    enemy->rect.height = 192;
    enemy->rect.top = (enemy->direction * 192) + (46 * 64);
    enemy->direction = get_best_attack_direction(game, enemy);
    sfSprite_setOrigin(enemy->sprite, (sfVector2f){192 / 2, 192 / 2 + 15});
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    sfRenderWindow_drawSprite(game->window->window, enemy->sprite, NULL);
}

static void update_walk(pirate_quest_t *game, enemy_t *enemy)
{
    enemy->rect.left = 0;
    enemy->is_moving = 1;
    enemy->rect.width = 64;
    enemy->rect.height = 64;
    enemy->rect.top = (enemy->direction * 64) + (8 * 64);
    sfSprite_setOrigin(enemy->sprite, (sfVector2f){64 / 2, 64 / 2 + 15});
    sfSprite_setTextureRect(enemy->sprite, enemy->rect);
    sfRenderWindow_drawSprite(game->window->window, enemy->sprite, NULL);
}

int remove_enemy(pirate_quest_t *game, enemy_t *enemy)
{
    unregister_task(game, enemy->task);
    my_list_remove(game->enemies, enemy);
    return 0;
}

static void update_epos(pirate_quest_t *game, enemy_t *enemy)
{
    sfVector2f pos = sfSprite_getPosition(
        get_square(game, enemy->square_pos)->sprite
    );

    sfSprite_setPosition(enemy->sprite, (sfVector2f){
        pos.x + enemy->pos_in_tile.x,
        pos.y + enemy->pos_in_tile.y
    });
}

int update_enemy(pirate_quest_t *game, enemy_t *enemy)
{
    if (get_square(game, enemy->square_pos) == NULL)
        return remove_enemy(game, enemy);
    update_epos(game, enemy);
    update_pos_goal(game, enemy);
    if (distance_between_points(sfSprite_getPosition(enemy->sprite),
        sfSprite_getPosition(game->player->sprite))
        < 32 * game->camera->zoom * 1.2) {
        if (enemy->is_moving)
            update_attack(game, enemy);
        enemy->rect.top = (enemy->direction * 192) + (46 * 64);
    } else {
        if (!enemy->is_moving)
            update_walk(game, enemy);
        enemy->rect.top = (enemy->direction * 64) + (8 * 64);
        move_enemy(game, enemy);
    }
    sfRenderWindow_drawSprite(game->window->window, enemy->sprite, NULL);
    return 0;
}

void update_enemies(pirate_quest_t *game)
{
    my_list_node_t *node;
    my_list_node_t *temp;

    if (game->enemies == NULL)
        return;
    while (my_list_size(game->enemies) < 1)
        init_enemy(game);
    if (my_list_size(game->enemies) < 1)
        return;
    node = game->enemies->head;
    while (node) {
        temp = node;
        node = node->next;
        if ((enemy_t *)temp->data == NULL
        || ((enemy_t *)temp->data)->sprite == NULL)
            continue;
        update_enemy(game, (enemy_t *)temp->data);
    }
}
