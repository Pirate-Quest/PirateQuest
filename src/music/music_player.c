/*
** EPITECH PROJECT, 2024
** Delivery
** File description:
** music_player
*/

#include "../../include/pirate_quest.h"
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Types.h>
#include <SFML/Config.h>
#include <stdlib.h>

const music_registry_t music_registry[] = {
    {MENU_MUSIC, "Menu", "assets/music/menu.wav"},
    {TUTO_MUSIC, "Tuto", "assets/music/tuto.wav"},
    {TAVERN_MUSIC, "Tavern", "assets/music/tavern.wav"}
};

void init_musique(pirate_quest_t *game)
{
    game->player->data->phase = 0;
    game->music = malloc(sizeof(music_tab_t));
    for (int i = 0; i < TOTAL_MUSIC; i++){
        game->music->musics[i] =
            sfMusic_createFromFile(music_registry[i].path);
        sfMusic_setLoop(game->music->musics[i], sfTrue);
    }
    sfMusic_play(game->music->musics[MENU_MUSIC]);
}

void music_player(pirate_quest_t *game, int music)
{
    for (int i = 0; i < TOTAL_MUSIC; i++){
        sfMusic_stop(game->music->musics[i]);
    }
    sfMusic_play(game->music->musics[music]);
}
