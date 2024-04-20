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

void free_game(pirate_quest_t *game)
{
    if (game->camera != NULL)
        free(game->camera);
    if (game->window != NULL) {
        sfRenderWindow_destroy(game->window->window);
        free(game->window);
    }
}

int init_window(pirate_quest_t *game)
{
    render_window_t *window = malloc(sizeof(render_window_t));
    camera_t *camera = malloc(sizeof(camera_t));

    if (window == NULL || camera == NULL) {
        my_puterr("Error: Could not allocate memory for window.\n");
        return FALSE;
    }
    window->window = sfRenderWindow_create(
        get_sfvideo_mode(0), "Pirate Quest", sfClose, NULL);
    camera->map_position = (sfVector2i){5, 16};
    camera->pos_in_tile = (sfVector2f){0.0, 0.0};
    camera->zoom = 2.5;
    game->window = window;
    game->camera = camera;
    return TRUE;
}

static void update(pirate_quest_t *game)
{
    update_listeners(game);
    sfRenderWindow_clear(game->window->window, sfBlack);
    for (int i = 0; i < LAYER_COUNT; i++)
        update_layer(game, i);
    sfRenderWindow_display(game->window->window);
}

int main(void)
{
    pirate_quest_t game;

    if (init_window(&game) == FALSE)
        return my_puterr("Error: Could not allocate memory for window.\n");
    if (game.window->window == NULL) {
        free_game(&game);
        return my_puterr("Error: Could not create window. This could be "
            "due to a lack of memory. Or incompatible hardware.\n");
    }
    init_icon(game.window);
    init_layers();
    init_squares(&game);
    sfRenderWindow_setFramerateLimit(game.window->window, 120);
    while (sfRenderWindow_isOpen(game.window->window))
        update(&game);
    free_game(&game);
    return FALSE;
}
