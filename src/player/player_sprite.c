/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** player_sprite.c
*/

#include "../../include/pirate_quest.h"

const task_builder_t task = {
    .on_tick = &on_player_tick,
    .on_end = NULL,
    .second_interval = 0.1,
    .execution_count = -1
};

int on_player_tick(pirate_quest_t *game, void *_, int exec_count)
{
    if (game->player->is_attacking && game->player->is_moving) {
        game->player->is_attacking = 0;
    }
    if (game->player->is_attacking == 1) {
        game->player->rect.top = (game->player->direction + 4) * 128 + 46 * 64;
        if (move_rect(&game->player->rect, 128, 0, 128 * 6) == 1) {
            game->player->is_attacking = 0;
            game->player->rect.left = 0;
            return 0;
        }
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
        return 0;
    }
    if (game->player->is_moving == 0)
        return 0;
    game->player->rect.top = (game->player->direction * 128) + 46 * 64;
    move_rect(&game->player->rect, 128, 128, 128 * 9);
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    return 0;
}

player_t *init_player(pirate_quest_t *game)
{
    player_t *player = malloc(sizeof(player_t));

    player->pos = (sfVector2f){get_resolution(game).width / 2,
        (get_resolution(game).height / 2) - 20};
    player->is_moving = 0;
    player->is_attacking = 0;
    player->rect = (sfIntRect){0, (DOWN * 128) + 46 * 64, 128, 128};
    player->texture = sfTexture_createFromFile("assets/player.png", NULL);
    player->sprite = sfSprite_create();
    sfSprite_setOrigin(player->sprite, (sfVector2f){64, 64 + 15});
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setScale(player->sprite, (sfVector2f){2 * game->camera->zoom
        / 2.5, 2 * game->camera->zoom / 2.5});
    update_direction(player, DOWN);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, player->pos);
    player->task = register_task(
        game, &task, NULL);
    player->data = malloc(sizeof(player_data_t));
    return player;
}

int update_player(pirate_quest_t *game)
{
    if ((game->player->is_moving == 0 && game->player->is_attacking == 0)
        || game->dialogue_service->is_dialogue_playing) {
        game->player->rect.left = 0;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
        sfRenderWindow_drawSprite(game->window->window,
            game->player->sprite, NULL);
        return 0;
    }
    sfSprite_setPosition(game->player->sprite, game->player->pos);
    sfRenderWindow_drawSprite(game->window->window,
        game->player->sprite, NULL);
    return 0;
}

void update_direction(player_t *player, direction_t direction)
{
    player->direction = direction;
    sfSprite_setTextureRect(player->sprite, player->rect);
}
