/*
 * Name=2-print_alphabet_x10.c
 * 
 */

#include "main.h"

/**
 * print_alphabet_x10 - Prints 10 times the alphabet in lowercase.
 */
void print_alphabet_x10(void)
{
	int count = 0;
	char alphas;

	while (count++ <= 9)
	{
		for (alphas = 'a'; alphas <= 'z'; alphas++)
			_putchar(alphas);
		_putchar('\n');
	}
}
