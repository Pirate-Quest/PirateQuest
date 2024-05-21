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
    #include <stdio.h>
    #include "commons.h"
    #include "render.h"
    #include "map.h"
    #include "settings.h"
    #include "gamerules.h"

typedef struct pirate_quest_s pirate_quest_t;

typedef enum {
    MAIN_MENU,
    SAVE_MENU,
    SETTINGS_MENU,
} current_gui_t;

typedef enum {
    GAME_STATE_MENU,
    GAME_STATE_PLAYING,
    GAME_STATE_TRANSITION
} game_state_t;

typedef struct task_s {
    int (*on_tick)(pirate_quest_t *, hashtable_t *, int);
    int (*on_end)(pirate_quest_t *, hashtable_t *);
    double second_interval;
    int execution_count;
    hashtable_t *data;
} task_t;

typedef struct task_builder_s {
    int (*on_tick)(pirate_quest_t *, hashtable_t *, int);
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

typedef enum {
    TUTORIAL_PHASE,
    VILLAGE_PHASE
} game_phase_t;

typedef struct game_phase_info_s {
    game_phase_t phase;
    sfVector2i pos_in_map;
} game_phase_info_t;

typedef enum {
    NONE_ITEM,
    SWORD_ITEM,
} inventory_item_t;

typedef struct inventory_item_registry_s {
    inventory_item_t item;
    char *name;
    char *path;
} inventory_item_registry_t;

typedef struct inventory_item_impl_s {
    sfSprite *sprite;
    sfTexture *texture;
} inventory_item_impl_t;

    #define SLOT_COUNT 5

typedef struct player_inventory_s {
    inventory_item_t slots[SLOT_COUNT];
} player_inventory_t;

typedef struct player_data_s {
    game_phase_t phase;
    player_xp_t xp;
    player_inventory_t inventory;
    int resistance_lvl;
    int strength_lvl;
    int speed_lvl;
} player_data_t;

typedef struct player_s {
    sfSprite *sprite;
    sfVector2f pos;
    int is_moving;
    sfVector2f size;
    sfIntRect rect;
    sfTexture *texture;
    direction_t direction;
    task_t *task;
    player_data_t *data;
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
    void (*callback)(
        pirate_quest_t *game,
        const struct button_builder_s *button,
        button_t *buttons
    );
    int (*show_btn)(
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
typedef struct main_menu_s main_menu_t;
typedef struct dialogue_impl_s dialogue_impl_t;
typedef struct interlocutor_impl_s interlocutor_impl_t;
typedef struct dialogue_box_s dialogue_box_t;
typedef struct dialogue_service_s dialogue_service_t;

struct pirate_quest_s {
    game_state_t state;
    current_gui_t current_gui;
    main_menu_t *main_menu;
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
    dialogue_impl_t *dialogues;
    interlocutor_impl_t *interlocutors;
    dialogue_box_t *dialogue_box;
    dialogue_service_t *dialogue_service;
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
int on_player_tick(pirate_quest_t *game, hashtable_t *_, int exec_count);

// utils/texture_util.c
void move_rect(sfIntRect *rect, int offset, int start, int max_value);

// utils/calculate_pos.c
sfVector2f calculate_position(int x, int y, pirate_quest_t *game);
int player_is_in_square(pirate_quest_t *game, int x, int y);

// map/collision.c
void init_collisions(pirate_quest_t *game);

// object/tile_object.c
void draw_front_tiles_object(pirate_quest_t *game, int layer, int y);
void draw_back_tiles_object(pirate_quest_t *game, int layer, int y);

// render/render_window.c
resolution_t get_resolution(pirate_quest_t *game);

typedef enum {
    ZIPCLICK_SOUND,
    HURT_SOUND
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

struct main_menu_s {
    sfTexture *background_texture;
    sfSprite *background;
};

// gui/interface/main_menu.c
int show_main_menu_btns(pirate_quest_t *game,
    const button_builder_t *_, button_t *__);
void main_menu_btns_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_);
void init_main_menu(pirate_quest_t *game);
void update_main_menu(pirate_quest_t *game);

// gui/interface/main_menu.c
int show_save_menu_btns(pirate_quest_t *game,
    const button_builder_t *_, button_t *__);
void save_menu_btns_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_);

// game/game_save.c
void load_game(pirate_quest_t *game, char *id);

// game/game_phase.c
sfVector2i get_pos_from_phase(game_phase_t phase);

// gui/interface/back_button.c
int show_back_btn(pirate_quest_t *game,
    const button_builder_t *_, button_t *__);
void back_btn_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_);

typedef enum {
    UNKNOWN,
    ME,
    FRANCK,
    ANA,
} dialogue_interlocutor_t;

typedef struct interlocutor_builder_s {
    dialogue_interlocutor_t interlocutor;
    char *name;
    char *file_path;
    float scale;
    sfVector2f origin;
    sfVector2f size;
} interlocutor_builder_t;

struct interlocutor_impl_s {
    const dialogue_interlocutor_t *interlocutor;
    sfTexture *texture;
    sfSprite *sprite;
    sfText *name_text;
    sfRectangleShape *name_bg;
};

typedef struct dialogue_s {
    FILE *file;
    dialogue_interlocutor_t speaker;
    char *content;
    int time;
} dialogue_t;

typedef enum {
    NONE_DIALOGUE,
    TUTORIAL_1
} dialogue_enum_t;

typedef struct dialogue_builder_s {
    dialogue_enum_t dialogue;
    const char *file_path;
} dialogue_builder_t;

extern const dialogue_builder_t dialogues[];
extern const int dialogue_count;

struct dialogue_impl_s {
    dialogue_enum_t dialogue;
    dialogue_t *dialogues;
    int dialogue_count;
};

typedef struct dialogue_box_s {
    sfRectangleShape *box;
    sfText *text;
    sfFont *font;
} dialogue_box_t;

struct dialogue_service_s {
    int is_dialogue_playing;
    dialogue_enum_t current_dialogue;
    int current_dialogue_index;
    int current_dialogue_text_index;
};

// dialogues/dialogues_parser.c
dialogue_t *parse_dialogue_file(const char *file_path, int *dialogue_count);
void free_dialogues(dialogue_t *dialogues, int dialogue_count);

// dialogues/dialogues_registry.c
void init_interlocutors_registry(pirate_quest_t *game);
void free_interlocutors_registry(pirate_quest_t *game);
void draw_interlocutor(pirate_quest_t *game, dialogue_interlocutor_t i);
void init_dialogues_registry(pirate_quest_t *game);
void free_dialogues_registry(pirate_quest_t *game);

// dialogues/dialogue_player.c
void init_dialogue_box(pirate_quest_t *game);
void free_dialogue_box(pirate_quest_t *game);
void update_dialogue_visuals(pirate_quest_t *game);
void play_dialogue(pirate_quest_t *game, dialogue_impl_t *dialogue, int i);

// dialogues/dialogues_service.c
dialogue_impl_t *get_dialogue(pirate_quest_t *game, dialogue_enum_t dialogue);
dialogue_t *get_current_dialogue(pirate_quest_t *game);

#endif /* PIRATE_QUEST_H */
