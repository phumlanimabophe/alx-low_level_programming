#include <stdlib.h>
#include "lists.h"

/**
 * Frees all nodes in a linked list.
 *
 * @param head a pointer to the head of the list.
 */
void free_listint(listint_t *head)
{
    listint_t *current_node, *next_node;

    current_node = head;
    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
}
