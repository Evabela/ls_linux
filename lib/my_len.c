/*
** EPITECH PROJECT, 2025
** my_len
** File description:
** All functions to have the len of something
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != 0){
        i++;
    }
    return i;
}

int my_intlen(int nb)
{
    int res = 0;

    if (nb == 0)
        return 1;
    if (nb < 0)
        res++;
    while (nb != 0){
        res++;
        nb = nb / 10;
    }
    return res;
}
