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
