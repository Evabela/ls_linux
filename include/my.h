/*
** EPITECH PROJECT, 2025
** my
** File description:
** Header file
*/

#ifndef MY_
    #define MY_

void my_putchar(char c);
void my_puterror(char *str);
void my_putstr(char *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char *strd, char *str);

int count_flags(char **av);
int count_files(char *pathname);
void **sort_array(char **list_files_ns, int nb_files);

void flag_a(int *tab);
void flag_d(int *tab);
void flag_l(int *tab);
void flag_ru(int *tab);
void flag_t(int *tab);

#endif /* MY_ */
