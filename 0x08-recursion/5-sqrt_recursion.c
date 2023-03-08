/*
 * File: 0-memset.c
 */

#include "main.h"

/**
 * is_prime_number - Checks whether a given number is prime.
 * @n: The number to check.
 *
 * Return: 1 if n is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
    /* Base case: n is less than 2, so it's not prime */
    if (n < 2)
        return 0;

    /* Base case: n is 2 or 3, so it's prime */
    if (n == 2 || n == 3)
        return 1;

    /* Base case: n is even, so it's not prime */
    if (n % 2 == 0)
        return 0;

    /* Recursive case: check odd divisors up to the square root of n */
    int i;
    for (i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

