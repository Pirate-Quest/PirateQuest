/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** dialogue_player.c
*/

#include "../../include/pirate_quest.h"

static void init_dialogue_service(pirate_quest_t *game)
{
    game->dialogue_service = malloc(sizeof(dialogue_service_t));
    game->dialogue_service->is_dialogue_playing = 0;
    game->dialogue_service->current_dialogue = NONE_DIALOGUE;
    game->dialogue_service->current_dialogue_index = 0;
}

void init_dialogue_box(pirate_quest_t *game)
{
    init_dialogue_service(game);
    game->dialogue_box = malloc(sizeof(dialogue_box_t));
    game->dialogue_box->box = sfRectangleShape_create();
    sfRectangleShape_setSize(game->dialogue_box->box, (sfVector2f){
        get_resolution(game).width - (64 * 2.5 * game->camera->zoom),
        64 * game->camera->zoom});
    sfRectangleShape_setFillColor(game->dialogue_box->box,
        (sfColor){0, 0, 0, 150});
    sfRectangleShape_setPosition(game->dialogue_box->box,
        (sfVector2f){32 * 2.5 * game->camera->zoom, get_resolution(game).height
        - 32 * 2.5 * game->camera->zoom});
    game->dialogue_box->text = sfText_create();
    game->dialogue_box->font = sfFont_createFromFile("assets/font/Bitter.ttf");
    sfText_setFont(game->dialogue_box->text, game->dialogue_box->font);
    sfText_setCharacterSize(game->dialogue_box->text, 30);
    sfText_setFillColor(game->dialogue_box->text, sfWhite);
}

void free_dialogue_box(pirate_quest_t *game)
{
    free(game->dialogue_service);
    sfRectangleShape_destroy(game->dialogue_box->box);
    sfText_destroy(game->dialogue_box->text);
    sfFont_destroy(game->dialogue_box->font);
    free(game->dialogue_box);
}

static int on_tick(pirate_quest_t *game, hashtable_t *_)
{
    return 0;
}

static int on_end(pirate_quest_t *game, hashtable_t *_)
{
    return 0;
}

void play_dialogue(pirate_quest_t *game, dialogue_impl_t *dialogue, int i)
{
    task_builder_t builder = {
        .on_tick = &on_tick,
        .on_end = &on_end,
        .second_interval = 0.1,
        .execution_count = 0
    };
}
