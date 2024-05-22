/*
** EPITECH PROJECT, 2024
** PirateQuest
** File description:
** utf8_to_32.c
*/

#include <SFML/Graphics.h>

/**
 * @brief Converts a single byte UTF-8 character to UTF-32.
 * @param begin Pointer to the pointer to the current
 * character in the UTF-8 string.
 * @return The UTF-32 representation of the character.
 */
static sfUint32 convert_utf8_1_byte(const char **begin)
{
    sfUint32 output = **begin;

    (*begin)++;
    return output;
}

/**
 * @brief Converts a two-byte UTF-8 character to UTF-32.
 * @param begin Pointer to the pointer to the current
 * character in the UTF-8 string.
 * @return The UTF-32 representation of the character.
 *
 * The two-byte UTF-8 character format is:
 * 110xxxxx 10xxxxxx
 *
 * Example: 11000010 10101100 (U+00AC)
 * Conversion:
 * ((11000010 & 0x1F) << 6) | (10101100 & 0x3F)
 * ((0000010) << 6) | (00101100)
 * (000001000000) | (00101100)
 * 00000100101100 -> U+00AC
 */
static sfUint32 convert_utf8_2_bytes(const char **begin)
{
    sfUint32 output = ((**begin & 0x1F) << 6) | (*(*begin + 1) & 0x3F);

    (*begin) += 2;
    return output;
}

/**
 * @brief Converts a three-byte UTF-8 character to UTF-32.
 * @param begin Pointer to the pointer to the current
 * character in the UTF-8 string.
 * @return The UTF-32 representation of the character.
 *
 * The three-byte UTF-8 character format is:
 * 1110xxxx 10xxxxxx 10xxxxxx
 *
 * Example: 11100010 10000010 10101100 (U+20AC)
 * Conversion:
 * ((11100010 & 0x0F) << 12) | ((10000010 & 0x3F) << 6) | (10101100 & 0x3F)
 * ((0000010) << 12) | ((0000010) << 6) | (00101100)
 * (0000010000000000) | (000010000000) | (00101100)
 * 000001000010101100 -> U+20AC
 */
static sfUint32 convert_utf8_3_bytes(const char **begin)
{
    sfUint32 output = ((**begin & 0x0F) << 12) | ((*(*begin + 1) & 0x3F) << 6)
        | (*(*begin + 2) & 0x3F);

    (*begin) += 3;
    return output;
}

/**
 * @brief Converts a four-byte UTF-8 character to UTF-32.
 * @param begin Pointer to the pointer to the current
 * character in the UTF-8 string.
 * @return The UTF-32 representation of the character.
 *
 * The four-byte UTF-8 character format is:
 * 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 *
 * Example: 11110000 10010000 10001100 10001101 (U+1034D)
 * Conversion:
 * ((11110000 & 0x07) << 18) | ((10010000 & 0x3F) << 12)
 *     | ((10001100 & 0x3F) << 6) | (10001101 & 0x3F)
 * ((0000000) << 18) | ((0010000) << 12) | ((001100) << 6) | (001101)
 * (000000000000000000) | (0001000000000000) | (000011000000) | (001101)
 * 00010000001100001101 -> U+1034D
 */
static sfUint32 convert_utf8_4_bytes(const char **begin)
{
    sfUint32 output = ((**begin & 0x07) << 18) | ((*(*begin + 1) & 0x3F) << 12)
        | ((*(*begin + 2) & 0x3F) << 6) | (*(*begin + 3) & 0x3F);

    (*begin) += 4;
    return output;
}

/**
 * @brief Converts a single UTF-8 character to UTF-32.
 * @param begin Pointer to the pointer to the current
 * character in the UTF-8 string.
 * @return The UTF-32 representation of the character.
 */
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

/**
 * @brief Converts a UTF-8 string to a UTF-32 string.
 * @param begin Pointer to the start of the UTF-8 string.
 * @param end Pointer to the end of the UTF-8 string.
 * @param output Pointer to the buffer where the UTF-32 string will be stored.
 *
 * This function iterates over the UTF-8 string, converting each character
 * to UTF-32 and storing it in the output buffer.
 */
void utf8_to_32(const char *begin, const char *end, sfUint32 *output)
{
    while (begin < end) {
        *output = convert_char_utf8_to_32(&begin);
        output++;
    }
}
