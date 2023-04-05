#include <stdio.h>
#include "lists.h"

/**
 * Returns the number of nodes in a linked list.
 *
 * @param h a pointer to the head of the list.
 * @return the number of nodes in the list.
 */
size_t listint_len(const listint_t *h)
{
    size_t num_nodes = 0;

    while (h != NULL) {
        h = h->next;
        num_nodes++;
    }

    return num_nodes;
}
