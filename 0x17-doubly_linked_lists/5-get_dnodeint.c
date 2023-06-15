#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a doubly linked list
 * @head: Pointer to the head of the list
 * @index: The index of the node to retrieve
 * Return: Pointer to the nth node, or NULL if it doesn't exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int counter = 0;

	while (counter < index)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
		counter++;
	}
	return (head);
}
