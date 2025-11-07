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

static int my_disint(int nb)
{
    if (nb < 0){
        my_putchar('-');
        nb = - nb;
    }
    if (nb / 10 == 0){
        my_putchar('0' + nb % 10);
        return 0;
    } else {
        my_disint(nb / 10);
        my_putchar(nb % 10 + '0');
    }
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648){
        my_disint(nb / 10);
        my_putchar('8');
    } else
        my_disint(nb);
    return 0;
}
