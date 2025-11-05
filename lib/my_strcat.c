/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** Concatenates two strings
*/

char *my_strcat(char *dest, char const *src)
{
    char *start = dest;

    while (*dest != '\0'){
        dest++;
    }
    while (*src != '\0'){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = 0;
    return start;
}
