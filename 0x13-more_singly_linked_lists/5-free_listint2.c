#include "lists.h"

/**
 * free_listint2 - lists to be freed
 * @head: points to the listint_t to frees
 */
void free_listint2(listint_t **head)
{
listint_t *temp;
listint_t *next_node;

if (head == NULL)
{
return;
}

temp = *head;

while (temp != NULL)
{
next_node = temp->next;
free(temp);
temp = next_node;
}

*head = NULL;
}
