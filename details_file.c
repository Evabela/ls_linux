/*
** EPITECH PROJECT, 2025
** details_file
** File description:
** Main functions for the programm
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/sysmacros.h>
#include "include/my.h"

char *dis_name(char *path_name)
{
    int count = 0;
    int i = 0;

    while (path_name[count] != 0){
        if (path_name[count] == '/')
            i = count + 1;
        count++;
    }
    return &path_name[i];
}

char find_type(struct stat *s)
{
    if (S_ISREG((*s).st_mode))
        return 'f';
    if (S_ISDIR((*s).st_mode))
        return 'd';
    if (S_ISCHR((*s).st_mode))
        return 'c';
    if (S_ISBLK((*s).st_mode))
        return 'b';
    if (S_ISFIFO((*s).st_mode))
        return 'p';
    if (S_ISLNK((*s).st_mode))
        return 'l';
    if (S_ISSOCK((*s).st_mode))
        return 's';
    return '0';
}

int details_file(char **av)
{
    char *path_name = av[1];
    struct stat s;

    if (open(path_name, O_RDONLY) < 0){
        my_puterror("File not found\n");
        return 84;
    }
    lstat(path_name, &s);
    my_printf("Name: %s\n", dis_name(path_name));
    my_printf("Type: %c\n", find_type(&s));
    my_printf("Inode: %i\n", s.st_ino);
    my_printf("Hard link: %i\n", s.st_nlink);
    my_printf("Size: %u\n", s.st_size);
    my_printf("Allocated space: %u\n", s.st_blocks * 512);
    my_printf("Minor: %u\n", minor(s.st_dev));
    my_printf("Major: %u\n", major(s.st_dev));
    my_printf("UID: %i\n", s.st_uid);
    my_printf("GID: %i\n", s.st_gid);
    return 0;
}
