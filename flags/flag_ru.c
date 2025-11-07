/*
** EPITECH PROJECT, 2025
** flag_ru
** File description:
** List recursively
*/

#include "../include/my.h"
#include <stdlib.h>

void flag_ru(char **list_files, char *pathname, int nb_files, int *tab)
{
    struct stat type;
    char *full_name;

    for (int i = 0; i < nb_files; i++){
        lstat(list_files[i], &type);
        if (tab[3] == 1 && S_ISDIR(type.st_mode)){
            full_name = fill_full_pathname(full_name, pathname, list_files[i]);
            my_putstr(full_name);
            my_putstr(":\n");
            free(full_name);
            display_ls(list_files[i], tab, &type);
        }
    }
}
