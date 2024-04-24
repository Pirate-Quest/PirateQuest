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

int on_player_tick(pirate_quest_t *game, hashtable_t *_)
{
    if (game->player->is_moving == 0)
        return 0;
    move_rect(&game->player->rect, 64, 64, 64 * 9);
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    return 0;
}

player_t *init_player(pirate_quest_t *game)
{
    player_t *player = malloc(sizeof(player_t));

    player->pos = (sfVector2f){get_resolution(0).width / 2,
        (get_resolution(0).height / 2) - 10};
    player->is_moving = 0;
    player->size = (sfVector2f){64, 64};
    player->rect = (sfIntRect){0, 0, 64, 64};
    player->texture = sfTexture_createFromFile("assets/player.png", NULL);
    player->sprite = sfSprite_create();
    sfSprite_setOrigin(player->sprite, (sfVector2f){32, 32 + 25});
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setScale(player->sprite, (sfVector2f){2, 2});
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, player->pos);
    player->task = register_task(
        game, &task, NULL);
    update_direction(player, DOWN);
    return player;
}

int update_player(pirate_quest_t *game)
{
    if (game->player->is_moving == 0) {
        game->player->rect.left = 0;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
        sfRenderWindow_drawSprite(
                game->window->window,
                game->player->sprite, NULL
        );
        return 0;
    }
    sfSprite_setPosition(game->player->sprite, game->player->pos);
    sfRenderWindow_drawSprite(
            game->window->window,
            game->player->sprite, NULL
    );
    return 0;
}

void update_direction(player_t *player, direction_t direction)
{
    player->direction = direction;
    player->rect.top = (direction * 64) + 8 * 64;
    sfSprite_setTextureRect(player->sprite, player->rect);
}
