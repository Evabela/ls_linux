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
#include <stdlib.h>

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

int redirect_of_flags(int ac, int i, char **av, int *tab)
{
    int a = 0;
    struct stat s;

    if (ac - i <= 0){
        if (lstat(".", &s) != 0)
            exit(84);
        return display_ls(".", tab, &s);
    }
    for (int k = i; k < ac; k++){
        if (lstat(av[k], &s) != 0)
            exit(84);
        if (ac - i > 1 && S_ISDIR(s.st_mode)){
            my_putstr(av[k]);
            my_putstr(":\n");
        }
        a = display_ls(av[k], tab, &s);
        if (a == 84)
            exit(84);
    }
    return 0;
}

int count_flags(int ac, char **av)
{
    int i = 1;
    int j = 0;
    int tab[5] = {0};

    while (i < ac && av[i][0] == '-'){
        j++;
        if (verif_flag(av[i][j], tab) == -1){
            return 84;
        }
        if (av[i][j + 1] == 0){
            i++;
            j = 0;
        }
    }
    return redirect_of_flags(ac, i, av, tab);
}
