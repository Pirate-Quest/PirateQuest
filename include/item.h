/*
** EPITECH PROJECT, 2024
** Delivery
** File description:
** item
*/

#ifndef ITEM_H_
    #define ITEM_H_

    #include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>

typedef struct item_texture_s {
        sfTexture *texture;
        char *name;
} item_texture_t;

#endif /* !ITEM_H_ */
