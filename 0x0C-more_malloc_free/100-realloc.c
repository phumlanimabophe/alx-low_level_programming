#include "main.h"
#include <stdlib.h>

char *_my_memcpy(char *dest, char *src, unsigned int n);

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated with malloc
 * @old_size: size of the allocated space of ptr
 * @new_size: new size to allocate
 *
 * Return: pointer to the reallocated memory block
 *         NULL if new_size is zero and ptr is not NULL,
 *         or if the allocation fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (ptr != NULL)
	{
		_my_memcpy(new_ptr, ptr, (old_size < new_size) ? old_size : new_size);
		free(ptr);
	}

	return (new_ptr);
}

/**
 * _my_memcpy - copies n bytes from memory area src to memory area dest
 * @dest: pointer to the destination array
 * @src: pointer to the source array
 * @n: number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_my_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
