/*
** EPITECH PROJECT, 2025
** my_strcmp
** File description:
** Return 1 if s1 is greater than s2, 0 if they're equals or else -1
*/

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 == *s2 && *s1 != 0 && *s2 != 0){
        s1++;
        s2++;
    }
    if (*s1 > *s2)
        return 1;
    if (*s1 < *s2)
        return -1;
    return 0;
}
