/*
** EPITECH PROJECT, 2025
** count_flags
** File description:
** Search and repertory flags, if error, return 84
*/
#include "include/my.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sysmacros.h>

static int verif_flag(char letter, int *tab)
{
    if (letter == 'a'){
        tab[0] = 1;
        return 0;
    }
    if (letter == 'd'){
        tab[1] = 1;
        return 0;
    } else if (letter == 'l'){
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
    } else
        return -1;
}

int redirect_of_flags(int nb_ac, char **av, int *tab)
{
    int a = 0;
    struct stat s;

    if (nb_ac <= 0){
        lstat(".", &s);
        a = display_ls(".", tab, &s);
        return a;
    }
    for (int k = 1; k <= nb_ac; k++){
        lstat(av[k], &s);
        if (nb_ac > 1 && S_ISDIR(s.st_mode)){
            my_putstr(av[k]);
            my_putstr(":\n");
        }
        a = display_ls(av[k], tab, &s);
        if (a == 84)
            return 84;
    }
    return 0;
}

int count_flags(int ac, char **av)
{
    int i = 1;
    int j = 1;
    int tab[5] = {0};
    int a = 0;

    if (ac == 1)
        i = 0;
    while (i < ac && i != 0 && av[i][0] == '-'){
        if (verif_flag(av[i][j], tab) == -1){
            return 84;
        }
        j++;
        if (av[i][j] == 0){
            i++;
            j = 0;
        }
    }
    if (i == 0)
        a = redirect_of_flags(i, av, tab);
    else
        a = redirect_of_flags(ac - i, av, tab);
    return a;
}
