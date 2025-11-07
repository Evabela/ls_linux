/*
** EPITECH PROJECT, 2025
** errors.c
** File description:
** Handle all errors and return 84 if one, else 0
*/

#include "include/my.h"
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void errors_in_folder(char *pathname)
{
    DIR *file;
    struct dirent *read_file;
    struct stat s;

    errno = 0;
    file = opendir(pathname);
    if (errno != 0){
        perror(pathname);
        exit(84);
    }
    read_file = readdir(file);
    if (read_file == 0 && errno != 0){
        perror(pathname);
        exit(84);
    }
    while (read_file != 0 && errno == 0){
        read_file = readdir(file);
        if (read_file == 0 && errno != 0){
            perror(pathname);
            exit(84);
        }
    }
}

static int error_not_exist(char *pathname, struct stat *s)
{
    struct stat t;

    if (pathname[0] == '-')
        return 0;
    if (S_ISDIR((*s).st_mode)){
        if (opendir(pathname) == 0)
            exit(84);
    }
    if (lstat(pathname, &t) == 0){
        return 0;
    }
    perror(pathname);
    exit(84);
}

int read_for_errors(int ac, char **av)
{
    struct stat s;

    for (int i = 1; i < ac; i++){
        lstat(av[i], &s);
        if (error_not_exist(av[i], &s) != 0){
            return 84;
        }
    }
    return 0;
}
