/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** pirate_quest.h
*/

#ifndef PIRATE_QUEST_H
    #define PIRATE_QUEST_H

    #include <SFML/Audio/Types.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdio.h>
    #include "commons.h"
    #include "render.h"
    #include "map.h"
    #include "settings.h"
    #include "gamerules.h"
    #include "item.h"

typedef struct pirate_quest_s pirate_quest_t;

typedef enum {
    IN_GAME,
    MAIN_MENU,
    SAVE_MENU,
    GAME_MENU,
    SETTINGS_MENU
} current_gui_t;

typedef enum {
    GAME_STATE_MENU,
    GAME_STATE_PLAYING,
    GAME_STATE_TRANSITION
} game_state_t;

typedef struct task_s {
    int (*on_tick)(pirate_quest_t *, void *, int);
    int (*on_end)(pirate_quest_t *, void *);
    double second_interval;
    int execution_count;
    void *data;
} task_t;

typedef struct task_builder_s {
    int (*on_tick)(pirate_quest_t *, void *, int);
    int (*on_end)(pirate_quest_t *, void *);
    double second_interval;
    int execution_count;
} task_builder_t;

// scheduler/*.c
task_t *register_task(pirate_quest_t *game, const task_builder_t *builder,
    void *data);
void unregister_task(pirate_quest_t *game, task_t *task);
void free_task(void *data);
void update_tasks(pirate_quest_t *game);

typedef struct task_daemon_s {
    sfClock* clock;
    int last_update;
    double seconds;
} task_daemon_t;

typedef enum {
    MENU_PHASE,
    TUTORIAL_PHASE,
    MARKET_PHASE,
    TAVERN_PHASE,
    DESERT_PHASE,
    BOSS_PHASE
} game_phase_t;

typedef struct game_phase_info_s {
    game_phase_t phase;
    sfVector2i pos_in_map;
} game_phase_info_t;

typedef enum {
    NONE_ITEM,
    SWORD_ITEM,
    KEY_ITEM,
    LETTER_ITEM,
    PLANK_ITEM,
    TUTO_SWORD_ITEM,
    SAIL_ITEM,
    WHEEL_ITEM
} inventory_item_t;

typedef struct inventory_item_registry_s {
    inventory_item_t item;
    char *name;
    char *path;
} inventory_item_registry_t;

    #define SLOT_COUNT 5
    #define TOTAL_ITEM 8

typedef struct inv_bar_s {
    sfTexture *texture_bar;
    sfSprite *sprite_bar;
    sfSprite *slots[SLOT_COUNT];
    inventory_item_t slots_id[SLOT_COUNT];
} inv_bar_t;

typedef struct player_inventory_s {
    inventory_item_t slots[SLOT_COUNT];
} player_inventory_t;

typedef enum {
    MENU_MUSIC,
    TUTO_MUSIC,
    MARKET_MUSIC,
    TAVERN_MUSIC,
    DESERT_MUSIC,
    BOSS_MUSIC
} music_t;

typedef struct music_registry_s {
    music_t item;
    char *name;
    char *path;
} music_registry_t;

    #define TOTAL_MUSIC 6

typedef struct music_tab_s {
    sfMusic *musics[TOTAL_MUSIC];
} music_tab_t;

void init_musique(pirate_quest_t *game);
void music_player(pirate_quest_t *game, int music);
void select_music(pirate_quest_t *game);

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
    int is_attacking;
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

typedef struct square_tile_s {
    sfSprite *sprite;
    sfVector2i pos;
} square_tile_t;

typedef square_tile_t *square_t[LAYER_COUNT][RENDER_HEIGHT][RENDER_WIDTH];
typedef int collision_t[MAP_HEIGHT][MAP_WIDTH];
typedef struct sound_impl_s sound_impl_t;
typedef struct main_menu_s main_menu_t;
typedef struct settings_menu_s settings_menu_t;
typedef struct dialogue_impl_s dialogue_impl_t;
typedef struct interlocutor_impl_s interlocutor_impl_t;
typedef struct dialogue_box_s dialogue_box_t;
typedef struct dialogue_service_s dialogue_service_t;

