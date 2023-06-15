#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes a node at a given index in a doubly linked list
 * @head: Pointer to a pointer to the head of the list
 * @index: The index of the node to be deleted
 * Return: 1 if the deletion succeeded, or -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *p1, *res_mem = *head; // Declare variables for traversal

	unsigned int counter = 0; // Initialize counter

	// Check if the list or head is empty
	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		// Update the head and link the new head to the previous second node
		*head = res_mem->next;
		if (res_mem->next == NULL)
			return (-1);
		res_mem->next->prev = NULL;
		free(res_mem); // Free the deleted node
		return (1);
	}

	while (counter < index)
	{
		// Traverse the list to find the node at the given index
		if (res_mem->next == NULL)
			return (-1);
		res_mem = res_mem->next;
		counter++;
	}

	// Update the links of the previous and next nodes to remove the current node
	res_mem->prev->next = res_mem->next;
	if (res_mem->next)
		res_mem->next->prev = res_mem->prev;

	if (res_mem->next == NULL)
	{
		// If the deleted node is the last node, update the previous node's link
		p1 = res_mem->prev;
		p1->next = NULL;
		free(res_mem); // Free the deleted node
		return (1);
	}

	free(res_mem); // Free the deleted node
	return (1);
}
