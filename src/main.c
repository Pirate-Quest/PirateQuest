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
    free_dialogues_registry(game);
    free_interlocutors_registry(game);
    free_dialogue_box(game);
    destroy_sounds(game);
    sfTexture_destroy(game->tileset);
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

    game->settings = import_settings();
    if (window == NULL || camera == NULL || game->settings == NULL) {
        my_puterr("Error: Could not allocate memory for window."
            " or settings.\n");
        return FALSE;
    }
    window->window = sfRenderWindow_create(get_sfvideo_mode(
        game->settings->resolution), "Pirate Quest", sfClose, NULL);
    camera->map_position = (sfVector2i){19, 69};
    camera->pos_in_tile = (sfVector2f){0.0, 0.0};
    camera->zoom = get_resolution(game).zoom;
    game->window = window;
    game->camera = camera;
    game->task_daemon = new_daemon_task();
    game->tasks = my_list_create(&free_task);
    game->tileset = sfTexture_createFromFile("assets/map/tileset.png", NULL);
    return TRUE;
}

int init_splash_screen(pirate_quest_t *game)
{
    resolution_t resolution = get_resolution(game);
    sfTexture *splash = sfTexture_createFromFile("assets/W.png", NULL);

    game->timer = sfClock_create();
    game->scr = sfSprite_create();
    sfSprite_setTexture(game->scr, splash, sfTrue);
    sfSprite_setScale(game->main_menu->background, (sfVector2f){
        (float) resolution.width / 1920, (float) resolution.height / 1080});
    return 0;
}

void draw_splash_screen(pirate_quest_t *game)
{
    sfRenderWindow_clear(game->window->window, sfBlack);
    sfRenderWindow_drawSprite(game->window->window, game->scr, NULL);
    sfRenderWindow_display(game->window->window);
}

static void update2(pirate_quest_t *game)
{
    for (int i = 0; i < LAYER_COUNT; i++)
        for (int y = 0; y < RENDER_HEIGHT; y++)
            draw_front_tiles_object(game, i, y);
    draw_inv(game);
    update_main_menu(game);
    show_buttons(game);
    select_music(game);
}

static void update(pirate_quest_t *game)
{
    if (sfClock_getElapsedTime(game->timer).microseconds < 2000000) {
        draw_splash_screen(game);
        return;
    }
    update_listeners(game);
    sfRenderWindow_clear(game->window->window, sfBlack);
    for (int i = 0; i < LAYER_COUNT; i++)
        update_layer(game, i);
    for (int i = 0; i < LAYER_COUNT; i++)
        for (int y = 0; y < RENDER_HEIGHT; y++)
            draw_back_tiles_object(game, i, y);
    update_player(game);
    update2(game);
    update_dialogue_visuals(game);
    sfRenderWindow_display(game->window->window);
    update_tasks(game);
    update_key_pressed(game);
}

static int init_game(pirate_quest_t *game)
{
    game->state = GAME_STATE_MENU;
    game->current_gui = MAIN_MENU;
    game->font = sfFont_createFromFile("assets/font/Caribbean.ttf");
    if (game->font == NULL)
        return 1;
    init_dialogues_registry(game);
    init_interlocutors_registry(game);
    init_dialogue_box(game);
    init_sound(game);
    init_icon(game->window);
    init_main_menu(game);
    init_buttons(game);
    init_collisions(game);
    init_layers();
    init_squares(game);
    game->player = init_player(game);
    init_splash_screen(game);
    init_inv(game);
    init_musique(game);
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
