/*
** EPITECH PROJECT, 2025
** count_flags
** File description:
** Search and repertory flags, if error, return 84
*/
#include "include/my.h"

static int verif_flag(char letter, int *tab)
{
    if (letter == 'a'){
        tab[0] = 1;
        return 0;
    }
    if (letter == 'd'){
        tab[1] = 1;
        return 0;
    }
    if (letter == 'l'){
        tab[2] = 1;
        return 0;
    }
    if (letter == 'R'){
        tab[3] = 1;
        return 0;
    }
    if (letter == 't'){
        tab[4] = 1;
        return 0;
    }
    return -1;
}

int count_flags(char **av)
{
    int i = 1;
    int j = 0;
    int tab[5] = {0};

    while (av[i][0] == '-'){
        j++;
        if (av[i][j] == 0 && av[i][j - 1] != '-')
            i++;
        if (verif_flag(av[i][j], tab) == -1){
            return 84;
        }
    }
    return 0;
}
