/*
** EPITECH PROJECT, 2025
** flag_l
** File description:
** List a lot of informations about files
*/

#include "../include/my.h"
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

static void perm_oth(struct stat *s)
{
    if ((*s).st_mode & S_IROTH)
        my_putchar('r');
    else
        my_putchar('-');
    if ((*s).st_mode & S_IWOTH)
        my_putchar('w');
    else
        my_putchar('-');
    if ((*s).st_mode & S_IXOTH)
        my_putchar('x');
    else
        my_putchar('-');
}

static void perm_grp(struct stat *s)
{
    if ((*s).st_mode & S_IRGRP)
        my_putchar('r');
    else
        my_putchar('-');
    if ((*s).st_mode & S_IWGRP)
        my_putchar('w');
    else
        my_putchar('-');
    if ((*s).st_mode & S_IXGRP)
        my_putchar('x');
    else
        my_putchar('-');
}

static void perm_usr(struct stat *s)
{
    if ((*s).st_mode & S_IRUSR)
        my_putchar('r');
    else
        my_putchar('-');
    if ((*s).st_mode & S_IWUSR)
        my_putchar('w');
    else
        my_putchar('-');
    if ((*s).st_mode & S_IXUSR)
        my_putchar('x');
    else
        my_putchar('-');
}

static void print_type(struct stat *s)
{
    if (S_ISREG((*s).st_mode))
        my_putchar('-');
    if (S_ISDIR((*s).st_mode))
        my_putchar('d');
    if (S_ISCHR((*s).st_mode))
        my_putchar('c');
    if (S_ISBLK((*s).st_mode))
        my_putchar('b');
    if (S_ISFIFO((*s).st_mode))
        my_putchar('p');
    if (S_ISLNK((*s).st_mode))
        my_putchar('l');
    if (S_ISSOCK((*s).st_mode))
        my_putchar('s');
}

static void print_user_and_group(struct stat *s)
{
    struct passwd *usr = getpwuid((*s).st_uid);
    struct group *grp = getgrgid((*s).st_gid);

    my_putchar(' ');
    my_putstr(usr->pw_name);
    my_putchar(' ');
    my_putstr(grp->gr_name);
}

void print_date(struct stat *s)
{
    char *str = ctime(&(*s).st_mtime);

    my_putchar(' ');
    for (int i = 4; i < 16; i++){
        my_putchar(str[i]);
    }
}

void print_name(char *path_name)
{
    int count = 0;
    int i = 0;

    while (path_name[count] != 0){
        if (path_name[count] == '/')
            i = count + 1;
        count++;
    }
    my_putchar(' ');
    my_putstr(&path_name[i]);
}

void my_put_size(struct stat *s)
{
    int size = (*s).st_size;

    for (int i = 0; i < 4 - my_intlen(size); i++)
        my_putchar(' ');
    my_put_nbr(size);
}

void my_put_total(char **list_file, int nb_file)
{
    struct stat size;
    int blocks = 0;

    my_putstr("total ");
    for (int i = 0; i < nb_file; i++){
        lstat(list_file[i], &size);
        blocks += size.st_blocks;
    }
    my_put_nbr(blocks / 2);
    my_putchar('\n');
}

void flag_l(char *pathname, int *tab)
{
    struct stat s;

    lstat(pathname, &s);
    print_type(&s);
    perm_usr(&s);
    perm_grp(&s);
    perm_oth(&s);
    my_putchar(' ');
    my_put_long(s.st_nlink);
    print_user_and_group(&s);
    my_putchar(' ');
    my_put_size(&s);
    print_date(&s);
    print_name(pathname);
    my_putchar('\n');
}
