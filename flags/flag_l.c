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

static void perm_oth(struct stat *s)
{
    if ((*s).st_mode && S_IROTH)
        my_putchar('r');
    else
        my_putchar('-');
    if ((*s).st_mode && S_IWOTH)
        my_putchar('w');
    else
        my_putchar('-');
    if ((*s).st_mode && S_IXOTH)
        my_putchar('x');
    else
        my_putchar('-');
}

static void perm_grp(struct stat *s)
{
    if ((*s).st_mode && S_IRGRP)
        my_putchar('r');
    else
        my_putchar('-');
    if ((*s).st_mode && S_IWGRP)
        my_putchar('w');
    else
        my_putchar('-');
    if ((*s).st_mode && S_IXGRP)
        my_putchar('x');
    else
        my_putchar('-');
}

static void perm_usr(struct stat *s)
{
    if ((*s).st_mode && S_IRUSR)
        my_putchar('r');
    else
        my_putchar('-');
    if ((*s).st_mode && S_IWUSR)
        my_putchar('w');
    else
        my_putchar('-');
    if ((*s).st_mode && S_IXUSR)
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

static print_user_and_group(struct stat *s)
{
    struct passwd *usr = getpwuid((*s).st_uid);
    struct group *grp = getgrgid((*s).st_gid);

    my_putchar(' ');
    my_putstr(usr->pw_name);
    my_putchar(' ');
    my_putstr(grp->gr_name);
    my_putchar(' ');
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
}
