/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** sound_registry.c
*/

#include "../../include/pirate_quest.h"

const sound_t sounds[] = {
    {
        .key = ZIPCLICK_SOUND,
        .path = "assets/sound/zipclick.ogg"
    }
};
const int sound_count = sizeof(sounds) / sizeof(sound_t);

void init_sound(pirate_quest_t *game)
{
    sfSoundBuffer* buffer;

    game->sounds = malloc(sizeof(sound_impl_t) * sound_count);
    for (int i = 0; i < sound_count; i++) {
        game->sounds[i].key = sounds[i].key;
        buffer = sfSoundBuffer_createFromFile(sounds[i].path);
        if (!buffer)
            return;
        game->sounds[i].sound = sfSound_create();
        sfSound_setBuffer(game->sounds[i].sound, buffer);
    }
}

void play_sound(pirate_quest_t *game, sound_key_t key)
{
    for (int i = 0; i < sound_count; i++) {
        if (game->sounds[i].key == key) {
            sfSound_play(game->sounds[i].sound);
            return;
        }
    }
}

void destroy_sounds(pirate_quest_t *game)
{
    for (int i = 0; i < sound_count; i++) {
        sfSound_destroy(game->sounds[i].sound);
    }
    free(game->sounds);
}
