/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** dialogue_npc.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/pirate_quest.h"


void cave_telep(pirate_quest_t *game)
{
    if (player_is_in_square_rect(game, (sfVector2i)
    {72, 70}, (sfVector2i) {72, 71}) && sfKeyboard_isKeyPressed(sfKeyE)) {
        game->camera->map_position.x = 151;
        game->camera->map_position.y = 32;
    }
    if (player_is_in_square_rect(game, (sfVector2i)
    {151, 30}, (sfVector2i) {151, 31}) && sfKeyboard_isKeyPressed(sfKeyE)) {
        game->camera->map_position.x = 72;
        game->camera->map_position.y = 72;
    }
}

void beach_telep(pirate_quest_t *game)
{
    if (player_is_in_square_rect(game, (sfVector2i)
    {169, 18}, (sfVector2i) {169, 20}) && sfKeyboard_isKeyPressed(sfKeyE)) {
        game->camera->map_position.x = 86;
        game->camera->map_position.y = 70;
    }
}

void tavern_telep(pirate_quest_t *game)
{
    if (player_is_in_square_rect(game, (sfVector2i)
    {153, 124}, (sfVector2i) {154, 126}) && sfKeyboard_isKeyPressed(sfKeyE)) {
        game->camera->map_position.x = 102;
        game->camera->map_position.y = 22;
    }
    if (player_is_in_square_rect(game, (sfVector2i)
    {102, 22}, (sfVector2i) {103, 24}) && sfKeyboard_isKeyPressed(sfKeyE)) {
        game->camera->map_position.x = 154;
        game->camera->map_position.y = 126;
    }
}

int dialogue_npc(pirate_quest_t *game)
{
    cave_telep(game);
    beach_telep(game);
    tavern_telep(game);
    return 0;
}