struct pirate_quest_s {
    game_state_t state;
    current_gui_t current_gui;
    main_menu_t *main_menu;
    main_menu_t *game_menu;
    settings_menu_t *settings_menu;
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
    item_texture_t item_texture[TOTAL_ITEM];
    inv_bar_t *inv_bar;
    interlocutor_impl_t *interlocutors;
    dialogue_box_t *dialogue_box;
    dialogue_service_t *dialogue_service;
    sfSprite *scr;
    sfClock *timer;
    my_list_t *enemies;
    sfTexture *enemy_texture;
    music_tab_t *music;
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
square_tile_t *get_square(pirate_quest_t *game, sfVector2i pos);

// player/player_sprite.c
player_t *init_player(pirate_quest_t *game);
void update_direction(player_t *player, direction_t direction);
int update_player(pirate_quest_t *game);
int on_player_tick(pirate_quest_t *game, void *_, int exec_count);

typedef struct enemy_s enemy_t;

// player/player_combat.c
void inflict_enemy_damage(pirate_quest_t *game, enemy_t *enemy, float damage);
void attack_enemies(pirate_quest_t *game, float damage);

// utils/texture_util.c
int move_rect(sfIntRect *rect, int offset, int start, int max_value);

// utils/csfml_str.c
sfUint32 *csfml_strndup(sfUint32 *str, int n);
void csfml_replace_char(sfUint32 *str, sfUint32 find, sfUint32 replace);
int csfml_strlen(sfUint32 *content);

// utils/utf8_to_32.c
void utf8_to_32(const char *begin, const char *end, sfUint32 *output);

// utils/calculate_pos.c
sfVector2f calculate_position(int x, int y, pirate_quest_t *game);
int pos_is_in_square(pirate_quest_t *game,
    int x, int y, sfVector2f sprite_pos);
int player_is_in_square_rect(pirate_quest_t *game,
    sfVector2i pos1, sfVector2i pos2);
int player_is_in_square(pirate_quest_t *game, int x, int y);
float distance_between_points(sfVector2f pos1, sfVector2f pos2);

// utils/square_tile_from_pos.c
square_tile_t *get_square_from_pos(pirate_quest_t *game, sfVector2f pos);

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

struct settings_menu_s {
    sfTexture *splash_texture;
    sfSprite *background;
    sfBool listen_key;
    sfKeyCode key_code;
    int index_key;
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

// gui/interface/game_menu.c
int show_game_menu_btns(pirate_quest_t *game,
    const button_builder_t *_, button_t *__);
void init_game_menu(pirate_quest_t *game);
void input_game_menu(pirate_quest_t *game);
void show_game_menu(pirate_quest_t *game);

// gui/interface/settings_menu.c
void init_settings_menu(pirate_quest_t *game);
void settings_menu_btns_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_);
int show_settings_menu_btns(pirate_quest_t *game,
    const button_builder_t *_, button_t *__);
void update_settings_menu(pirate_quest_t *game);
void change_setting(pirate_quest_t *game, sfKeyCode new_key);

// gui/button/game_menu_button.c
void game_menu_resume_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_);
void game_menu_save_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_);
void game_menu_settings_event(pirate_quest_t *game,
    const button_builder_t *button, button_t *_);
