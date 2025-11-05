/*
** EPITECH PROJECT, 2025
** test_sort_array.c
** File description:
** Test for sort a double array of strings
*/

#include "../include/my.h"
#include <criterion/criterion.h>
#include <stddef.h>

Test(sort_array, whith_differents_words)
{
    char *arr[9] = {"Hello", "world", "abcd",
        "Abdc2", "42", "How", "How", "ZER", "aaaaa"};
    char *attempt[9] = {"42",
        "aaaaa",
        "abcd",
        "Abdc2",
        "Hello",
        "How",
        "How",
        "world",
        "ZER"};
    char **result;

    result = sort_array(arr, 9);
    for (int i = 0; i < 9; i++)
        cr_assert_str_eq(result[i], attempt[i]);
    free(result);
}

Test(sort_array, with_same_words)
{
    char *arr[3] = {"Hello", "Hello", "Hello"};
    char *attempt[3] = {"Hello", "Hello", "Hello"};
    char **result;

    result = sort_array(arr, 3);
    for (int i = 0; i < 3; i++)
        cr_assert_str_eq(result[i], attempt[i]);
    free(result);
}
