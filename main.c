/*
** EPITECH PROJECT, 2025
** main
** File description:
** Programm
*/

#include "include/my.h"

int main(int argc, char **argv)
{
    int a = 0;

    if (argc > 1)
        if (read_for_errors(argc, argv) == 84)
            return 84;
    a = count_flags(argc, argv);
    return a;
}