void game_menu_exit_event(pirate_quest_t *game,
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

// settings/settings_import.c
void write_settings_index(pirate_quest_t *game, int index, sfKeyCode key);

typedef enum {
    UNKNOWN,
    ME,
    FRANCK,
    ANA,
    ASTORA,
    TUTO,
    MAYOR,
    SANDRINE,
    MICHEL,
    DOUGLAS,
    MARIE,
    JULIE,
    GROGNON,
    OTIS,
    GUARDE,
    LOCAL,
    SENIL,
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
    sfUint32 *content;
    int time;
} dialogue_t;

typedef enum {
    NONE_DIALOGUE,
    TUTORIAL_1,
    FIRST_NPC,
    COMMAND,
    MAYOR_DG,
    SOLO_SWORD,
    FIRST_WOMEN,
    MICH,
    DOUGLA,
    MARI,
    GRE,
    GROGN,
    MONO,
    GUARD,
    END_GAME,
    CHEST,
    BEACH,
    LOC,
    OLD,
    SEN,
    DESERT,
    CAVE,
} dialogue_enum_t;

typedef struct dialogue_builder_s {
    dialogue_enum_t dialogue;
    const char *file_path;
} dialogue_builder_t;

extern const dialogue_builder_t dialogues[];
extern const int dialogue_count;
extern const int intrlcutors;

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

    #define IS_DIALOGUE_PLAYING(g) ((g)->dialogue_service->is_dialogue_playing)

// dialogues/dialogue_player.c
void init_dialogue_box(pirate_quest_t *game);
void free_dialogue_box(pirate_quest_t *game);
void update_dialogue_visuals(pirate_quest_t *game);
void play_dialogue(pirate_quest_t *game, dialogue_impl_t *dialogue, int i);

// dialogues/dialogues_service.c
dialogue_impl_t *get_dialogue(pirate_quest_t *game, dialogue_enum_t dialogue);
dialogue_t *get_current_dialogue(pirate_quest_t *game);

//teleportation of players and npc dialogue features
void dialogue_npc(sfEvent event, pirate_quest_t *game);
void tavern_telep(sfEvent event, pirate_quest_t *game);
void beach_telep(sfEvent event, pirate_quest_t *game);
void cave_telep(sfEvent event, pirate_quest_t *game);
void dialogue_npc_two(sfEvent event, pirate_quest_t *game);
void dialogue_npc_three(sfEvent event, pirate_quest_t *game);
void dialogue_npc_four(sfEvent event, pirate_quest_t *game);
void dialogue_npc_guard(sfEvent event, pirate_quest_t *game);

typedef struct node_t {
    sfVector2i pos;
    int g;
    int h;
    int f;
    struct node_t *parent;
} node_t;

typedef struct {
    node_t *current;
    node_t **open_list;
    int *open_size;
    node_t **closed_list;
    int closed_size;
    sfVector2i end;
} process_neighbors_builder_t;

typedef struct {
    node_t *current;
    sfVector2i neighbor_pos;
    int tentative_g;
    sfVector2i end;
    node_t **open_list;
    int *open_size;
    int in_open;
} create_add_neighbor_builder_t;

typedef struct {
    int s;
    int closed_size;
    int current_index;
    node_t *current;
    node_t *cl[MAP_HEIGHT * MAP_WIDTH];
} path_finding_builder_t;

// algorithm/path_finding.c
sfVector2i *find_path(pirate_quest_t *g, sfVector2i start, sfVector2i end);

struct enemy_s {
    sfSprite *sprite;
    sfVector2i square_pos;
    sfVector2f pos_in_tile;
    sfVector2f pos;
    sfVector2i pos_goal;
    sfVector2f pos_in_tile_goal;
    sfVector2i super_pos_goal;
    int is_moving;
    int attacking;
    sfVector2f size;
    sfIntRect rect;
    direction_t direction;
    task_t *task;
    float health;
};

// enemy/enemy.c
int on_enemy_tick(pirate_quest_t *game, void *data, int _);
void update_enemy_direction(enemy_t *enemy, direction_t direction);
void update_enemies(pirate_quest_t *game);

// enemy/enemy_utils.c
sfVector2i get_random_pos(pirate_quest_t *game);
direction_t get_best_attack_direction(pirate_quest_t *game, enemy_t *enemy);
void free_enemy(void *data);
void move_enemy(pirate_quest_t *game, enemy_t *enemy);
void update_pos_goal(pirate_quest_t *game, enemy_t *enemy);

// enemy/enemy_utils2.c
void apply_knockback(pirate_quest_t *game, enemy_t *enemy);

// inventory
void init_inv(pirate_quest_t *game);
void draw_inv(pirate_quest_t *game);
int add_item(pirate_quest_t *game, int item);
int is_item(pirate_quest_t *game, int item);
int remove_item(pirate_quest_t *game, int item);

void reload_res(pirate_quest_t *game);
void update_enemies_sprite_resolution(pirate_quest_t *game);
void update_button_sprite_resolution(pirate_quest_t *game);
void update_dialogue_sprites_resolution(pirate_quest_t *game);

#endif /* PIRATE_QUEST_H */
