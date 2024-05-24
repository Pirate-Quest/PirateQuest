/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** path_finding.c
*/

#include "../../include/pirate_quest.h"

const sfVector2i directions[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

static int heuristic(sfVector2i a, sfVector2i b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

static node_t *create_node(sfVector2i pos, int g, int h, node_t *parent)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        return NULL;
    node->pos = pos;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

static void free_nodes(node_t *node)
{
    node_t *temp;

    while (node) {
        temp = node;
        node = node->parent;
        free(temp);
    }
}

static int is_valid_pos(sfVector2i pos, pirate_quest_t *game)
{
    if (pos.x < 0 || pos.x >= MAP_WIDTH || pos.y < 0 || pos.y >= MAP_HEIGHT)
        return 0;
    if (game->collision[pos.y][pos.x] != -1)
        return 0;
    return 1;
}

static int is_in_list(node_t **list, int list_size, sfVector2i pos)
{
    for (int i = 0; i < list_size; i++) {
        if (list[i] && list[i]->pos.x == pos.x && list[i]->pos.y == pos.y)
            return 1;
    }
    return 0;
}

static int get_current_index(node_t **list, int list_size)
{
    int lowest_f = INT_MAX;
    int current_index = -1;

    for (int i = 0; i < list_size; i++) {
        if (list[i]->f < lowest_f) {
            lowest_f = list[i]->f;
            current_index = i;
        }
    }
    return current_index;
}

node_t *create_and_add_neighbor(create_add_neighbor_builder_t *builder)
{
    node_t *neighbor = create_node(builder->neighbor_pos, builder->tentative_g,
        heuristic(builder->neighbor_pos, builder->end), builder->current);

    if (!neighbor) {
        free_nodes(builder->current);
        return NULL;
    }
    if (!builder->in_open) {
        builder->open_list[(*builder->open_size)] = neighbor;
        (*builder->open_size)++;
    }
    return neighbor;
}

void process_neighbors(process_neighbors_builder_t *builder,
    pirate_quest_t *game)
{
    sfVector2i n_pos;
    int tentative_g;
    int in_open;

    for (int i = 0; i < 4; i++) {
        n_pos = (sfVector2i) {builder->current->pos.x + directions[i].x,
            builder->current->pos.y + directions[i].y};
        if (!is_valid_pos(n_pos, game)
            || is_in_list(builder->closed_list, builder->closed_size, n_pos))
            continue;
        tentative_g = builder->current->g + 1;
        in_open = is_in_list(builder->open_list, *builder->open_size, n_pos);
        if ((!in_open || tentative_g < builder->current->g)
            && (!create_and_add_neighbor(&(create_add_neighbor_builder_t) {
            builder->current, n_pos, tentative_g, builder->end,
            builder->open_list, builder->open_size, in_open})))
            return;
    }
}

sfVector2i *build_path(node_t *current)
{
    int path_length = 0;
    sfVector2i *path = NULL;

    for (node_t *node = current; node; node = node->parent)
        path_length++;
    path = malloc(sizeof(sfVector2i) * path_length);
    if (!path) {
        free_nodes(current);
        return NULL;
    }
    for (int i = path_length - 1; i >= 0; i--) {
        path[i] = current->pos;
        current = current->parent;
    }
    free_nodes(current);
    return path;
}

sfVector2i *find_path(pirate_quest_t *g, sfVector2i start, sfVector2i end)
{
    node_t *open_list[MAP_HEIGHT * MAP_WIDTH] = {NULL};
    path_finding_builder_t builder = {0, 0, 0, NULL, {NULL}};

    open_list[builder.s] = create_node(start, 0, heuristic(start, end), NULL);
    builder.s++;
    if (!open_list[0])
        return NULL;
    while (builder.s > 0) {
        builder.current_index = get_current_index(open_list, builder.s);
        builder.current = open_list[builder.current_index];
        builder.s--;
        open_list[builder.current_index] = open_list[builder.s];
        builder.cl[builder.closed_size] = builder.current;
        builder.closed_size++;
        if (builder.current->pos.x == end.x && builder.current->pos.y == end.y)
            return build_path(builder.current);
        process_neighbors(&(process_neighbors_builder_t) {builder.current,
            open_list, &builder.s, builder.cl, builder.closed_size, end}, g);
    }
    return NULL;
}
