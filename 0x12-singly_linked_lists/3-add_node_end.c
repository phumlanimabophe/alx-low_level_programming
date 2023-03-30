#include "lists.h"
#include <string.h>

/**
 * _strlen - gets the length of a string.
 * @s: string
 * Return: length of the string.
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * add_node_end - adds a node at the end of a list.
 * @head: current head address
 * @str: pointer to string
 * Return: the address of the new node, or NULL on failure.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = NULL;
	list_t *last = *head;

	if (!head)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	new_node->len = _strlen(str);
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}

	while (last->next)
		last = last->next;

	last->next = new_node;

	return (new_node);
}
