#include "lists.h"

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to the pointer of the head of the list
 * @str: string to be added as content of the new node
 *
 * Return: address of the new element or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new_node, *last_node;
    unsigned int len_str;

    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    len_str = 0;
    while (str[len_str])
        len_str++;

    new_node->str = strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return (NULL);
    }
    new_node->len = len_str;
    new_node->next = NULL;

    if (*head == NULL)
        *head = new_node;
    else
    {
        last_node = *head;
        while (last_node->next)
            last_node = last_node->next;
        last_node->next = new_node;
    }
    return (new_node);
}
