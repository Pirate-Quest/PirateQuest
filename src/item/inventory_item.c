/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** inventory_item.c
*/

#include "../../include/pirate_quest.h"
#include <SFML/Config.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Types.h>
#include <stdlib.h>

const inventory_item_registry_t inventory_item_registry[] = {
    {NONE_ITEM, "None", "assets/item/empty.png"},
    {SWORD_ITEM, "Sword", "assets/item/sword.png"},
    {KEY_ITEM, "Key", "assets/item/key.png"},
    {LETTER_ITEM, "Letter", "assets/item/letter.png"},
    {PLANK_ITEM, "Plank", "assets/item/plank.png"},
    {TUTO_SWORD_ITEM, "Tuto_sword", "assets/item/tuto_sword.png"},
};

static void set_texture(pirate_quest_t *game)
{
    for (int i = 0; i < TOTAL_ITEM; i++){
        game->item_texture[i]->name = inventory_item_registry[i].name;
        game->item_texture[i]->texture =
            sfTexture_createFromFile(inventory_item_registry[i].path, NULL);
    }
}

int remove_item(pirate_quest_t *game, int item)
{
    for (int i = 0; i < SLOT_COUNT; i++) {
        if (game->inv_bar->slots_id[i] == item){
            game->inv_bar->slots_id[i] = NONE_ITEM;
            sfSprite_setTexture(game->inv_bar->slots[i],
                game->item_texture[0]->texture, sfFalse);
            return 1;
        }
    }
    return 0;
}

int is_item(pirate_quest_t *game, int item)
{
    for (int i = 0; i < SLOT_COUNT; i++){
        if (game->inv_bar->slots_id[i] == item)
            return 1;
    }
    return 0;
}

int add_item(pirate_quest_t *game, int item)
{
    for (int i = 0; i < SLOT_COUNT; i++){
        if (game->inv_bar->slots_id[i] == NONE_ITEM){
            game->inv_bar->slots_id[i] = item;
            sfSprite_setTexture(game->inv_bar->slots[i],
                game->item_texture[i]->texture, sfFalse);
            return 1;
        }
    }
    return 0;
}

void init_inv(pirate_quest_t *game)
{
    set_texture(game);
    game->inv_bar->texture_bar =
        sfTexture_createFromFile("assets/item/bar.png", NULL);
    game->inv_bar->sprite_bar = sfSprite_create();
    sfSprite_setTexture(game->inv_bar->sprite_bar,
        game->inv_bar->texture_bar, sfFalse);
    for (int i = 0; i < SLOT_COUNT; i++){
        game->inv_bar->slots[i] = sfSprite_create();
        sfSprite_setTexture(game->inv_bar->slots[i],
            game->item_texture[0]->texture, sfFalse);
        game->inv_bar->slots_id[i] = NONE_ITEM;
    }
}
