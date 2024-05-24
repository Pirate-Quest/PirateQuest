/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** enemy_utils.c
*/

#include "../../include/pirate_quest.h"

sfVector2i get_random_pos(pirate_quest_t *game)
{
    int min_x = game->square[0][0][0]->pos.x;
    int max_x = game->square[0][0][RENDER_WIDTH - 1]->pos.x;
    int x = rand() % (max_x - min_x + 1) + min_x;
    int min_y = game->square[0][0][0]->pos.y;
    int max_y = game->square[0][RENDER_HEIGHT - 1][0]->pos.y;
    int y = rand() % (max_y - min_y + 1) + min_y;

    return (sfVector2i){x, y};
}

direction_t get_best_attack_direction(pirate_quest_t *game, enemy_t *enemy)
{
    sfVector2f pos = sfSprite_getPosition(enemy->sprite);
    sfVector2f pos_goal = sfSprite_getPosition(game->player->sprite);
    sfVector2f diff = {pos_goal.x - pos.x, pos_goal.y - pos.y};

    if (diff.y > 0.0 && (diff.x > -10 && diff.x < 10))
        return DOWN;
    if (diff.y < 0.0 && (diff.x > -10 && diff.x < 10))
        return UP;
    if (diff.x > 0.0)
        return RIGHT;
    if (diff.x < 0.0)
        return LEFT;
    return RIGHT;
}

void free_enemy(void *data)
{
    enemy_t *enemy = (enemy_t *)data;

    sfSprite_destroy(enemy->sprite);
    free(enemy);
}

static void update_enemy_position_x(pirate_quest_t *game,
    enemy_t *enemy, float diff_x)
{
    if (diff_x > 0.0) {
        enemy->direction = RIGHT;
        enemy->pos_in_tile.x += 2;
        if (enemy->pos_in_tile.x >= 32 * game->camera->zoom) {
            enemy->pos_in_tile.x = 0;
            enemy->square_pos.x += 1;
            update_pos_goal(game, enemy);
        }
        return;
    }
    if (diff_x < 0.0) {
        enemy->direction = LEFT;
        enemy->pos_in_tile.x -= 2;
        if (enemy->pos_in_tile.x <= -32 * game->camera->zoom) {
            enemy->pos_in_tile.x = 0;
            enemy->square_pos.x -= 1;
            update_pos_goal(game, enemy);
        }
    }
}

static void update_enemy_position_y(pirate_quest_t *game,
    enemy_t *enemy, float diff_y)
{
    if (diff_y > 0.0) {
        enemy->pos_in_tile.y += 2;
        if (enemy->pos_in_tile.y >= 32 * game->camera->zoom) {
            enemy->pos_in_tile.y = 0;
            enemy->square_pos.y += 1;
            update_pos_goal(game, enemy);
        }
        return;
    }
    if (diff_y < 0.0) {
        enemy->pos_in_tile.y -= 2;
        if (enemy->pos_in_tile.y <= -32 * game->camera->zoom) {
            enemy->pos_in_tile.y = 0;
            enemy->square_pos.y -= 1;
            update_pos_goal(game, enemy);
        }
    }
}

void move_enemy(pirate_quest_t *game, enemy_t *enemy)
{
    sfVector2f pos = sfSprite_getPosition(enemy->sprite);
    sfVector2f pos_goal = sfSprite_getPosition(game->player->sprite);
    sfVector2f diff = {pos_goal.x - pos.x, pos_goal.y - pos.y};

    update_enemy_position_x(game, enemy, diff.x);
    update_enemy_position_y(game, enemy, diff.y);
}

void update_pos_goal(pirate_quest_t *game, enemy_t *enemy)
{
    sfVector2i goal = game->camera->map_position;
    int min_x = goal.x - 1;
    int max_x = goal.x + 1;
    int min_y = goal.y - 1;
    int max_y = goal.y + 1;
    float min_in_tile_x = -32 * game->camera->zoom;
    float max_in_tile_x = 32 * game->camera->zoom;
    float min_in_tile_y = -32 * game->camera->zoom;
    float max_in_tile_y = 32 * game->camera->zoom;

    if (enemy->super_pos_goal.x == goal.x && enemy->super_pos_goal.y == goal.y)
        return;
    enemy->super_pos_goal = goal;
    enemy->pos_goal = get_square(game, (sfVector2i){rand() % (max_x - min_x
    + 1) + min_x, rand() % (max_y - min_y + 1) + min_y})->pos;
    enemy->pos_in_tile_goal = (sfVector2f){rand() % (int)(max_in_tile_x -
    min_in_tile_x + 1) + min_in_tile_x, rand() % (int)(max_in_tile_y -
    min_in_tile_y + 1) + min_in_tile_y};
}
