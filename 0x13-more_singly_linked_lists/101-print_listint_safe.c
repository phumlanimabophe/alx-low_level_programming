#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - print list
 * @head: head node
 * Return: amount of nodes in list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t size = 0;
	const listint_t *tmp[100] = {NULL}; // initialize array with NULL values
	const listint_t *current = head;

	if (!head)
		exit(98);

	while (current && size < 100) // added limit to avoid going out of array bounds
	{
		tmp[size++] = current; // update array and size at the same time
		printf("[%p] %d\n", (void *)current, current->n);
		current = current->next;

		if (current) // check if we have a next node
		{
			for (size_t i = 0; i < size; i++)
			{
				if (tmp[i] == current) // check if the node is already in the array
				{
					printf("-> [%p] %d\n", (void *)current, current->n);
					return size;
				}
			}
		}
	}
	return size;
}
