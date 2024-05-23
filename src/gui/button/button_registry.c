/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** button_registry.c
*/

#include <SFML/Graphics.h>
#include "../../../include/pirate_quest.h"

const button_builder_t buttons[] = {
    {
        .path = "assets/button/basic_btn.png",
        .rect = (sfIntRect){100, 100, 401, 174},
        .text = "Play",
        .text_pos = (sfVector2f){45, 15},
        .text_size = 40,
        .text_color = (sfColor){255, 255, 255, 255},
        .scale = 0.5,
        .callback = &main_menu_btns_event,
        .show_btn = &show_main_menu_btns
    },
    {
        .path = "assets/button/basic_btn.png",
        .rect = (sfIntRect){100, 200, 401, 174},
        .text = "Settings",
        .text_pos = (sfVector2f){22, 20},
        .text_size = 30,
        .text_color = (sfColor){255, 255, 255, 255},
        .scale = 0.5,
        .callback = &main_menu_btns_event,
        .show_btn = &show_main_menu_btns
    },
    {
        .path = "assets/button/basic_btn.png",
        .rect = (sfIntRect){100, 300, 401, 174},
        .text = "Exit",
        .text_pos = (sfVector2f){45, 15},
        .text_size = 40,
        .text_color = (sfColor){255, 255, 255, 255},
        .scale = 0.5,
        .callback = &main_menu_btns_event,
        .show_btn = &show_main_menu_btns
    },
    {
        .path = "assets/button/basic_btn.png",
        .rect = (sfIntRect){100, 100, 401, 174},
        .text = "Save-1",
        .text_pos = (sfVector2f){25, 15},
        .text_size = 40,
        .text_color = (sfColor){255, 255, 255, 255},
        .scale = 0.5,
        .callback = &save_menu_btns_event,
        .show_btn = &show_save_menu_btns
    },
    {
        .path = "assets/button/basic_btn.png",
        .rect = (sfIntRect){100, 200, 401, 174},
        .text = "Save-2",
        .text_pos = (sfVector2f){25, 15},
        .text_size = 40,
        .text_color = (sfColor){255, 255, 255, 255},
        .scale = 0.5,
        .callback = &save_menu_btns_event,
        .show_btn = &show_save_menu_btns
    },
    {
        .path = "assets/button/basic_btn.png",
        .rect = (sfIntRect){100, 300, 401, 174},
        .text = "Save-3",
        .text_pos = (sfVector2f){25, 15},
        .text_size = 40,
        .text_color = (sfColor){255, 255, 255, 255},
        .scale = 0.5,
        .callback = &save_menu_btns_event,
        .show_btn = &show_save_menu_btns
    },
    {
        .path = "assets/button/basic_btn.png",
        .rect = (sfIntRect){100, 400, 401, 174},
        .text = "Save-4",
        .text_pos = (sfVector2f){25, 15},
        .text_size = 40,
        .text_color = (sfColor){255, 255, 255, 255},
        .scale = 0.5,
        .callback = &save_menu_btns_event,
        .show_btn = &show_save_menu_btns
    },
    {
        .path = "assets/button/basic_btn.png",
        .rect = (sfIntRect){100, 550, 401, 174},
        .text = "Back",
        .text_pos = (sfVector2f){25, 15},
        .text_size = 40,
        .text_color = (sfColor){255, 255, 255, 255},
        .scale = 0.5,
        .callback = &back_btn_event,
        .show_btn = &show_back_btn
    },
    {
        .path = "assets/button/basic_btn.png",
        .rect = (sfIntRect){600, 200, 401, 174},
        .text = "Resume",
        .text_pos = (sfVector2f){25, 15},
        .text_size = 40,
        .text_color = (sfColor){255, 255, 255, 255},
        .scale = 0.6,
        .callback = &game_menu_resume,
        .show_btn = &show_game_menu_btns
    },
        {
        .path = "assets/button/basic_btn.png",
        .rect = (sfIntRect){600, 300, 401, 174},
        .text = "Save",
        .text_pos = (sfVector2f){25, 15},
        .text_size = 40,
        .text_color = (sfColor){255, 255, 255, 255},
        .scale = 0.6,
        .callback = &game_menu_save,
        .show_btn = &show_game_menu_btns
    },
        {
        .path = "assets/button/basic_btn.png",
        .rect = (sfIntRect){600, 400, 401, 174},
        .text = "Settings",
        .text_pos = (sfVector2f){25, 15},
        .text_size = 40,
        .text_color = (sfColor){255, 255, 255, 255},
        .scale = 0.6,
        .callback = &game_menu_settings,
        .show_btn = &show_game_menu_btns
    },
        {
        .path = "assets/button/basic_btn.png",
        .rect = (sfIntRect){600, 500, 401, 174},
        .text = "Exit",
        .text_pos = (sfVector2f){25, 15},
        .text_size = 40,
        .text_color = (sfColor){255, 255, 255, 255},
        .scale = 0.6,
        .callback = &game_menu_exit,
        .show_btn = &show_game_menu_btns
    }
};

const int button_count = sizeof(buttons) / sizeof(button_builder_t);

