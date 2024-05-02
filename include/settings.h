/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** settings.h
*/

#ifndef SETTINGS_H_
    #define SETTINGS_H_

    #include <SFML/Graphics.h>
    #include "commons.h"

typedef struct settings_s {
    sfKeyCode up;
    sfKeyCode down;
    sfKeyCode left;
    sfKeyCode right;
    sfKeyCode attack;
    int resolution;
} settings_t;

settings_t *import_settings(void);
void write_settings(settings_t *settings);

#endif /* !SETTINGS_H_ */
