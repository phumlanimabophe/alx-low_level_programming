#include <stdlib.h>
#include "lists.h"
/**
 * add_nodeint - add node at the beginning of the list
 * Return: pointer to new node
 * @head: pointer to head node
 * @n: value for new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node;

	if (!head)
		return (NULL);
	node = malloc(sizeof(listint_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = *head;
	*head = node;
	return (node);
}

/**
 * get_nodeint_at_index - get node at index
 * Return: pointer to node at index
 * @head: pointer to head node
 * @index: index of node to get
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

/**
 * insert_nodeint_at_index - insert node at given position
 * Return: pointer to new node
 * @head: pointer to head node
 * @idx: index where new node should be inserted
 * @n: value for new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *node, *prev;

	if (!head)
		return (NULL);

	if (idx == 0)
		return (add_nodeint(head, n));

	prev = get_nodeint_at_index(*head, idx - 1);
	if (!prev)
		return (NULL);

	node = malloc(sizeof(listint_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->next = prev->next;
	prev->next = node;

	return (node);
}
