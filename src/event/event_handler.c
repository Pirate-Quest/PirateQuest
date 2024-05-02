/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** event_handler.c
*/

#include "../../include/pirate_quest.h"
#include "../../include/event.h"

event_listener_t event_listener[] = {
    {sfEvtClosed, &close_event},
    {sfEvtKeyPressed, &key_pressed_event},
    {sfEvtKeyReleased, &key_released_event}
};
int events_size = {sizeof(event_listener) / sizeof(event_listener_t)};

void fire_event(pirate_quest_t *game,
    sfEvent *event, event_listener_t *listener)
{
    if (listener->type == event->type) {
        listener->function(*event, game);
    }
}

void update_listeners(pirate_quest_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window->window, &event)) {
        for (int i = 0; i < events_size; i++) {
            fire_event(game, &event, &event_listener[i]);
        }
    }
}
