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

    settings->up = sfKeyUp;
    settings->down = sfKeyDown;
    settings->left = sfKeyLeft;
    settings->right = sfKeyRight;
    settings->attack = sfKeySpace;
    write_settings(settings);
    return settings;
}

void set_keycode(settings_t *settings, int i, char *line)
{
    sfKeyCode keycode = (sfKeyCode) my_getnbr(line);

    switch (i) {
        case 0:
            settings->up = keycode;
            break;
        case 1:
            settings->down = keycode;
            break;
        case 2:
            settings->left = keycode;
            break;
        case 3:
            settings->right = keycode;
            break;
        case 4:
            settings->attack = keycode;
            break;
    }
}

settings_t *import_settings(void)
{
    FILE *fd = fopen("settings.txt", "r");
    settings_t *settings;
    char *line = NULL;
    size_t len = 0;
    size_t size;

    if (fd == NULL) {
        return initialize_settings();
    }
    settings = malloc(sizeof(settings_t));
    for (int i = 0; i < 5; i++) {
        size = getline(&line, &len, fd);
        if (size == -1 || my_strcmp(line, "") == 0)
            break;
        line[size - 1] = '\0';
        set_keycode(settings, i, line);
    }
    fclose(fd);
    return settings;
}

void write_settings(settings_t *settings)
{
    FILE *fd = fopen("settings.txt", "w");

    if (fd == NULL)
        return;
    fprintf(fd, "%d\n", settings->up);
    fprintf(fd, "%d\n", settings->down);
    fprintf(fd, "%d\n", settings->left);
    fprintf(fd, "%d\n", settings->right);
    fprintf(fd, "%d\n", settings->attack);
    fclose(fd);
}
