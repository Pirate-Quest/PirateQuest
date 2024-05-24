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
        .pos_in_map = {0, 0}
    },
    {
        .phase = TUTORIAL_PHASE,
        .pos_in_map = {19, 69}
    },
    {
        .phase = MARKET_PHASE,
        .pos_in_map = {143, 128}
    },
    {
        .phase = TAVERN_PHASE,
        .pos_in_map = {102, 21}
    },
    {
        .phase = DESERT_PHASE,
        .pos_in_map = {135, 246}
    },
    {
        .phase = BOSS_PHASE,
        .pos_in_map = {40, 223}
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
