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

int dialogue_npc(pirate_quest_t *game)
{
    //printf("//%d//%d//\n\n", game->camera->map_position.x, game->camera->map_position.y);
        if (game->camera->map_position.x == 46 && game->camera->map_position.y == 70)
            play_dialogue(game, get_dialogue(game, FIRST_NPC), 0);
        //printf("//%d//%d//\n\n", game->camera->map_position.x, game->camera->map_position.y);
    //46 69
    return 0;
}