/*
** EPITECH PROJECT, 2025
** display_ls.c
** File description:
** Print lines (find and display files)
*/

#include "include/my.h"
#include <dirent.h>
#include <stdlib.h>

static void my_swap_str(char *str1, char *str2)
{
    char *temp;

    if (my_strcmp(str1, str2) == 1){
        temp = my_strdup(temp, str1);
        str1 = str2;
        str2 = temp;
    }
    free(temp);
}

void **sort_array(char **list_files_ns, int nb_files)
{
    for (int i = 0; i < nb_files - 1; i++){
        for (int j = 0; j < nb_files - 1; j++){
            my_swap_str(list_files_ns[i], list_files_ns[i + 1]);
        }
    }
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
    while(read_file != 0){
        nb_files++;
        read_file = readdir(list_files);
    }
    closedir(list_files);
    return nb_files;
}
