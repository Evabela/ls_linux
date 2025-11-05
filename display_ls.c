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
                my_strlen(read_file->d_name));
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

void normal_ls(char *pathname, int *tab)
{
    int nb_files = 0;
    char **list_files;

    nb_files = count_files(pathname);
    list_files = sort_array(get_files(pathname, nb_files), nb_files);
    for (int i = 0; i < nb_files; i++){
        my_putstr(list_files[i]);
        my_putchar('\n');
    }
    free(list_files);
}

int display_ls(char *pathname, int *tab, struct stat *s)
{
    if (S_ISDIR((*s).st_mode)){
        if(tab[1] == 1){
            flag_d(pathname, tab);
            return 0;
        }
        if (tab[0] == 1){
            flag_a(pathname, tab);
            return 0;
        }
        normal_ls(pathname, tab);
    } else {
        my_putstr(pathname);
        my_putchar('\n');
    }
    return 0;
}
