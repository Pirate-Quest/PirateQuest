/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** camera.c
*/

#include <SFML/Graphics.h>
#include "../../include/render.h"

void set_camera_center(camera_t *camera, sfVector2f center)
{
    sfView_setCenter(camera->view, center);
}

void set_camera_size(camera_t *camera, sfVector2f size)
{
    sfView_setSize(camera->view, size);
}

void set_camera(camera_t *camera, sfRenderWindow *window)
{
    sfRenderWindow_setView(window, camera->view);
}
