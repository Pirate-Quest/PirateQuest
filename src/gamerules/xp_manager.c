/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** xp_manager.c
*/

#include "../../include/gamerules.h"
#include "../../include/pirate_quest.h"
#include <stdio.h>

static int get_max_xp_from_lvl(int lvl)
{
    if (lvl < 1)
        return 0;
    return (XP_GAP * lvl);
}

player_xp_t *init_player_xp(void)
{
    player_xp_t *playerXp = malloc(sizeof(player_xp_t));

    playerXp->current_lvl = 1;
    playerXp->current_xp = 0;
    return (playerXp);
}

player_xp_t *add_xp(player_xp_t *playerXp, unsigned int amount)
{
    int max_xp;

    if (playerXp == NULL)
        playerXp = init_player_xp();
    if (amount > INT_MAX)
        exit(84);
    playerXp->current_xp += amount;
    max_xp = get_max_xp_from_lvl(playerXp->current_lvl);
    if (playerXp->current_xp > max_xp) {
        playerXp->current_lvl++;
        playerXp->current_xp -= max_xp;
    }
    return (playerXp);
}

void printcon(player_xp_t *playerXp)
{
    printf("LVL: %d\n", playerXp->current_lvl);
    printf("XP: %d\n", playerXp->current_xp);
}
