/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** game_phase.c
*/

#include "../../include/pirate_quest.h"

const game_phase_info_t game_phases[] = {
    {
        .phase = TUTORIAL_PHASE,
        .pos_in_map = {19, 69}
    },
    {
        .phase = VILLAGE_PHASE,
        .pos_in_map = {143, 128}
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
