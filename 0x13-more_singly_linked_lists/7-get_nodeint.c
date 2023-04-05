#include <stdlib.h>
#include "lists.h"

/**
 * get_nodeint_at_index - returns the node at a given index in a linked list
 * @head: pointer to the head of the linked list
 * @index: index of the node to return
 *
 * Return: pointer to the node at the given index, or NULL if the index is
 *         out of range
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    unsigned int i;

    for (i = 0; head != NULL && i < index; i++)
        head = head->next;

    return (head);
}
