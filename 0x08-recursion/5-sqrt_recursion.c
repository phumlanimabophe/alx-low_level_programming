/*
 * File: 0-memset.c
 */

#include "main.h"

/**
 * _sqrt_recursion - Finds the natural square root of a number using recursion.
 * @n: The number to find the square root of.
 *
 * Return: The square root of n if it exists, otherwise -1.
 */
int _sqrt_recursion(int n)
{
    /* Base case: n has a natural square root */
    if (n == 0 || n == 1)
        return n;

    /* Base case: n does not have a natural square root */
    if (n < 0)
        return -1;

    /* Recursive case: try a lower number */
    int root = _sqrt_recursion(n / 4) * 2;
    if (root * root <= n && (root + 1) * (root + 1) > n)
        return root;
    else if (root * root < n)
        return root + 1;
    else
        return -1;
}
