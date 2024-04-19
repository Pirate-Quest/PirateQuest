/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** gamerules.h
*/

#ifndef MY_RPG_GAMERULES_H
    #define MY_RPG_GAMERULES_H
    #define XP_GAP 100

typedef struct player_xp_s {
    unsigned int current_lvl;
    unsigned int current_xp;
} player_xp_t;

player_xp_t *init_player_xp(void);
player_xp_t *add_xp(player_xp_t *playerXp, unsigned int amount);

#endif //MY_RPG_GAMERULES_H
