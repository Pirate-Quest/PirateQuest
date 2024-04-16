/*
** EPITECH PROJECT, 2024
** commons
** File description:
** key_hash.c
*/

#include <stdlib.h>
#include "../../../../include/commons.h"

void process_char(unsigned char c, unsigned long x[], unsigned long *h, int *i)
{
    for (int shift = 0; shift < 8; shift++) {
        if (c & 0x1) {
            *h ^= x[*i] * (*i + 1);
        }
        c >>= 1;
        (*i)++;
    }
}

int hash(char *key, int len)
{
    unsigned long result = 0;
    unsigned long x[1024];
    unsigned const char *us = (unsigned const char *)key;
    unsigned char current;
    int key_len = my_strlen(key);

    if (key == NULL || my_strlen(key) == 0 && len == 0)
        return 0;
    for (int i = 0; i < 1024; i++)
        x[i] = i + 1;
    for (int i = 0; *us != 0 && i < 1024 && i < key_len * 8; us++) {
        current = *us;
        process_char(current, x, &result, &i);
    }
    return result != 0 ? result : 1;
}
