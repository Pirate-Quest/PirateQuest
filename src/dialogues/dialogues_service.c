/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** dialogues_service.c
*/

#include "../../include/pirate_quest.h"

dialogue_impl_t *get_dialogue(pirate_quest_t *game, dialogue_enum_t dialogue)
{
    for (int i = 0; i < dialogue_count; i++) {
        if (dialogues[i].dialogue == dialogue)
            return game->dialogues[i];
    }
    return NULL;
}
