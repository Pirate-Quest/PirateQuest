/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** dialogue_player.c
*/

#include "../../include/pirate_quest.h"

static void stop_playing(pirate_quest_t *game)
{
    game->dialogue_service->is_dialogue_playing = 0;
    game->dialogue_service->current_dialogue = NONE_DIALOGUE;
    game->dialogue_service->current_dialogue_index = 0;
    game->dialogue_service->current_dialogue_text_index = 0;
}

static void init_dialogue_service(pirate_quest_t *game)
{
    game->dialogue_service = malloc(sizeof(dialogue_service_t));
    stop_playing(game);
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

static int on_tick(pirate_quest_t *game, hashtable_t *_, int exec_count)
{
    dialogue_t *current_dialogue = get_current_dialogue(game);
    int showed_text_length =
        game->dialogue_service->current_dialogue_text_index;

    replace_char(current_dialogue->content, '\n', ' ');
    if (showed_text_length >= my_strlen(current_dialogue->content)) {
        sfText_setString(game->dialogue_box->text, current_dialogue->content);
        return 0;
    }
    sfText_setString(game->dialogue_box->text,
        my_strndup(current_dialogue->content, showed_text_length));
    play_sound(game, ZIPCLICK_SOUND);
    game->dialogue_service->current_dialogue_text_index += 2;
    return 0;
}

static int on_end(pirate_quest_t *game, hashtable_t *_)
{
    dialogue_impl_t *dialogue = get_dialogue(game,
        game->dialogue_service->current_dialogue);

    if (game->dialogue_service->current_dialogue_index + 1
        < dialogue->dialogue_count) {
        game->dialogue_service->current_dialogue_index++;
        game->dialogue_service->current_dialogue_text_index = 0;
        play_dialogue(game, dialogue,
            game->dialogue_service->current_dialogue_index);
        return 0;
    }
    stop_playing(game);
    return 0;
}

void play_dialogue(pirate_quest_t *game, dialogue_impl_t *dialogue, int i)
{
    task_builder_t builder = {
        .on_tick = &on_tick,
        .on_end = &on_end,
        .second_interval = 0.1,
        .execution_count = (dialogue->dialogues[i].time) * 10
    };

    if (game->dialogue_service->is_dialogue_playing && i == 0) {
        my_puterr("A dialogue is already playing.\n");
        return;
    }
    game->dialogue_service->is_dialogue_playing = 1;
    game->dialogue_service->current_dialogue = dialogue->dialogue;
    game->dialogue_service->current_dialogue_index = i;
    game->dialogue_service->current_dialogue_text_index = 0;
    sfText_setString(game->dialogue_box->text,
        dialogue->dialogues[i].content);
    register_task(game, &builder, ht_from_args(0));
}

void update_dialogue_visuals(pirate_quest_t *game)
{
    dialogue_t *current_dialogue;
    sfFloatRect ga = sfRectangleShape_getGlobalBounds(game->dialogue_box->box);
    sfFloatRect gb = sfText_getGlobalBounds(game->dialogue_box->text);

    if (!game->dialogue_service->is_dialogue_playing)
        return;
    current_dialogue = get_current_dialogue(game);
    draw_interlocutor(game, current_dialogue->speaker);
    sfText_setPosition(game->dialogue_box->text, (sfVector2f){
        ga.left + (ga.width - gb.width) / 2,
        ga.top + (ga.height - gb.height) / 2
    });
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->dialogue_box->box, NULL);
    sfRenderWindow_drawText(game->window->window,
        game->dialogue_box->text, NULL);
}
