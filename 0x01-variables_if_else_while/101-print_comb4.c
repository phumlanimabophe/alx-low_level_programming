/*
 * File: 102-print_comb5.c
 * Auth: Brennan D Baraban
 */

#include <unistd.h>

/**
 * print_comb - prints all possible different combinations of three digits
 * in ascending order, separated by ', '
 */
void print_comb(void)
{
    int i, j, k;

    for (i = 0; i < 8; i++)
    {
        for (j = i + 1; j < 9; j++)
        {
            for (k = j + 1; k < 10; k++)
            {
                putchar(i % 10 + '0');
                putchar(j % 10 + '0');
                putchar(k % 10 + '0');

                if (i == 7 && j == 8 && k == 9)
                    continue;

                putchar(',');
                putchar(' ');
            }
        }
    }
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    print_comb();
    putchar('\n');

    return (0);
}

