/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** interact_box.c
*/

#include "../../include/pirate_quest.h"

static void init_text_bg(pirate_quest_t *game, sfFloatRect text_rect)
{
    sfRectangleShape_setSize(game->interact_box->text_bg, (sfVector2f){
        text_rect.width + 20, text_rect.height + 40
    });
    sfRectangleShape_setFillColor(game->interact_box->text_bg,
        (sfColor){0, 0, 0, 150}
    );
    sfRectangleShape_setPosition(game->interact_box->text_bg, (sfVector2f){
        get_resolution(game).width / 2 - text_rect.width / 2 - 10,
        get_resolution(game).height - 100
    });
}

void init_interact_box(pirate_quest_t *game)
{
    sfFloatRect text_rect;

    game->have_interaction = 0;
    game->interact_box = malloc(sizeof(interact_box_t));
    game->interact_box->text = sfText_create();
    game->interact_box->text_bg = sfRectangleShape_create();
    sfText_setString(game->interact_box->text, "Click \"E\" to interact");
    sfText_setFont(game->interact_box->text, game->dialogue_box->font);
    sfText_setCharacterSize(game->interact_box->text, 30);
    sfText_setFillColor(game->interact_box->text, sfWhite);
    text_rect = sfText_getGlobalBounds(game->interact_box->text);
    sfText_setPosition(game->interact_box->text, (sfVector2f){
        get_resolution(game).width / 2 - text_rect.width / 2,
        get_resolution(game).height - 90
    });
    init_text_bg(game, sfText_getGlobalBounds(game->interact_box->text));
}

void free_interact_box(pirate_quest_t *game)
{
    sfText_destroy(game->interact_box->text);
    sfRectangleShape_destroy(game->interact_box->text_bg);
    free(game->interact_box);
}

void draw_interact_box(pirate_quest_t *game)
{
    sfRenderWindow_drawRectangleShape(game->window->window,
        game->interact_box->text_bg, NULL);
    sfRenderWindow_drawText(game->window->window,
        game->interact_box->text, NULL);
}

void update_interact_box_resolution(pirate_quest_t *game)
{
    sfRectangleShape_setPosition(game->interact_box->text_bg, (sfVector2f){
        get_resolution(game).width / 2 - 100,
        get_resolution(game).height - 100
    });
    sfText_setPosition(game->interact_box->text, (sfVector2f){
        get_resolution(game).width / 2 - 90,
        get_resolution(game).height - 90
    });
}
