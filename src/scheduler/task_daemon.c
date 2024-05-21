/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** task_daemon.c
*/

#include <stdlib.h>
#include "../../include/pirate_quest.h"

int is_valid_interval(double seconds, double interval)
{
    if (interval == 0 || interval == -1)
        return 1;
    return (int) (seconds * 100) % (int) (interval * 100) == 0;
}

void apply_count(pirate_quest_t *game, task_t *task)
{
    if (task->execution_count == -1)
        return;
    task->execution_count--;
    if (task->execution_count == 0) {
        if (task->on_end != NULL)
            task->on_end(game, task->data);
    }
}

void execute_all_tasks(pirate_quest_t *game, double seconds)
{
    my_list_node_t *current = game->tasks->head;
    int status = -1;
    task_t *task;

    while (current != NULL) {
        task = current->data;
        if (task->execution_count == 0) {
            current = current->next;
            unregister_task(game, task);
            continue;
        }
        if (is_valid_interval(seconds, task->second_interval)) {
            status = task->on_tick(game, task->data, task->execution_count);
            apply_count(game, task);
        }
        if (status == 1)
            task->execution_count = 0;
        current = current->next;
    }
}

void update_tasks(pirate_quest_t *game)
{
    task_daemon_t *daemon = game->task_daemon;

    daemon->seconds = sfClock_getElapsedTime(daemon->clock)
        .microseconds / 1000000.0;
    if (daemon->last_update != (int) (daemon->seconds * 100))
        execute_all_tasks(game, daemon->seconds);
    daemon->last_update = (int) (daemon->seconds * 100);
}
