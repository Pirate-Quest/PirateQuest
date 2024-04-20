/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** input_event.c
*/

#include "../../include/pirate_quest.h"
#include "../../include/event.h"

static void go_down(pirate_quest_t *game)
{
    update_direction(game->player, DOWN);
    game->camera->pos_in_tile.y -= 16 / (32.0 * game->camera->zoom);
    if (game->camera->pos_in_tile.y <= -1 * game->camera->zoom) {
        game->camera->pos_in_tile.y = 0;
        game->camera->map_position.y++;
    }
}

static void go_up(pirate_quest_t *game)
{
    update_direction(game->player, UP);
    game->camera->pos_in_tile.y += 16 / (32.0 * game->camera->zoom);
    if (game->camera->pos_in_tile.y >= game->camera->zoom) {
        game->camera->pos_in_tile.y = 0;
        game->camera->map_position.y--;
    }
}

static void go_right(pirate_quest_t *game)
{
    update_direction(game->player, RIGHT);
    game->camera->pos_in_tile.x -= 16 / (32.0 * game->camera->zoom);
    if (game->camera->pos_in_tile.x <= -1 * game->camera->zoom) {
        game->camera->pos_in_tile.x = 0;
        game->camera->map_position.x++;
    }
}

static void go_left(pirate_quest_t *game)
{
    update_direction(game->player, LEFT);
    game->camera->pos_in_tile.x += 16 / (32.0 * game->camera->zoom);
    if (game->camera->pos_in_tile.x >= game->camera->zoom) {
        game->camera->pos_in_tile.x = 0;
        game->camera->map_position.x--;
    }
}

void key_pressed_event(sfEvent event, pirate_quest_t *game)
{
    if (event.key.code == game->settings->up)
        go_up(game);
    if (event.key.code == game->settings->down)
        go_down(game);
    if (event.key.code == game->settings->left)
        go_left(game);
    if (event.key.code == game->settings->right)
        go_right(game);
}
