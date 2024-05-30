/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** input_event.c
*/

#include "../../include/pirate_quest.h"
#include "../../include/event.h"

static int rect_contains(pirate_quest_t *game, sfVector2f pos,
    sfVector2i direction, int j)
{
    sfFloatRect rect;

    for (int k = 0; k < RENDER_WIDTH; k++) {
        rect = sfSprite_getGlobalBounds(game->square[0][j][k]->sprite);
        if (!(pos.x >= rect.left && pos.x <= rect.left + rect.width
            && pos.y >= rect.top && pos.y <= rect.top + rect.height))
            continue;
        return game->collision
        [game->camera->map_position.y + j -
            (RENDER_HEIGHT / 2) + direction.y]
        [game->camera->map_position.x + k -
            (RENDER_WIDTH / 2) + direction.x];
    }
    return -2;
}

int is_colid_block(pirate_quest_t *game, sfVector2f pos, sfVector2i direction)
{
    for (int j = 0; j < RENDER_HEIGHT; j++) {
        if (rect_contains(game, pos, direction, j) != -2)
            return rect_contains(game, pos, direction, j);
    }
    return -1;
}

static void go_down(pirate_quest_t *game, float delta_time)
{
    float offset = delta_time / (32.0 * game->camera->zoom);
    sfVector2f pos = (sfVector2f){get_resolution(game).width / 2,
        get_resolution(game).height / 2};

    update_direction(game->player, DOWN);
    game->player->is_moving = 1;
    if (is_colid_block(game, (sfVector2f){pos.x, pos.y + (offset + 4)},
        (sfVector2i){0, 0}) != -1) {
        return;
    }
    game->camera->pos_in_tile.y -= offset;
    if (game->camera->pos_in_tile.y <= -1 * game->camera->zoom) {
        game->camera->pos_in_tile.y = 0;
        game->camera->map_position.y++;
    }
}

static void go_up(pirate_quest_t *game, float delta_time)
{
    float offset = delta_time / (32.0 * game->camera->zoom);
    sfVector2f pos = (sfVector2f){get_resolution(game).width / 2,
        get_resolution(game).height / 2};

    update_direction(game->player, UP);
    game->player->is_moving = 1;
    if (is_colid_block(game, (sfVector2f){pos.x, (pos.y - 4)},
        (sfVector2i){0, 0}) != -1)
        return;
    game->camera->pos_in_tile.y += offset;
    if (game->camera->pos_in_tile.y >= game->camera->zoom) {
        game->camera->pos_in_tile.y = 0;
        game->camera->map_position.y--;
    }
}

static void go_right(pirate_quest_t *game, float delta_time)
{
    float offset = delta_time / (32.0 * game->camera->zoom);
    sfVector2f pos = (sfVector2f){get_resolution(game).width / 2,
        get_resolution(game).height / 2};

    update_direction(game->player, RIGHT);
    game->player->is_moving = 1;
    if (is_colid_block(game, (sfVector2f){pos.x - (offset - 4), pos.y},
        (sfVector2i){0, 0}) != -1)
        return;
    game->camera->pos_in_tile.x -= offset;
    if (game->camera->pos_in_tile.x <= -1 * game->camera->zoom) {
        game->camera->pos_in_tile.x = 0;
        game->camera->map_position.x++;
    }
}

static void go_left(pirate_quest_t *game, float delta_time)
{
    float offset = delta_time / (32.0 * game->camera->zoom);
    sfVector2f pos = (sfVector2f){get_resolution(game).width / 2,
        get_resolution(game).height / 2};

    update_direction(game->player, LEFT);
    game->player->is_moving = 1;
    if (is_colid_block(game, (sfVector2f){pos.x + (offset - 4), pos.y},
        (sfVector2i){0, 0}) != -1)
        return;
    game->camera->pos_in_tile.x += offset;
    if (game->camera->pos_in_tile.x >= game->camera->zoom) {
        game->camera->pos_in_tile.x = 0;
        game->camera->map_position.x--;
    }
}

void key_pressed_event(sfEvent event, pirate_quest_t *game)
{
    if (game->settings_menu->listen_key == sfTrue
        || game->dialogue_service->is_dialogue_playing
        || game->player->is_attacking)
        return;
    if (event.key.code == game->settings->up
        || event.key.code == game->settings->down
        || event.key.code == game->settings->left
        || event.key.code == game->settings->right)
        game->player->is_moving = 1;
}

void key_released_event(sfEvent event, pirate_quest_t *game)
{
    if (game->settings_menu->listen_key == sfTrue) {
        change_setting(game, event.key.code);
        return;
    }
    if (game->dialogue_service->is_dialogue_playing
        || game->player->is_attacking)
        return;
    if (event.key.code == sfKeySpace) {
        game->player->is_moving = 0;
        game->player->is_attacking = 1;
        attack_enemies(game, 25);
        return;
    }
    if (is_other_pressed(game))
        return;
    if (reset_move(game, event))
        game->player->is_moving = 0;
    if (event.key.code == sfKeyEscape)
        input_game_menu(game);
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
    float delta_time = 5.6 * game->camera->zoom / 2.5;
    float delta_time_d = 8 * game->camera->zoom / 2.5;

    if (game->settings_menu->listen_key == sfTrue
    || game->dialogue_service->is_dialogue_playing
    || game->player->is_attacking)
        return;
    if (sfKeyboard_isKeyPressed(game->settings->down))
        go_down(game, is_corner(game) ? delta_time : delta_time_d);
    if (sfKeyboard_isKeyPressed(game->settings->up))
        go_up(game, is_corner(game) ? delta_time : delta_time_d);
    if (sfKeyboard_isKeyPressed(game->settings->left))
        go_left(game, is_corner(game) ? delta_time : delta_time_d);
    if (sfKeyboard_isKeyPressed(game->settings->right))
        go_right(game, is_corner(game) ? delta_time : delta_time_d);
}
