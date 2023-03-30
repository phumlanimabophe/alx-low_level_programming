#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: head of linked list to free
 *
 * Return: void
 */
void free_list(list_t *head)
{
    list_t *current;

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current->str);
        free(current);
    }
}
