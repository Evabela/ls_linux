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
