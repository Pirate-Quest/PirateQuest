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
    if (game->settings != NULL)
        free(game->settings);
}

static task_daemon_t *new_daemon_task(void)
{
    task_daemon_t *daemon = malloc(sizeof(task_daemon_t));

    *daemon = (task_daemon_t) {
            .clock = sfClock_create(),
            .last_update = 0,
            .seconds = 0.0
    };
    return daemon;
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
    camera->map_position = (sfVector2i){95, 86};
    camera->pos_in_tile = (sfVector2f){0.0, 0.0};
    camera->zoom = 2.5;
    game->window = window;
    game->camera = camera;
    game->task_daemon = new_daemon_task();
    game->tasks = my_list_create(&free_task);
    return TRUE;
}

static void update(pirate_quest_t *game)
{
    update_listeners(game);
    sfRenderWindow_clear(game->window->window, sfBlack);
    for (int i = 0; i < LAYER_COUNT; i++)
        update_layer(game, i);
    update_player(game);
    sfRenderWindow_display(game->window->window);
    update_tasks(game);
    update_key_pressed(game);
}

static int init_game(pirate_quest_t *game)
{
    init_icon(game->window);
    init_collisions(game);
    init_layers();
    init_squares(game);
    game->settings = import_settings();
    if (game->settings == NULL) {
        return my_puterr("Error: Could not import settings.\n");
    }
    game->player = init_player(game);
    return 0;
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
    if (init_game(&game) != 0) {
        free_game(&game);
        return my_puterr("Error: Could not initialize game.\n");
    }
    sfRenderWindow_setFramerateLimit(game.window->window, 120);
    while (sfRenderWindow_isOpen(game.window->window))
        update(&game);
    write_settings(game.settings);
    free_game(&game);
    return FALSE;
}
