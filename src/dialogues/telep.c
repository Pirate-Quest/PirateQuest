/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** dialogue_npc.c
*/

#include "../../include/pirate_quest.h"


static int guard_beach(pirate_quest_t *game)
{
    if (player_is_in_square_rect(game, (sfVector2i)
    {116, 194}, (sfVector2i) {118, 196}))
        return 1;
    if (player_is_in_square_rect(game, (sfVector2i)
    {120, 191}, (sfVector2i) {122, 193}))
        return 1;
    if (player_is_in_square_rect(game, (sfVector2i)
    {124, 191}, (sfVector2i) {126, 193}))
        return 1;
    if (player_is_in_square_rect(game, (sfVector2i)
    {130, 194}, (sfVector2i) {132, 196}))
        return 1;
    if (player_is_in_square_rect(game, (sfVector2i)
    {134, 197}, (sfVector2i) {136, 199}))
        return 1;
    if (player_is_in_square_rect(game, (sfVector2i)
    {132, 201}, (sfVector2i) {134, 203}))
        return 1;
    return 0;
}

void cave_telep(sfEvent event, pirate_quest_t *game)
{
    if (player_is_in_square_rect(game, (sfVector2i)
    {72, 70}, (sfVector2i) {72, 71}) && event.key.code == sfKeyE) {
        game->camera->pos_in_tile = (sfVector2f){0, 0};
        game->camera->map_position.x = 151;
        game->camera->map_position.y = 31;
    }
    if (player_is_in_square_rect(game, (sfVector2i)
    {151, 30}, (sfVector2i) {151, 31}) && event.key.code == sfKeyE) {
        game->camera->pos_in_tile = (sfVector2f){0, 0};
        game->camera->map_position.x = 72;
        game->camera->map_position.y = 71;
    }
}

void dialogue_npc_four(sfEvent event, pirate_quest_t *game)
{
    if (player_is_in_square_rect(game, (sfVector2i)
    {32, 173}, (sfVector2i) {41, 179}) && event.key.code == sfKeyE &&
    is_item(game, PLANK_ITEM) && is_item(game, SAIL_ITEM)
    && is_item(game, WHEEL_ITEM))
        play_dialogue(game, get_dialogue(game, END_GAME), 0);
    if (player_is_in_square_rect(game, (sfVector2i)
    {153, 20}, (sfVector2i) {156, 21}) && game->dialogue_service->
    is_dialogue_playing == 0 && event.key.code == sfKeyE &&
    !is_item(game, SAIL_ITEM)) {
            play_dialogue(game, get_dialogue(game, CHEST), 0);
            add_item(game, SAIL_ITEM);
    }
    if (player_is_in_square_rect(game, (sfVector2i)
    {157, 135}, (sfVector2i) {159, 136}) && event.key.code == sfKeyE
    && game->dialogue_service->is_dialogue_playing == 0)
        play_dialogue(game, get_dialogue(game, MICH), 0);
}

void dialogue_npc_guard(sfEvent event, pirate_quest_t *game)
{
    if (guard_beach(game) == 1 && event.key.code == sfKeyE
    && game->dialogue_service->is_dialogue_playing == 0)
        play_dialogue(game, get_dialogue(game, BEACH), 0);
    if (player_is_in_square_rect(game, (sfVector2i)
    {135, 249}, (sfVector2i) {137, 251}) && event.key.code == sfKeyE
    && game->dialogue_service->is_dialogue_playing == 0)
        play_dialogue(game, get_dialogue(game, LOC), 0);
    if (player_is_in_square_rect(game, (sfVector2i)
    {139, 255}, (sfVector2i) {141, 257}) && event.key.code == sfKeyE
    && game->dialogue_service->is_dialogue_playing == 0)
        play_dialogue(game, get_dialogue(game, SEN), 0);
    if (player_is_in_square_rect(game, (sfVector2i)
    {36, 270}, (sfVector2i) {39, 271}) &&
    event.key.code == sfKeyE && !is_item(game, SWORD_ITEM)
    && game->dialogue_service->is_dialogue_playing == 0) {
        play_dialogue(game, get_dialogue(game, DESERT), 0);
        if (is_item(game, TUTO_SWORD_ITEM) == 1)
            remove_item(game, TUTO_SWORD_ITEM);
        add_item(game, SWORD_ITEM);
    }
}
