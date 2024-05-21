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
    
    if (player_is_in_square_rect(game, (sfVector2i) {72, 70}, (sfVector2i) {72, 71}) && sfKeyboard_isKeyPressed(sfKeyE)) {
        game->camera->map_position.x = 151;
        game->camera->map_position.y = 32;
    }
    if (player_is_in_square_rect(game, (sfVector2i) {151, 30}, (sfVector2i) {151, 31}) && sfKeyboard_isKeyPressed(sfKeyE)) {
        game->camera->map_position.x = 72;
        game->camera->map_position.y = 72;
    }
}

int dialogue_npc(pirate_quest_t *game)
{
    //printf("//%d//%d//\n\n", game->camera->map_position.x, game->camera->map_position.y);
      //  if (game->camera->map_position.x == 46 && game->camera->map_position.y == 70)
        //    play_dialogue(game, get_dialogue(game, FIRST_NPC), 0);
        //printf("//%d//%d//\n\n", game->camera->map_position.x, game->camera->map_position.y);
    //46 69
    cave_telep(game);
    return 0;
}