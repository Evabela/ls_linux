/*
** EPITECH PROJECT, 2025
** display_ls.c
** File description:
** Print lines (find and display files)
*/

#include "include/my.h"
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/sysmacros.h>

static int find_smallest(char **list, int nb_files)
{
    int smaller = 0;
    int comp = 0;

    for (int i = 0; i < nb_files; i++){
        comp = 0;
        while (list[smaller] == 0)
            smaller++;
        if (list[i] != 0 && list[smaller] != 0)
            comp = my_strcmp(list[i], list[smaller]);
        if (comp == -1)
            smaller = i;
    }
    return smaller;
}

char **sort_array(char **list_files_ns, int nb_files)
{
    char **sorted;
    int k = 0;

    sorted = malloc(sizeof(char *) * nb_files);
    for (int i = 0; i < nb_files; i++){
        k = find_smallest(list_files_ns, nb_files);
        if (list_files_ns[k] != 0){
            sorted[i] = malloc(sizeof(char) *
                (my_strlen(list_files_ns[k]) + 1));
            my_strcpy(sorted[i], list_files_ns[k]);
            list_files_ns[k] = 0;
        }
    }
    free(list_files_ns);
    return sorted;
}

int display_ls(char *pathname, int *tab, struct stat *s)
{
    if (S_ISDIR((*s).st_mode)){
        if (tab[1] == 1)
            flag_d(pathname, tab);
        if (tab[0] == 1 && tab[1] == 0)
            flag_a(pathname, tab);
        if (tab[1] + tab[0] == 0)
            normal_ls(pathname, tab);
    } else {
        if (tab[1] == 1)
            flag_d(pathname, tab);
        if (tab[0] == 1 && tab[1] == 0)
            flag_a(pathname, tab);
        if (tab[2] == 1)
            flag_l(pathname, tab);
        if (tab[1] + tab[0] + tab[2] == 0){
            my_putstr(pathname);
            my_putchar('\n');
        }
    }
    return 0;
}
