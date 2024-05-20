/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** dialogues_registry.c
*/

#include "../../include/pirate_quest.h"

static dialogue_builder_t dialogue_builders[] = {
    {TUTORIAL_1, "assets/dialogues/tutorial_1.dialogue"},
};

const int dialogue_builders_count = sizeof(dialogue_builders) /
    sizeof(dialogue_builder_t);

void init_dialogues_registry(pirate_quest_t *game)
{
    game->dialogues = malloc(sizeof(dialogue_impl_t) * dialogue_builders_count);
    for (int i = 0; i < dialogue_builders_count; i++) {
        game->dialogues[i].dialogue = dialogue_builders[i].dialogue;
        game->dialogues[i].dialogue_count = 0;
        game->dialogues[i].dialogues = parse_dialogue_file(
            dialogue_builders[i].file_path,
            &game->dialogues[i].dialogue_count
        );
    }
}

void free_dialogues_registry(pirate_quest_t *game)
{
    for (int i = 0; i < dialogue_builders_count; i++) {
        free_dialogues(game->dialogues[i].dialogues,
            game->dialogues[i].dialogue_count);
    }
    free(game->dialogues);
}
