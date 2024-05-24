/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** render.h
*/

#ifndef RENDER_H_
    #define RENDER_H_

    #include <SFML/Graphics.h>

typedef struct resolution_s {
    int width;
    int height;
    float zoom;
} resolution_t;

typedef struct camera_s {
    sfVector2i map_position;
    sfVector2f pos_in_tile;
    float zoom;
} camera_t;

typedef struct tile_object_s {
    int id;
    sfIntRect rect;
    sfVector2f origin;
} tile_object_t;

// render/camera.c
void set_camera_center(camera_t *camera, sfVector2f center);
void set_camera_size(camera_t *camera, sfVector2f size);
void set_camera(camera_t *camera, sfRenderWindow *window);

typedef struct render_window_s {
    sfRenderWindow *window;
} render_window_t;

// render/render_window.c
int get_resolutions_count(void);
sfVideoMode get_sfvideo_mode(int index);

// render/render_window.c
void init_icon(render_window_t *window);

#endif /* !RENDER_H_ */
