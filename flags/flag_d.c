/*
** EPITECH PROJECT, 2025
** flag_d
** File description:
** Only list the folder
*/

#include "../include/my.h"

void flag_d(char *pathname, int *tab)
{
    if (tab[2] == 0){
        my_putstr(pathname);
        my_putchar('\n');
    } else
        flag_l(pathname, tab);
}
