/*
** EPITECH PROJECT, 2024
** commons
** File description:
** my_put_int.c
*/

#include "../../include/commons.h"

static void print_positive(int nb)
{
    if (nb >= 10) {
        print_positive(nb / 10);
    }
    my_putchar('0' + (nb % 10));
}

void my_put_nbr(int nb)
{
    if (nb <= -2147483648) {
        my_putstr("-2147483648");
        return;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb == 0) {
        my_putchar('0');
    } else {
        print_positive(nb);
    }
}
