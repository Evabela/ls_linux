/*
** EPITECH PROJECT, 2025
** test_sort_array.c
** File description:
** Test for sort a double array of strings
*/

#include "../include/my.h"
#include <criterion/criterion.h>

Test (sort_array, whith_differents_words)
{
    char *arr[9] = {"Hello", "world", "abcd", "Abdc2", "42", "How", "How", "ZER", "aaaaa"};
    char *attempt[9] = {"42", "Abdc2", "Hello", "How", "How", "ZER", "aaaaa", "abcd", "world"};

    sort_array(arr, 9);
    cr_assert_eq(arr, attempt);
}

Test (sort_array, with_no_words)
{
    char **arr[0];
    char **attempt[0];

    sort_array(arr, 0);
    cr_assert_eq(arr, attempt);
}

Test(sort_array, with_same_words)
{
    char *arr[3] = {"Hello", "Hello", "Hello"};
    char *attempt[3] = {"Hello", "Hello", "Hello"};

    sort_array(arr, 3);
    cr_assert_eq(arr, attempt);
}
