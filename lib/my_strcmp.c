/*
** EPITECH PROJECT, 2025
** my_strcmp
** File description:
** Return 1 if s1 is greater than s2, 0 if they're equals or else -1
*/

#include "../include/my.h"
#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
    char *str1 = malloc(sizeof(char) * (my_strlen(s1) + 1));
    char *str2 = malloc(sizeof(char) * (my_strlen(s2) + 1));
    int i = 0;
    int res = 0;

    my_strcpy(str1, s1);
    my_strlowcase(str1);
    my_strcpy(str2, s2);
    my_strlowcase(str2);
    while (str1[i] == str2[i] && str1[i] != 0 && str2[i] != 0){
        i++;
    }
    if (str1[i] > str2[i])
        res = 1;
    if (str1[i] < str2[i])
        res = -1;
    free(str1);
    free(str2);
    return res;
}
