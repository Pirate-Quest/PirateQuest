/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** dialogue_npc.c
*/

#include "../../include/pirate_quest.h"


void cave_telep(sfEvent event, pirate_quest_t *game)
{
    if (player_is_in_square_rect(game, (sfVector2i)
    {72, 70}, (sfVector2i) {72, 71}) && event.key.code == sfKeyE) {
        game->camera->map_position.x = 151;
        game->camera->map_position.y = 32;
    }
    if (player_is_in_square_rect(game, (sfVector2i)
    {151, 30}, (sfVector2i) {151, 31}) && event.key.code == sfKeyE) {
        game->camera->map_position.x = 72;
        game->camera->map_position.y = 72;
    }
}

void beach_telep(sfEvent event, pirate_quest_t *game)
{
    if (player_is_in_square_rect(game, (sfVector2i)
    {169, 18}, (sfVector2i) {169, 20}) && event.key.code == sfKeyE) {
        game->camera->map_position.x = 86;
        game->camera->map_position.y = 70;
    }
}

void tavern_telep(sfEvent event, pirate_quest_t *game)
{
    if (player_is_in_square_rect(game, (sfVector2i)
    {153, 124}, (sfVector2i) {154, 126}) && event.key.code == sfKeyE) {
        game->camera->map_position.x = 102;
        game->camera->map_position.y = 22;
    }
    if (player_is_in_square_rect(game, (sfVector2i)
    {102, 22}, (sfVector2i) {103, 24}) && event.key.code == sfKeyE) {
        game->camera->map_position.x = 154;
        game->camera->map_position.y = 126;
    }
}

void dialogue_npc(sfEvent event, pirate_quest_t *game)
{
    if (player_is_in_square(game, 107, 18) && game->dialogue_service->
        is_dialogue_playing == 0 && event.key.code == sfKeyE)
        play_dialogue(game, get_dialogue(game, MAYOR_DG), 0);
    if (player_is_in_square(game, 27, 99) && game->dialogue_service->
        is_dialogue_playing == 0 && event.key.code == sfKeyE) {
        play_dialogue(game, get_dialogue(game, SOLO_SWORD), 0);
        }
    if (player_is_in_square(game, 46, 70) && game->dialogue_service->
        is_dialogue_playing == 0 && event.key.code == sfKeyE)
        play_dialogue(game, get_dialogue(game, FIRST_NPC), 0);
}
