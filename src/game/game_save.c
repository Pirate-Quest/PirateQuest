/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** game_save.c
*/

#include <stdio.h>
#include <string.h>
#include "../../include/pirate_quest.h"

void init_as_default(pirate_quest_t *game)
{
    game->player->data->phase = TUTORIAL_PHASE;
    game->player->data->xp.current_lvl = 1;
    game->player->data->xp.current_xp = 0;
    game->player->data->inventory = (player_inventory_t)
        {NONE_ITEM, NONE_ITEM, NONE_ITEM, NONE_ITEM, NONE_ITEM};
    game->player->data->resistance_lvl = 0;
    game->player->data->strength_lvl = 0;
    game->player->data->speed_lvl = 0;
}

void save_game(pirate_quest_t *game, char *id)
{
    FILE *file = fopen(id, "w");
    player_data_t *player_data = game->player->data;

    if (!file)
        return;
    fprintf(file, "phase=%d\n", player_data->phase);
    fprintf(file, "current_lvl=%d\n", player_data->xp.current_lvl);
    fprintf(file, "current_xp=%d\n", player_data->xp.current_xp);
    fprintf(file, "resistance_lvl=%d\n", player_data->resistance_lvl);
    fprintf(file, "strength_lvl=%d\n", player_data->strength_lvl);
    fprintf(file, "speed_lvl=%d\n", player_data->speed_lvl);
    for (int i = 0; i < SLOT_COUNT; i++)
        fprintf(file, "slot%d=%d\n", i, player_data->inventory.slots[i]);
    fclose(file);
}

static int my_intlen(int nb)
{
    int len = 0;

    while (nb > 0) {
        nb /= 10;
        len++;
    }
    return len;
}

static void read_slot_params(char *line, player_data_t **player_data)
{
    if (my_strncmp(line, "slot0=", 6) == 0)
        (*player_data)->inventory.slots[0] = my_getnbr(line + 6);
    if (my_strncmp(line, "slot1=", 6) == 0)
        (*player_data)->inventory.slots[1] = my_getnbr(line + 6);
    if (my_strncmp(line, "slot2=", 6) == 0)
        (*player_data)->inventory.slots[2] = my_getnbr(line + 6);
    if (my_strncmp(line, "slot3=", 6) == 0)
        (*player_data)->inventory.slots[3] = my_getnbr(line + 6);
    if (my_strncmp(line, "slot4=", 6) == 0)
        (*player_data)->inventory.slots[4] = my_getnbr(line + 6);
}

static void read_params(char *line, player_data_t **player_data)
{
    if (my_strncmp(line, "phase=", 6) == 0)
        (*player_data)->phase = my_getnbr(line + 6);
    if (my_strncmp(line, "current_lvl=", 12) == 0)
        (*player_data)->xp.current_lvl = my_getnbr(line + 12);
    if (my_strncmp(line, "current_xp=", 11) == 0)
        (*player_data)->xp.current_xp = my_getnbr(line + 11);
    if (my_strncmp(line, "resistance_lvl=", 15) == 0)
        (*player_data)->resistance_lvl = my_getnbr(line + 15);
    if (my_strncmp(line, "strength_lvl=", 13) == 0)
        (*player_data)->strength_lvl = my_getnbr(line + 13);
    if (my_strncmp(line, "speed_lvl=", 10) == 0)
        (*player_data)->speed_lvl = my_getnbr(line + 10);
    read_slot_params(line, player_data);
}

void print_player_data(player_data_t *player_data)
{
    printf("phase=%d\n", player_data->phase);
    printf("current_lvl=%d\n", player_data->xp.current_lvl);
    printf("current_xp=%d\n", player_data->xp.current_xp);
    printf("resistance_lvl=%d\n", player_data->resistance_lvl);
    printf("strength_lvl=%d\n", player_data->strength_lvl);
    printf("speed_lvl=%d\n", player_data->speed_lvl);
    for (int i = 0; i < SLOT_COUNT; i++)
        printf("slot%d=%d\n", i, player_data->inventory.slots[i]);
}

void load_game(pirate_quest_t *game, char *id)
{
    FILE *file = fopen(id, "r");
    player_data_t **player_data = &game->player->data;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    init_as_default(game);
    if (!file) {
        save_game(game, id);
        return;
    }
    for (read = getline(&line, &len, file); read != -1;
        read = getline(&line, &len, file)) {
        read_params(line, player_data);
    }
    fclose(file);
}
