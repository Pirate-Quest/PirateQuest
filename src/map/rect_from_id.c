/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** rect_from_id.c
*/

#include "../../include/map.h"
#include <SFML/Graphics.h>

/*
 * The texture IDs are defined in the following order:
 * - The lines go from 20 to 20 so the first line is from 0 to 19,
 *   the second from 20 to 39, etc.
 * - The element [0][0] is the ID 0, [0][1] is the ID 1, [0][2] is the ID 2, ..
 * - The element [1][0] is the ID 20, [1][1] is the ID 21, [1][2] is the ID 22
 * - The element [2][0] is the ID 40, [2][1] is the ID 41, [2][2] is the ID 42

 * So, as the tileset is 32x32, to get the position of the
 * rectangle in the tileset, you have to do:
 * x = id % 20 * 32
 * y = id / 20 * 32
 */

sfIntRect rect_from_id(int id, int offset)
{
    if (id == -1)
        return rect_from_id(DEFAULT_EMPTY_TILE_ID, offset);
    return (sfIntRect){(id % offset) * 32, (id / offset) * 32, 32, 32};
}
