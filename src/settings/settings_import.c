/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** settings_import.c
*/


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/settings.h"
#include "../../include/pirate_quest.h"

settings_t *initialize_settings(void)
{
    settings_t *settings = malloc(sizeof(settings_t));

    settings->up = sfKeyZ;
    settings->down = sfKeyS;
    settings->left = sfKeyQ;
    settings->right = sfKeyD;
    settings->attack = sfKeyF;
    settings->resolution = 1;
    write_settings(settings);
    return settings;
}

void set_keycode(settings_t *settings, char *line)
{
    if (my_strncmp(line, "res: ", 5) == 0)
        settings->resolution = my_getnbr(line + 5);
    if (my_strncmp(line, "up: ", 4) == 0)
        settings->up = my_getnbr(line + 4);
    if (my_strncmp(line, "down: ", 6) == 0)
        settings->down = my_getnbr(line + 6);
    if (my_strncmp(line, "left: ", 6) == 0)
        settings->left = my_getnbr(line + 6);
    if (my_strncmp(line, "right: ", 7) == 0)
        settings->right = my_getnbr(line + 7);
    if (my_strncmp(line, "attack: ", 8) == 0)
        settings->attack = my_getnbr(line + 8);
}

settings_t *import_settings(void)
{
    FILE *fd = fopen("settings.txt", "r");
    settings_t *settings;
    char *line = NULL;
    size_t len = 0;
    size_t size;

    if (fd == NULL)
        return initialize_settings();
    settings = malloc(sizeof(settings_t));
    for (size = getline(&line, &len, fd); size != -1;
        size = getline(&line, &len, fd)) {
        line[size - 1] = '\0';
        set_keycode(settings, line);
    }
    fclose(fd);
    return settings;
}

void write_settings(settings_t *settings)
{
    FILE *fd = fopen("settings.txt", "w");

    if (fd == NULL)
        return;
    fprintf(fd, "up: %d\n", settings->up);
    fprintf(fd, "down: %d\n", settings->down);
    fprintf(fd, "left: %d\n", settings->left);
    fprintf(fd, "right: %d\n", settings->right);
    fprintf(fd, "attack: %d\n", settings->attack);
    fprintf(fd, "res: %d\n", settings->resolution);
    fclose(fd);
}

void write_settings_index(pirate_quest_t *game, int index, sfKeyCode key)
{
    if (index == 1)
        game->settings->up = key;
    if (index == 2)
        game->settings->down = key;
    if (index == 3)
        game->settings->left = key;
    if (index == 4)
        game->settings->right = key;
    if (index == 5)
        game->settings->attack = key;
    write_settings(game->settings);
}
