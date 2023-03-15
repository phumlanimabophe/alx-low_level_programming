/*
 * File: 0-reset_to_98.c
 */

#include "main.h"
#include <stdio.h>

/**
 * wrdcnt - counts the number of words in a string
 * @s: string
 * Return: int of number of words
 */
int wcount(char *s)
{
	int i, n = 0;

	for (i = 0; s[i]; i++)
		n += s[i] != ' ' && (i == 0 || s[i - 1] == ' ');

	return (n);
}

/**
 * strtow - splits a string into words
 * @str: string
 * Return: pointer to an array of strings
 */
char **strtow(char *str)
{
	int i, j, k, l, n = 0, ch = 0;
	char **x;

	if (!str || !*str || (n = wcount(str)) == 1)
		return (NULL);
	
	x = malloc(n * sizeof(char *));
	if (!x)
		return (NULL);
	
	x[n - 1] = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			for (j = 1; str[i + j] != ' ' && str[i + j]; j++)
				;
			j++;
			x[ch] = malloc(j * sizeof(char));
			if (!x[ch])
			{
				for (k = 0; k < ch; k++)
					free(x[k]);
				free(x[n - 1]);
				free(x);
				return (NULL);
			}
			for (l = 0; l < j - 1; l++)
				x[ch][l] = str[i + l];
			x[ch++][l] = '\0';
			i += j;
		}
		else
			i++;
	}
	return (x);
}
