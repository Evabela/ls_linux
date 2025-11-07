/*
** EPITECH PROJECT, 2025
** my
** File description:
** Header file
*/

#include <sys/stat.h>

#ifndef MY_
    #define MY_

void my_putchar(char c);
void my_puterror(char *str);
void my_putstr(char *str);
int my_put_nbr(int nb);
int my_put_long(long nb);
int my_put_long_long(long long nb);
int my_strlen(char const *str);
int my_intlen(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_real_strcmp(char const *s1, char const *s2);
char *my_strdup(char *strd, char *str);
char *my_strlowcase(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);

int count_flags(int ac, char **av);
int count_files(char *pathname);
char **sort_array(char **list_files_ns, int nb_files);
int read_for_errors(int ac, char **av);
char *fill_full_pathname(char *full_pathname, char *pathname, char *file);
void my_put_total(char **list_file, char *pathname, int nb_file);
void errors_in_folder(char *pathname);

int display_ls(char *pathname, int *tab, struct stat *s);
void normal_ls(char *pathname, int *tab);
void flag_a(char *pathname, int *tab);
void flag_d(char *pathname, int *tab);
void flag_l(char *pathname, int *tab);
void flag_ru(char **list_files, char *pathname, int nb_files, int *tab);
char **flag_t(char **list_files, char *pathname, int nb_file, int *tab);

#endif /* MY_ */
