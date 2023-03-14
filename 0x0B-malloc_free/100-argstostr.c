/*
 * File: 0-reset_to_98.c
 */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of the program
 * @ac: Number of arguments
 * @av: Arguments
 *
 * Return: A pointer to a new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	int i, j, k, len;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* Compute the length of the new string */
	len = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			len++;
		len++; /* For the newline character */
	}

	/* Allocate memory for the new string */
	str = (char *) malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);

	/* Copy the arguments into the new string */
	k = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			str[k] = av[i][j];
			k++;
		}
		str[k] = '\n';
		k++;
	}
	str[k] = '\0';

	return (str);
}