static void update_texture(pirate_quest_t *game, int i, int status)
{
    if (status == BUTTON_ACTIVE) {
        sfSprite_setTextureRect(game->buttons[i].sprite,
            (sfIntRect){buttons[i].rect.width * 2, 0,
            buttons[i].rect.width, buttons[i].rect.height});
    } else if (status == BUTTON_HOVER) {
        sfSprite_setTextureRect(game->buttons[i].sprite,
            (sfIntRect){buttons[i].rect.width, 0,
            buttons[i].rect.width, buttons[i].rect.height});
    } else {
        sfSprite_setTextureRect(game->buttons[i].sprite,
            (sfIntRect){0, 0, buttons[i].rect.width, buttons[i].rect.height});
    }
}

static void init_text(pirate_quest_t *game, int i)
{
    sfText_setString(game->buttons[i].text, buttons[i].text);
    sfText_setFont(game->buttons[i].text, game->font);
    sfText_setCharacterSize(game->buttons[i].text, buttons[i].text_size);
    sfText_setColor(game->buttons[i].text, buttons[i].text_color);
    sfText_setPosition(game->buttons[i].text, (sfVector2f){
        buttons[i].rect.left + buttons[i].text_pos.x, buttons[i].rect.top +
        buttons[i].text_pos.y});
}

void init_buttons(pirate_quest_t *game)
{
    game->buttons = malloc(sizeof(button_t) * button_count);
    for (int i = 0; i < button_count; i++) {
        game->buttons[i].texture = sfTexture_createFromFile(
            buttons[i].path, NULL);
        game->buttons[i].sprite = sfSprite_create();
        sfSprite_setTexture(game->buttons[i].sprite,
            game->buttons[i].texture, sfTrue);
        game->buttons[i].status = BUTTON_IDLE;
        sfSprite_setPosition(game->buttons[i].sprite,
            (sfVector2f){buttons[i].rect.left, buttons[i].rect.top});
        sfSprite_setScale(game->buttons[i].sprite,
            (sfVector2f){buttons[i].scale, buttons[i].scale});
        update_texture(game, i, game->buttons[i].status);
        game->buttons[i].text = sfText_create();
        init_text(game, i);
    }
}

void show_buttons(pirate_quest_t *game)
{
    for (int i = 0; i < button_count; i++) {
        if (game->buttons[i].status == BUTTON_HIDDEN)
            continue;
        if (buttons[i].show_btn != NULL
            && !buttons[i].show_btn(game, &buttons[i], game->buttons)) {
            game->buttons[i].status = BUTTON_HIDDEN;
            continue;
        }
        sfRenderWindow_drawSprite(game->window->window,
            game->buttons[i].sprite, NULL);
        sfRenderWindow_drawText(game->window->window,
            game->buttons[i].text, NULL);
    }
}

static void button_hover(pirate_quest_t *game, sfVector2f mouse_pos)
{
    for (int i = 0; i < button_count; i++) {
        if (game->buttons[i].status == BUTTON_ACTIVE)
            continue;
        if ((mouse_pos.x >= buttons[i].rect.left) && mouse_pos.x <=
            (buttons[i].rect.left + (buttons[i].rect.width * buttons[i].scale))
            && mouse_pos.y >= buttons[i].rect.top && mouse_pos.y <=
            buttons[i].rect.top + buttons[i].rect.height * buttons[i].scale) {
            game->buttons[i].status = BUTTON_HOVER;
            update_texture(game, i, BUTTON_HOVER);
        } else {
            game->buttons[i].status = BUTTON_IDLE;
            update_texture(game, i, BUTTON_IDLE);
        }
    }
}

static void button_pressed(pirate_quest_t *game, sfVector2f mouse_pos)
{
    for (int i = 0; i < button_count; i++) {
        if (game->buttons[i].status != BUTTON_HOVER)
            continue;
        game->buttons[i].status = BUTTON_ACTIVE;
        update_texture(game, i, BUTTON_ACTIVE);
        play_sound(game, ZIPCLICK_SOUND);
        if (buttons[i].callback != NULL)
            buttons[i].callback(game, &buttons[i], game->buttons);
    }
    for (int i = 0; i < button_count; i++) {
        button_hover(game, mouse_pos);
    }
}

static void unactive_buttons(pirate_quest_t *game, sfVector2f mouse_pos)
{
    for (int i = 0; i < button_count; i++) {
        game->buttons[i].status = BUTTON_IDLE;
        button_hover(game, mouse_pos);
    }
}

sfVector2f get_mouse_pos(pirate_quest_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(
            game->window->window
    );

    return (sfVector2f) {mouse_pos.x, mouse_pos.y};
}

void button_event(sfEvent event, pirate_quest_t *game)
{
    if (game->buttons == NULL)
        return;
    if (event.type == sfEvtMouseMoved)
        button_hover(game, get_mouse_pos(game));
    if (event.type == sfEvtMouseButtonPressed)
        button_pressed(game, get_mouse_pos(game));
    if (event.type == sfEvtMouseButtonReleased)
        unactive_buttons(game, get_mouse_pos(game));
}
