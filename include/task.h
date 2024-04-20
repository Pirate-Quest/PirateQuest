/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** task.h
*/

#ifndef TASK_H_
    #define TASK_H_

    #include "pirate_quest.h"

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

/**
 * @brief Register a task
 *
 * @param list
 * @param builder
 * @param data
 *
 * @return the created task @task_t
 *
 * @example
 * task_builder_t builder = {\n
 *    .on_tick = void_function,\n
 *    .on_end = fire,\n
 *    .second_interval = 1,\n
 *    .execution_count = 1\n
 * };\n
 * register_task(list, &builder, data);
 */
task_t *register_task(pirate_quest_t *game, task_builder_t *builder,
    hashtable_t *data);

/**
 * @brief Unregister a task
 *
 * @param list
 * @param task
 *
 * @return void
 */
void unregister_task(pirate_quest_t *game, task_t *task);

void free_task(void *data);

#endif /* !TASK_H_ */
