/*
 * File: 3-strspn.c
 */

#include "main.h"
#include <stdio.h>

/**
 * _strspn - gets the length of a prefix substring.
 * @s: string to check
 * @accept: bytes to compare
 * Return: number of bytes in the initial segment of s which
 *         consist only of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;
    int found;

    while (*s != '\0')
    {
        found = 0;
        while (*accept != '\0')
        {
            if (*s == *accept)
            {
                count++;
                found = 1;
                break;
            }
            accept++;
        }
        if (found == 0)
            break;

        s++;
    }

    return count;
}
