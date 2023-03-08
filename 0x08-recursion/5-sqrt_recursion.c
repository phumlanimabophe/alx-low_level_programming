/*
 * File: 0-memset.c
 */

#include "main.h"

/**
 * _memset - fills memory with a constant byte .
 * @s: pass allocated memory - array of characters .
 * @b: pass char bytes .
 * @n: pass number of spaces to fill .
 * Return: pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(s + i) = b;
	}
	return (s);
}
