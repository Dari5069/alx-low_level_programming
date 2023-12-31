#include "lists.h"

/**
 * add_nodeint_end -  a new node added at the end of a listint_t list.
 * @head:points to first element in the list
 * @n: data to input in the new element
 * Return: new node or Null when fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new;
listint_t *temp = *head;

new = malloc(sizeof(listint_t));
if (!new)
return (NULL);

new->n = n;
new->next = NULL;

if (*head == NULL)
{
*head = new;
return (new);
}

while (temp->next)
temp = temp->next;

temp->next = new;

return (new);
}
