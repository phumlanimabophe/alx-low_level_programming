/*
 * File: 3-strspn.c
 */

#include "main.h"
#include <stdio.h>

/**
 * _strspn - gets the length of a prefix substring.
 * @s: input string
 * @accept: bytes to compare
 *
 * Return: the number of bytes in the initial segment of s which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i, j;

	for (i = 0; s[i] != '\0'; i++) // loop through each character in s
	{
		for (j = 0; accept[j] != '\0'; j++) // loop through each character in accept
		{
			if (s[i] == accept[j])
			{
				count++; // increment count if byte is found in accept
				break; // break out of inner loop to avoid unnecessary comparisons
			}
		}
		if (accept[j] == '\0') // if s[i] is not found in accept, break out of outer loop
			break;
	}

	return (count); // return the count of matching bytes
}
