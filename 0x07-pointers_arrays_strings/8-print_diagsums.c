/*
 * File: 8-print_diagsums.c
 */

#include "main.h"

/**
 * print_diagsums - prints the sums of the diagonals of a matrix.
 * @a: pointer to the matrix.
 * @size: size of the matrix.
 *
 * Return: void.
 */
void print_diagsums(int *a, int size)
{
    int sum1 = 0, sum2 = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        sum1 += *(a + i * size + i);
        sum2 += *(a + i * size + (size - i - 1));
    }

    putchar(sum1 / 10 + '0');
    putchar(sum1 % 10 + '0');
    putchar(',');
    putchar(' ');
    putchar(sum2 / 10 + '0');
    putchar(sum2 % 10 + '0');
    putchar('\n');
}
