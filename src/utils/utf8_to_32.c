/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** utf8_to_32.c
*/

#include <SFML/Graphics.h>

static sfUint32 convert_utf8_1_byte(const char **begin)
{
    sfUint32 output = **begin;

    (*begin)++;
    return output;
}

static sfUint32 convert_utf8_2_bytes(const char **begin)
{
    sfUint32 output = ((**begin & 0x1F) << 6) | (*(*begin + 1) & 0x3F);

    (*begin) += 2;
    return output;
}

static sfUint32 convert_utf8_3_bytes(const char **begin)
{
    sfUint32 output = ((**begin & 0x0F) << 12) | ((*(*begin + 1) & 0x3F) << 6)
        | (*(*begin + 2) & 0x3F);

    (*begin) += 3;
    return output;
}

static sfUint32 convert_utf8_4_bytes(const char **begin)
{
    sfUint32 output = ((**begin & 0x07) << 18) | ((*(*begin + 1) & 0x3F) << 12)
        | ((*(*begin + 2) & 0x3F) << 6) | (*(*begin + 3) & 0x3F);

    (*begin) += 4;
    return output;
}

sfUint32 convert_char_utf8_to_32(const char **begin)
{
    if ((**begin & 0x80) == 0)
        return convert_utf8_1_byte(begin);
    if ((**begin & 0xE0) == 0xC0)
        return convert_utf8_2_bytes(begin);
    if ((**begin & 0xF0) == 0xE0)
        return convert_utf8_3_bytes(begin);
    if ((**begin & 0xF8) == 0xF0)
        return convert_utf8_4_bytes(begin);
    return 0;
}

void utf8_to_32(const char *begin, const char *end, sfUint32 *output)
{
    while (begin < end) {
        *output = convert_char_utf8_to_32(&begin);
        output++;
    }
}
