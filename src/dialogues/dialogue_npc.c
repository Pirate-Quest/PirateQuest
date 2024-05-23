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
    if (player_is_in_square_rect(game, (sfVector2i)
    {152, 135}, (sfVector2i) {153, 136}) && event.key.code == sfKeyE)
        play_dialogue(game, get_dialogue(game, FIRST_WOMEN), 0);
    if (player_is_in_square_rect(game, (sfVector2i)
    {157, 135}, (sfVector2i) {159, 136}) && event.key.code == sfKeyE)
        play_dialogue(game, get_dialogue(game, MICH), 0);
}

void dialogue_npc_two(sfEvent event, pirate_quest_t *game)
{
    if (player_is_in_square_rect(game, (sfVector2i)
    {150, 142}, (sfVector2i) {152, 143}) && event.key.code == sfKeyE)
        play_dialogue(game, get_dialogue(game, DOUGLA), 0);
    if (player_is_in_square_rect(game, (sfVector2i)
    {160, 139}, (sfVector2i) {162, 141}) && event.key.code == sfKeyE)
        play_dialogue(game, get_dialogue(game, MARI), 0);
    if (player_is_in_square_rect(game, (sfVector2i)
    {163, 142}, (sfVector2i) {165, 144}) && event.key.code == sfKeyE)
        play_dialogue(game, get_dialogue(game, GRE), 0);
    if (player_is_in_square_rect(game, (sfVector2i)
    {164, 135}, (sfVector2i) {166, 136}) && event.key.code == sfKeyE)
        play_dialogue(game, get_dialogue(game, MONO), 0);
    if (player_is_in_square_rect(game, (sfVector2i)
    {149, 140}, (sfVector2i) {151, 141}) && event.key.code == sfKeyE)
        play_dialogue(game, get_dialogue(game, GROGN), 0);
    if (player_is_in_square_rect(game, (sfVector2i)
    {151, 125}, (sfVector2i) {153, 126}) && event.key.code == sfKeyE)
        play_dialogue(game, get_dialogue(game, GUARD), 0);
}

void dialogue_npc_three(sfEvent event, pirate_quest_t *game)
{
    if (player_is_in_square_rect(game, (sfVector2i)
    {154, 125}, (sfVector2i) {157, 126}) && event.key.code == sfKeyE)
        play_dialogue(game, get_dialogue(game, GUARD), 0);
}