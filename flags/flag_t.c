/*
** EPITECH PROJECT, 2025
** flag_t
** File description:
** Sort by time
*/

#include "../include/my.h"
#include <stdlib.h>
#include <time.h>

int return_smallest(char **list, int nb_files, char *path)
{
    int smallest = 0;
    time_t small_time;
    struct stat my_time;
    char *full_path;

    while (list[smallest] == 0)
        smallest++;
    full_path = fill_full_pathname(full_path, path, list[smallest]);
    lstat(full_path, &my_time);
    small_time = my_time.st_mtime;
    for (int i = 0; i < nb_files; i++){
        if (list[i] != 0)
            lstat(fill_full_pathname(full_path, path, list[i]), &my_time);
        if (list[i] != 0 && my_time.st_mtime >= small_time){
            smallest = i;
            small_time = my_time.st_mtime;
        }
    }
    return smallest;
}

char **flag_t(char **list_files, char *pathname, int nb_file, int *tab)
{
    char **list_sort;
    int small = 0;

    if (tab[4] == 1){
        list_sort = malloc(sizeof(char *) * nb_file);
        for (int i = 0; i < nb_file; i++){
            small = return_smallest(list_files, nb_file, pathname);
            list_sort[i] = malloc(sizeof(char) *
                my_strlen(list_files[small]) + 1);
            my_strcpy(list_sort[i], list_files[small]);
            list_files[small] = 0;
        }
        free(list_files);
        return list_sort;
    }
    return list_files;
}
