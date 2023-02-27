#include "main.h"

/**
 * puts2 - Prints one char out of two of a string.
 * @str: The string containing characters.
 * Return: void
 */

void puts2(char *s)
{
	int a;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (a % 2 == 0)
		{
			_putchar(s[a]);
		}
	}
	_putchar('\n');
}
