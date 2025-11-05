/*
** EPITECH PROJECT, 2025
** errors.c
** File description:
** Handle all errors and return 84 if one, else 0
*/

#include "include/my.h"
#include <fcntl.h>
#include <dirent.h>

static int error_not_exist(char *pathname, struct stat *s)
{
    if (pathname[0] == '-')
        return 0;
    if (S_ISDIR((*s).st_mode)){
        if (opendir(pathname) != 0)
            return 0;
    }
    if (open(pathname, O_RDONLY) >= 0){
        return 0;
    }
    return 84;
}

int read_for_errors(int ac, char **av)
{
    struct stat s;

    for (int i = 1; i < ac; i++){
        lstat(av[i], &s);
        if (error_not_exist(av[i], &s)){
            my_puterror("my_ls: cannot access '");
            my_putstr(av[i]);
            my_putstr("' : No such file or directory\n");
            return 84;
        }
    }
    return 0;
}
