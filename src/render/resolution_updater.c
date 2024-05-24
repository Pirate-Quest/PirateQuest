/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** resolution_updater.c
*/

#include "../../include/pirate_quest.h"

static void reload_inv_sprites_resolution(pirate_quest_t *game)
{
    sfSprite_setScale(game->inv_bar->sprite_bar, (sfVector2f){
        game->camera->zoom * 1,
        game->camera->zoom * 1});
    sfSprite_setPosition(game->inv_bar->sprite_bar, (sfVector2f){2 *
        game->camera->zoom,
        get_resolution(game).height - 35.5 * game->camera->zoom});
    for (int i = 0; i < SLOT_COUNT; i++){
        sfSprite_setScale(game->inv_bar->slots[i], (sfVector2f){
            game->camera->zoom * 1,
            game->camera->zoom * 1});
        sfSprite_setPosition(game->inv_bar->slots[i], (sfVector2f){2 *
            game->camera->zoom + (i * 128),
            get_resolution(game).height - 34 * game->camera->zoom});
    }
}

void reload_square_res2(pirate_quest_t *game, int i, int y)
{
    for (int x = 0; x < RENDER_WIDTH; x++) {
        sfSprite_setPosition(game->square[i][y][x]->sprite,
            (sfVector2f){(x * 32 * game->camera->zoom) +
            get_resolution(game).width / 2 - (RENDER_WIDTH * 32 *
            game->camera->zoom / 2) +
            (game->camera->pos_in_tile.x * 32), (y * 32 *
            game->camera->zoom) + get_resolution(game).height / 2 -
            (RENDER_HEIGHT * 32 * game->camera->zoom / 2) +
            (game->camera->pos_in_tile.y * 32)}
        );
        sfSprite_setScale(game->square[i][y][x]->sprite,
            (sfVector2f){game->camera->zoom, game->camera->zoom});
    }
}

void reload_square_res(pirate_quest_t *game)
{
    for (int i = 0; i < LAYER_COUNT; i++)
        for (int y = 0; y < RENDER_HEIGHT; y++)
            reload_square_res2(game, i, y);
}

void update_player_sprite_resolution(pirate_quest_t *game)
{
    sfSprite_setScale(game->player->sprite, (sfVector2f){2 * game->camera->zoom
        / 2.5, 2 * game->camera->zoom / 2.5});
    game->player->pos = (sfVector2f){get_resolution(game).width / 2,
        get_resolution(game).height / 2};
    sfSprite_setPosition(game->player->sprite, game->player->pos);
}

void reload_sprites_resolution(pirate_quest_t *game)
{
    sfRectangleShape_setSize(game->dialogue_box->box, (sfVector2f){
        get_resolution(game).width - (64 * 2.5 * game->camera->zoom),
        64 * game->camera->zoom});
    sfRectangleShape_setPosition(game->dialogue_box->box,
        (sfVector2f){32 * 2.5 * game->camera->zoom, get_resolution(game).height
        - 32 * 2.5 * game->camera->zoom});
}

void reload_res(pirate_quest_t *game)
{
    resolution_t resolution = get_resolution(game);
    const float scale = 0.4;

    game->camera->pos_in_tile = (sfVector2f){0, 0};
    sfRenderWindow_setFramerateLimit(game->window->window, 120);
    reload_inv_sprites_resolution(game);
    reload_square_res(game);
    update_player_sprite_resolution(game);
    update_enemies_sprite_resolution(game);
    sfSprite_setScale(game->main_menu->background, (sfVector2f){
        (float) resolution.width / 1920, (float) resolution.height / 1080});
    sfSprite_setPosition(game->settings_menu->background, (sfVector2f){
            (resolution.width / 2) - 960 * scale / 2,
            (resolution.height / 2) - 540 * scale / 2});
    reload_sprites_resolution(game);
    update_dialogue_sprites_resolution(game);
    game->current_gui = IN_GAME;
}
