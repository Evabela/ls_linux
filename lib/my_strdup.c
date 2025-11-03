/*
** EPITECH PROJECT, 2025
** my_strdup.c
** File description:
** Function to duplicate another
*/

#include "../include/my.h"
#include <stdlib.h>

char *my_strdup(char *str)
{
    char *strd;
    int len_str = my_strlen(str);

    strd = malloc(sizeof(char) * len_str + 1);
    for (int i = 0; i < len_str; i++){
        strd[i] = str[i];
    }
    strd[len_str] = 0;
    return strd;
}
