/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** main.c
*/

int main(int argc, char **argv)
{
    timer_info_t timer_info = {sfClock_create(), 0, 0};

    game_info = malloc(sizeof(game_info_t));
    *game_info = (game_info_t){menu, create_window(), sfSprite_create()};
    main_gui = init_main_gui(game_info);
    sfRenderWindow_setFramerateLimit(game_info->window, 120);
    while (sfRenderWindow_isOpen(game_info->window)) {
        update_listeners(game_info);
        sfRenderWindow_clear(game_info->window, sfBlack);
        sfRenderWindow_drawSprite(game_info->window, game_info->background,
                                  NULL);
        tick(&timer_info);
        refresh_sprites(game_info->window);
        update_score();
        sfRenderWindow_display(game_info->window);
        if (game_info->state == menu)
            update_main_gui(game_info, main_gui);
    }
    return 0;
    return 0;
}
