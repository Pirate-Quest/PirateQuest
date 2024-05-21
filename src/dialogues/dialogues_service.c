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
            return &game->dialogues[i];
    }
    return NULL;
}

dialogue_t *get_current_dialogue(pirate_quest_t *game)
{
    dialogue_impl_t *d = get_dialogue(game,
        game->dialogue_service->current_dialogue);

    if (d == NULL)
        return NULL;
    return &d->dialogues[game->dialogue_service->current_dialogue_index];
}
