/*
** EPITECH PROJECT, 2025
** my_strlowcase
** File description:
** replace all non-lowcase alpha by lowcases characters
*/
#include "../include/my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != 0; i++){
        if (str[i] <= 'Z' && str[i] >= 'A')
            str[i] = str[i] + 32;
    }
    return str;
}
