/*
 * File: 0-reset_to_98.c
 */

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *
 *strtow - splits a string into words
 *
 *@str: input string
 *
 *Return: pointer to an array of strings or NULL if failure 
 */

char **strtow(char *str)
{
int i, word_count = 0, j = 0, k, word_len, m;
char **p, *word;

if (str == NULL || *str == '\0')
return (NULL);

for (i = 0; str[i] != '\0'; i++)
{
if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
word_count++;
}

p = (char **)malloc((word_count + 1) * sizeof(char *));
if (p == NULL)
return (NULL);

for (i = 0; str[i] != '\0' && j < word_count; i++)
{
if (str[i] != ' ')
{
word_len = 0;
for (k = i; str[k] != ' ' && str[k] != '\0'; k++)
word_len++;

scss
Copy code
 	word = (char *)malloc((word_len + 1) * sizeof(char));
 	if (word == NULL)
 	{
 		for (k = 0; k < j; k++)
 			free(p[k]);
 		free(p);
 		return (NULL);
 	}

 	for (m = 0; m < word_len; m++, i++)
 		word[m] = str[i];
 	word[m] = '\0';
 	p[j++] = word;
 }
}

p[j] = NULL;
return (p);
}
