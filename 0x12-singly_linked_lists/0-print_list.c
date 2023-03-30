#include "lists.h"

/**
 * list_len - returns the number of nodes in a list_t list
 * @h: pointer to the list
 * Return: number of nodes in the list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
													