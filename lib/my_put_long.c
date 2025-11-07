/*
** EPITECH PROJECT, 2025
** my_put_long.c
** File description:
** Like, my_put_nbr, but for long int and long long
*/

#include "../include/my.h"

static int my_dislong(long nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = - nb;
    }
    if (nb / 10 == 0){
        my_putchar('0' + nb % 10);
        return 0;
    } else {
        my_dislong(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    return 0;
}

int my_put_long(long nb)
{
    if (nb == -2147483648){
        my_dislong(nb / 10);
        my_putchar('8');
    } else
        my_dislong(nb);
    return 0;
}

static int my_dislonglong(long long nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = - nb;
    }
    if (nb / 10 == 0){
        my_putchar('0' + nb % 10);
        return 0;
    } else {
        my_dislonglong(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    return 0;
}

int my_put_long_long(long long nb)
{
    if (nb == -2147483648){
        my_dislonglong(nb / 10);
        my_putchar('8');
    } else
        my_dislonglong(nb);
    return 0;
}
