/*
** EPITECH PROJECT, 2025
** my_putchar
** File description:
** Put characters and errors
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_puterror(char *str)
{
    int i = 0;

    while (str[i] != 0){
        write(2, &str[i], 1);
        i++;
    }
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != 0){
        my_putchar(str[i]);
        i++;
    }
}
