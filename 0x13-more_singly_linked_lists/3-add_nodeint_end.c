#include <stdlib.h>
#include "lists.h"

/**
 * Adds a new node with the given integer value at the end of a linked list.
 *
 * @param head a pointer to the head of the list.
 * @param n the integer value for the new node.
 * @return a pointer to the new node.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new_node, *last_node;

    if (head == NULL) {
        return NULL;
    }

    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->n = n;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return new_node;
    }

    last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;

    return new_node;
}
