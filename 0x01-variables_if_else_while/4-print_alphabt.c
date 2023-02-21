/*
 * File= 4-print_alphabt.c
 */

#include <stdio.h>

/**
 * main - When I was having that alphabet soup...
 *
 * Return: Always 0.
 */
int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		if (letter != 'e' && letter != 'q')
			putchar(letter);
	}

	putchar('\n');

	return (0);
}

