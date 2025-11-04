/*
** EPITECH PROJECT, 2025
** display_ls.c
** File description:
** Print lines (find and display files)
*/

#include "include/my.h"
#include <dirent.h>
#include <stdlib.h>

static void print_2d_arr(char **str, int size)
{
    for (int i = 0; i < size; i++){
        if (str[i] == 0){
            my_put_nbr(0);
            my_putstr(" / ");
        } else {
            my_putstr(str[i]);
            my_putstr(" / ");
        }
    }
    my_putchar('\n');
}

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
    return sorted;
}

char **get_files(char *pathname, int nb_files)
{
    DIR *list_files;
    struct dirent *read_file;
    char **list_files_ns = {0};
    int i = 0;

    list_files_ns = malloc(sizeof(char *) * nb_files);
    list_files = opendir(pathname);
    read_file = readdir(list_files);
    while (read_file != 0){
        list_files_ns[i] = malloc(sizeof(char) * my_strlen(read_file->d_name));
        list_files_ns[i] = read_file->d_name;
        i++;
        read_file = readdir(list_files);
    }
    closedir(list_files);
    return list_files_ns;
}

int count_files(char *pathname)
{
    DIR *list_files;
    struct dirent *read_file;
    int nb_files;

    list_files = opendir(pathname);
    read_file = readdir(list_files);
    while (read_file != 0){
        nb_files++;
        read_file = readdir(list_files);
    }
    closedir(list_files);
    return nb_files;
}
