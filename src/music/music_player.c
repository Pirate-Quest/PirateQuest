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
    {MARKET_MUSIC, "Tuto", "assets/music/market.wav"},
    {TAVERN_MUSIC, "Tavern", "assets/music/tavern.wav"},
    {DESERT_MUSIC, "Desert", "assets/music/desert.wav"},
    {BOSS_MUSIC, "Boss", "assets/music/boss.wav"}
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
    game->player->data->phase = music;
    sfMusic_play(game->music->musics[music]);
}

void select_music(pirate_quest_t *game)
{
    if (player_is_in_square_rect(game, (sfVector2i){134, 203},
        (sfVector2i){136, 205}) && game->player->data->phase != MARKET_MUSIC)
        music_player(game, MARKET_MUSIC);
    if (player_is_in_square_rect(game, (sfVector2i){134, 237},
        (sfVector2i){136, 239}) && game->player->data->phase != DESERT_MUSIC)
        music_player(game, DESERT_MUSIC);
    if (player_is_in_square_rect(game, (sfVector2i){39, 239},
        (sfVector2i){41, 241}) && game->player->data->phase != DESERT_MUSIC)
        music_player(game, DESERT_MUSIC);
    if (player_is_in_square_rect(game, (sfVector2i){39, 225},
        (sfVector2i){41, 227}) && game->player->data->phase != BOSS_MUSIC)
        music_player(game, BOSS_MUSIC);
    if (player_is_in_square_rect(game, (sfVector2i){108, 114},
        (sfVector2i){110, 117}) && game->player->data->phase != TUTO_MUSIC)
        music_player(game, TUTO_MUSIC);
    if (player_is_in_square_rect(game, (sfVector2i){121, 113},
        (sfVector2i){123, 118}) && game->player->data->phase != MARKET_MUSIC)
        music_player(game, MARKET_MUSIC);
}
