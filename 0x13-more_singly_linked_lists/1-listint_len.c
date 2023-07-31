#include "lists.h"
/**
 * listint_len - elements in a linked listint_t list.
 * @h:  traverse linked list of type listint_t
 * Return: node
 */

size_t listint_len(const listint_t *h)
{
size_t node_count = 0;

while (h != NULL)
{
node_count++;
h = h->next;
}

return (node_count);
}
