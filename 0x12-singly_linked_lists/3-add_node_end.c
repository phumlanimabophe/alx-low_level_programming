#include "lists.h"

/**
 * add_node_end - Add a new node to the end of a list_t list.
 * @head: A pointer to the head of the list_t list.
 * @str: The string to be added to the new node.
 *
 * Return: If memory allocation fails or head is NULL, NULL.
 *         Otherwise, the address of the new element.
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new, *last = *head;
    size_t len = 0;

    while (str && str[len])
        len++;

    new = malloc(sizeof(list_t));
    if (!new)
        return (NULL);

    new->str  = strdup(str);
    new->len  = len;
    new->next = NULL;

    if (!*head)
        *head = new;

    else
    {
        while (last->next)
            last = last->next;

        last->next = new;
    }

    return (new);
}
