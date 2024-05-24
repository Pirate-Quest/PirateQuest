/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** task_provider.c
*/

#include <stdlib.h>
#include "../../include/pirate_quest.h"

task_t *register_task(pirate_quest_t *game, const task_builder_t *builder,
    void *data)
{
    task_t *new_task = malloc(sizeof(task_t));

    new_task->on_tick = builder->on_tick;
    new_task->on_end = builder->on_end;
    new_task->second_interval = builder->second_interval;
    new_task->execution_count = builder->execution_count;
    new_task->data = data;
    my_list_add(game->tasks, new_task);
    return new_task;
}

void unregister_task(pirate_quest_t *game, task_t *task)
{
    my_list_remove(game->tasks, task);
}

void free_task(void *data)
{
    task_t *task = data;

    free(task);
}
