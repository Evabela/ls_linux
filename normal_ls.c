/*
** EPITECH PROJECT, 2025
** normal_ls.c
** File description:
** Display the ls with no flag (except t or l)
*/

#include "include/my.h"
#include <dirent.h>
#include <stdlib.h>

char **get_files(char *pathname, int nb_files)
{
    DIR *list_files;
    struct dirent *read_file;
    char **list_files_ns = 0;
    int i = 0;

    list_files_ns = malloc(sizeof(char *) * nb_files);
    list_files = opendir(pathname);
    read_file = readdir(list_files);
    while (read_file != 0){
        if (read_file->d_name[0] != '.'){
            list_files_ns[i] = malloc(sizeof(char) *
                my_strlen(read_file->d_name) + 1);
            my_strcpy(list_files_ns[i], read_file->d_name);
            i++;
        }
        read_file = readdir(list_files);
    }
    closedir(list_files);
    return list_files_ns;
}

int count_files(char *pathname)
{
    DIR *list_files;
    struct dirent *read_file;
    int nb_files = 0;

    list_files = opendir(pathname);
    read_file = readdir(list_files);
    while (read_file != 0){
        if (read_file->d_name[0] != '.')
            nb_files++;
        read_file = readdir(list_files);
    }
    closedir(list_files);
    return nb_files;
}

char *fill_full_pathname(char *pathname, char *file)
{
    char *full_pathname;

    full_pathname = malloc(sizeof(char) *
        (my_strlen(pathname) + my_strlen(file) + 2));
    full_pathname[0] = 0;
    my_strcat(full_pathname, pathname);
    my_strcat(full_pathname, "/");
    my_strcat(full_pathname, file);
    return full_pathname;
}

void normal_ls(char *pathname, int *tab)
{
    int nb_files = count_files(pathname);
    char **list_files = flag_t(sort_array(
            get_files(pathname, nb_files), nb_files), pathname, nb_files, tab);
    char *full_name;

    if (tab[2] == 1)
        my_put_total(list_files, pathname, nb_files);
    for (int i = 0; i < nb_files; i++){
        full_name = fill_full_pathname(pathname, list_files[i]);
        if (tab[2] == 0){
            my_putstr(list_files[i]);
            my_putchar('\n');
        }
        if (tab[2] == 1)
            flag_l(full_name, tab);
        free(full_name);
    }
    flag_ru(list_files, pathname, nb_files, tab);
    free(list_files);
}
