/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** event.h
*/

#ifndef EVENT_H
    #define EVENT_H

    #include <SFML/Graphics.h>
    #include "pirate_quest.h"

/**
 * @brief The event listener struct
 *
 * @param type The type of the event
 * @param function The function to call when the event is fired
 */
typedef struct event_listener_s {
    const sfEventType type;
    void (*function)(sfEvent event, pirate_quest_t *game);
} event_listener_t;

/**
 * @brief Fire all registered listeners
 *
 * @param game game infos
 * @return void
 */
void update_listeners(pirate_quest_t *game);

/**
 * @brief Implemented default event on close
 *
 * @param event event info
 * @param game game infos
 * @return void
 */
void close_event(sfEvent event, pirate_quest_t *game);

void key_pressed_event(sfEvent event, pirate_quest_t *game);
void key_released_event(sfEvent event, pirate_quest_t *game);

void update_key_pressed(pirate_quest_t *game);

#endif /* !EVENT_H */
