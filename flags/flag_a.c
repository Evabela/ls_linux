/*
** EPITECH PROJECT, 2025
** flag_a
** File description:
** List all files
*/

#include "../include/my.h"
#include <dirent.h>
#include <stdlib.h>

static char **get_files_a(char *pathname, int nb_files)
{
    DIR *list_files;
    struct dirent *read_file;
    char **list_files_ns = 0;
    int i = 0;

    list_files_ns = malloc(sizeof(char *) * nb_files);
    list_files = opendir(pathname);
    read_file = readdir(list_files);
    while (read_file != 0){
        list_files_ns[i] = malloc(sizeof(char) *
            my_strlen(read_file->d_name));
        my_strcpy(list_files_ns[i], read_file->d_name);
        i++;
        read_file = readdir(list_files);
    }
    closedir(list_files);
    return list_files_ns;
}

static int count_files_a(char *pathname)
{
    DIR *list_files;
    struct dirent *read_file;
    int nb_files = 0;

    list_files = opendir(pathname);
    read_file = readdir(list_files);
    while (read_file != 0){
        nb_files++;
        read_file = readdir(list_files);
    }
    closedir(list_files);
    return nb_files;
}

void flag_a(char *pathname, int *tab)
{
    int nb_files = 0;
    char **list_files;

    nb_files = count_files_a(pathname);
    list_files = sort_array(get_files_a(pathname, nb_files), nb_files);
    for (int i = 0; i < nb_files; i++){
        if (tab[2] == 0){
            my_putstr(list_files[i]);
            my_putchar('\n');
        }
        if (tab[2] == 1){
            flag_l(list_files[i], tab);
        }
    }
    free(list_files);
}
