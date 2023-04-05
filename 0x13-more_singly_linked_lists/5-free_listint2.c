#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * Frees all nodes in a linked list, and sets the head pointer to NULL.
 *
 * @param head a pointer to a pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
    listint_t *current_node, *next_node;

    if (head == NULL || *head == NULL) {
        return;
    }

    current_node = *head;
    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    *head = NULL;
}
