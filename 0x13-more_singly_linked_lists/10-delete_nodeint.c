#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - delete node at index
 * @head: head node
 * @index: index node
 * Return: 1 success, -1 failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev, *node;

	if (!*head)
		return (-1);

	prev = get_nodeint_at_index(*head, index - 1);
	node = get_nodeint_at_index(*head, index);
	if (!node)
		return (-1);
	if (index != 0)
		prev->next = node->next;
	else
		*head = node->next;

	node->next = NULL;
	free(node);
	return (1);
}

/**
 * get_nodeint_at_index - get node at index
 * @head: head node
 * @index: index node
 * Return: address of index node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);

	while (head)
	{
		if (index == i)
			return (head);
		i++;
		head = head->next;
	}
	return (NULL);
}
