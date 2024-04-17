/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** render_window.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../../include/render.h"

void init_icon(render_window_t *window)
{
    sfImage* icon = sfImage_createFromFile("assets/logo.png");
    const sfUint8 *pixel_data;

    if (icon == NULL)
        return;
    pixel_data = sfImage_getPixelsPtr(icon);
    sfRenderWindow_setIcon(
        window->window,
        sfImage_getSize(icon).x,
        sfImage_getSize(icon).y,
        pixel_data
    );
    sfImage_destroy(icon);
}
