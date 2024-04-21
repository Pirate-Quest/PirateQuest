/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** input_event.c
*/

#include "../../include/pirate_quest.h"
#include "../../include/event.h"
#include <stdarg.h>

static void go_down(pirate_quest_t *game, float delta_time)
{
    update_direction(game->player, DOWN);
    game->camera->pos_in_tile.y -= delta_time / (32.0 * game->camera->zoom);
    if (game->camera->pos_in_tile.y <= -1 * game->camera->zoom) {
        game->camera->pos_in_tile.y = 0;
        game->camera->map_position.y++;
    }
}

static void go_up(pirate_quest_t *game, float delta_time)
{
    update_direction(game->player, UP);
    game->camera->pos_in_tile.y += delta_time / (32.0 * game->camera->zoom);
    if (game->camera->pos_in_tile.y >= game->camera->zoom) {
        game->camera->pos_in_tile.y = 0;
        game->camera->map_position.y--;
    }
}

static void go_right(pirate_quest_t *game, float delta_time)
{
    update_direction(game->player, RIGHT);
    game->camera->pos_in_tile.x -= delta_time / (32.0 * game->camera->zoom);
    if (game->camera->pos_in_tile.x <= -1 * game->camera->zoom) {
        game->camera->pos_in_tile.x = 0;
        game->camera->map_position.x++;
    }
}

static void go_left(pirate_quest_t *game, float delta_time)
{
    update_direction(game->player, LEFT);
    game->camera->pos_in_tile.x += delta_time / (32.0 * game->camera->zoom);
    if (game->camera->pos_in_tile.x >= game->camera->zoom) {
        game->camera->pos_in_tile.x = 0;
        game->camera->map_position.x--;
    }
}

void key_pressed_event(sfEvent event, pirate_quest_t *game)
{
    if (event.key.code == game->settings->up
        || event.key.code == game->settings->down
        || event.key.code == game->settings->left
        || event.key.code == game->settings->right)
        game->player->is_moving = 1;
}

void key_released_event(sfEvent event, pirate_quest_t *game)
{
    if (event.key.code == game->settings->up
        || event.key.code == game->settings->down
        || event.key.code == game->settings->left
        || event.key.code == game->settings->right)
        game->player->is_moving = 0;
}

int is_corner(pirate_quest_t *game)
{
    if (sfKeyboard_isKeyPressed(game->settings->up)
        && sfKeyboard_isKeyPressed(game->settings->left))
        return TRUE;
    if (sfKeyboard_isKeyPressed(game->settings->up)
        && sfKeyboard_isKeyPressed(game->settings->right))
        return TRUE;
    if (sfKeyboard_isKeyPressed(game->settings->down)
        && sfKeyboard_isKeyPressed(game->settings->left))
        return TRUE;
    if (sfKeyboard_isKeyPressed(game->settings->down)
        && sfKeyboard_isKeyPressed(game->settings->right))
        return TRUE;
    return FALSE;
}

void update_key_pressed(pirate_quest_t *game)
{
    if (sfKeyboard_isKeyPressed(game->settings->down))
        go_down(game, is_corner(game) ? 2.8 : 4);
    if (sfKeyboard_isKeyPressed(game->settings->up))
        go_up(game, is_corner(game) ? 2.8 : 4);
    if (sfKeyboard_isKeyPressed(game->settings->left))
        go_left(game, is_corner(game) ? 2.8 : 4);
    if (sfKeyboard_isKeyPressed(game->settings->right))
        go_right(game, is_corner(game) ? 2.8 : 4);
}
