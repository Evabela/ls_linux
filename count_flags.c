/*
** EPITECH PROJECT, 2025
** count_flags
** File description:
** Search and repertory flags, if error, return 84
*/
#include "include/my.h"

void initialize(letter_t **flags)
{
    char flags_letters[5] = {'a', 'd', 'l', 'R', 't'};
    void (*flags_functions[5])(int *) = {&flag_a, &flag_d, &flag_l, &flag_ru, &flag_t};
    letter_t *list;

    for (int i = 0; i < my_strlen(flags_letters); i++){
        list->letter = flags_letters[i];
        list->ptr = flags_functions[i];
        list-> next = *flags;
        *flags = list;
    }
}

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
    letter_t *list;
    int i = 1;
    int j = 0;
    int tab[5] = {0};

    initialize(list);
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
