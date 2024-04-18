/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../include/commons.h"
#include "../include/render.h"
#include "../include/event.h"
#include "../include/map.h"

void free_window(render_window_t *window)
{
    if (window == NULL)
        return;
    if (window->camera != NULL) {
        if (window->camera->view != NULL)
            sfView_destroy(window->camera->view);
        free(window->camera);
    }
    sfRenderWindow_destroy(window->window);
    free(window);
}

render_window_t *init_window(void)
{
    render_window_t *window = malloc(sizeof(render_window_t));

    if (window == NULL) {
        my_puterr("Error: Could not allocate memory for window.\n");
        return NULL;
    }
    window->window = sfRenderWindow_create(
        get_sfvideo_mode(0), "Pirate Quest", sfResize | sfClose, NULL);
    window->camera = malloc(sizeof(camera_t));
    window->camera->view = sfView_create();
    window->camera->center = (sfVector2f){0, 0};
    window->camera->size = (sfVector2f){1920, 1080};
    set_camera(window->camera, window->window);
    return window;
}

static void update(pirate_quest_t *game)
{
    update_listeners(game);
    sfRenderWindow_clear(game->window->window, sfBlack);
    sfRenderWindow_display(game->window->window);
}

int main(void)
{
    pirate_quest_t game;

    game.window = init_window();
    if (game.window == NULL)
        return my_puterr("Error: Could not allocate memory for window.\n");
    if (game.window->window == NULL) {
        free_window(game.window);
        return my_puterr("Error: Could not create window. This could be "
            "due to a lack of memory. Or incompatible hardware.\n");
    }
    init_icon(game.window);
    init_layers();
    while (sfRenderWindow_isOpen(game.window->window))
        update(&game);
    free_window(game.window);
    return FALSE;
}
