/*
** EPITECH PROJECT, 2025
** my_len
** File description:
** All functions to have the len of something (int, long or str if one is necessary)
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;
    int count;

    while (str[i] != 0){
        i++;
        count++;
    }
    return count;
}
