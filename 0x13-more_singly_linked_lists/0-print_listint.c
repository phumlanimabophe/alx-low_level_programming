#include <stdio.h>
#include "lists.h"

/**
 * Prints the integer values in a linked list and returns the number of nodes.
 *
 * @param h a pointer to the head of the list.
 * @return the number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
    size_t num_nodes = 0;

    while (h != NULL) {
        printf("%d\n", h->n);
        h = h->next;
        num_nodes++;
    }

    return num_nodes;
}
