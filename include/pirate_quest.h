/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** pirate_quest.h
*/

#ifndef PIRATE_QUEST_H
    #define PIRATE_QUEST_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "commons.h"
    #include "render.h"
    #include "map.h"
    #include "settings.h"

typedef struct pirate_quest_s pirate_quest_t;

typedef struct task_s {
    int (*on_tick)(pirate_quest_t *, hashtable_t *);
    int (*on_end)(pirate_quest_t *, hashtable_t *);
    double second_interval;
    int execution_count;
    hashtable_t *data;
} task_t;

typedef struct task_builder_s {
    int (*on_tick)(pirate_quest_t *, hashtable_t *);
    int (*on_end)(pirate_quest_t *, hashtable_t *);
    double second_interval;
    int execution_count;
} task_builder_t;

// scheduler/*.c
task_t *register_task(pirate_quest_t *game, const task_builder_t *builder,
    hashtable_t *data);
void unregister_task(pirate_quest_t *game, task_t *task);
void free_task(void *data);
void update_tasks(pirate_quest_t *game);

typedef struct task_daemon_s {
    sfClock* clock;
    int last_update;
    double seconds;
} task_daemon_t;

typedef struct player_s {
    sfSprite *sprite;
    sfVector2f pos;
    int is_moving;
    sfVector2f size;
    sfIntRect rect;
    sfTexture *texture;
    direction_t direction;
    task_t *task;
} player_t;

typedef struct button_s button_t;

typedef struct button_builder_s {
    char *path;
    sfIntRect rect;
    char *text;
    sfVector2f text_pos;
    int text_size;
    sfColor text_color;
    float scale;
    void(*callback)(
        pirate_quest_t *game,
        const struct button_builder_s *button,
        button_t *buttons
    );
} button_builder_t;

typedef enum {
    BUTTON_IDLE,
    BUTTON_HOVER,
    BUTTON_ACTIVE,
    BUTTON_HIDDEN
} button_status_t;

struct button_s {
    sfSprite *sprite;
    button_status_t status;
    sfTexture *texture;
    sfText *text;
};

// gui/button/button_registry.c
void init_buttons(pirate_quest_t *game);
void show_buttons(pirate_quest_t *game);
void button_event(sfEvent event, pirate_quest_t *game);

typedef sfSprite *square_t[LAYER_COUNT][RENDER_HEIGHT][RENDER_WIDTH];
typedef int collision_t[MAP_HEIGHT][MAP_WIDTH];
typedef struct sound_impl_s sound_impl_t;

struct pirate_quest_s {
    render_window_t *window;
    camera_t *camera;
    square_t square;
    settings_t *settings;
    player_t *player;
    my_list_t *tasks;
    task_daemon_t *task_daemon;
    collision_t collision;
    sfTexture *tileset;
    button_t *buttons;
    sfFont *font;
    sound_impl_t *sounds;
};

typedef struct asset_s {
    char *key;
    char *path;
} asset_t;

// map/rect_from_id.c
sfIntRect rect_from_id(int id, int offset);

// main.c
int get_tile_id(int i, int y, int x);

// map/tiles_manager.c
void init_squares(pirate_quest_t *game);
void update_layer(pirate_quest_t *game, int i);

// player/player_sprite.c
player_t *init_player(pirate_quest_t *game);
void update_direction(player_t *player, direction_t direction);
int update_player(pirate_quest_t *game);
int on_player_tick(pirate_quest_t *game, hashtable_t *_);

// utils/texture_util.c
void move_rect(sfIntRect *rect, int offset, int start, int max_value);

// utils/calculate_pos.c
sfVector2f calculate_position(int x, int y, pirate_quest_t *game);

// map/collision.c
void init_collisions(pirate_quest_t *game);

// object/tile_object.c
void draw_front_tiles_object(pirate_quest_t *game, int layer, int y);
void draw_back_tiles_object(pirate_quest_t *game, int layer, int y);

// render/render_window.c
resolution_t get_resolution(pirate_quest_t *game);

typedef enum {
    ZIPCLICK_SOUND,
} sound_key_t;

typedef struct sound_s {
    sound_key_t key;
    char *path;
} sound_t;

struct sound_impl_s {
    sound_key_t key;
    sfSound *sound;
};

// sound/sound_registry.c
void init_sound(pirate_quest_t *game);
void play_sound(pirate_quest_t *game, sound_key_t key);
void destroy_sounds(pirate_quest_t *game);

#endif /* PIRATE_QUEST_H */
