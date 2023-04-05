\#include <stdlib.h>
#include "lists.h"

/**
 * Removes and returns the data stored in the head node of a list.
 * If the list is empty, returns 0.
 *
 * @param head a pointer to a pointer to the head node of the list.
 * @return the data stored in the original head node, or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
    int data;
    listint_t *second;

    if (head == NULL || *head == NULL) {
        return 0;
    }

    data = (*head)->n;
    second = (*head)->next;
    free(*head);
    *head = second;

    return data;
}
