#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - at the beginning of a linked list add a new node
 * @head: points to the first node of the list
 * @n: data to put in that new node
 * Return: pointer to the new node, if faills return NULL
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new;

new = malloc(sizeof(listint_t));
if (!new)
return (NULL);

new->n = n;
new->next = *head;
*head = new;

return (new);
}
