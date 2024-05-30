/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** game_phase.c
*/

#include "../../include/pirate_quest.h"

const game_phase_info_t game_phases[] = {
    {
        .phase = MENU_PHASE,
        .pos_in_map = {0, 0},
        .enemy_count = 0,
        .enemy_type = BASIC
    },
    {
        .phase = TUTORIAL_PHASE,
        .pos_in_map = {19, 69},
        .enemy_count = 0,
        .enemy_type = BASIC
    },
    {
        .phase = MARKET_PHASE,
        .pos_in_map = {143, 128},
        .enemy_count = 0,
        .enemy_type = BASIC
    },
    {
        .phase = TAVERN_PHASE,
        .pos_in_map = {102, 21},
        .enemy_count = 0,
        .enemy_type = BASIC
    },
    {
        .phase = DESERT_PHASE,
        .pos_in_map = {135, 246},
        .enemy_count = 1,
        .enemy_type = BASIC
    },
    {
        .phase = BOSS_PHASE,
        .pos_in_map = {40, 208},
        .enemy_count = 1,
        .enemy_type = BOSS
    },
    {
        .phase = CAVERN_PHASE,
        .pos_in_map = {151, 31},
        .enemy_count = 1,
        .enemy_type = RAT
    }
};

const int game_phase_count = sizeof(game_phases) / sizeof(game_phase_info_t);

sfVector2i get_pos_from_phase(game_phase_t phase)
{
    for (int i = 0; i < game_phase_count; i++)
        if (game_phases[i].phase == phase)
            return game_phases[i].pos_in_map;
    return (sfVector2i){0, 0};
}

int get_enemy_count_from_phase(pirate_quest_t *game)
{
    for (int i = 0; i < game_phase_count; i++)
        if (game_phases[i].phase == game->player->data->phase)
            return game_phases[i].enemy_count;
    return 0;
}

enemy_type_t get_enemy_type_from_phase(pirate_quest_t *game)
{
    for (int i = 0; i < game_phase_count; i++)
        if (game_phases[i].phase == game->player->data->phase)
            return game_phases[i].enemy_type;
    return BASIC;
}
