#include "lists.h"

/**
 * get_nodeint_at_index - linked list returns in an index
 * @head: first linked list node
 * @index:return node index
 * Return:points to the NULL node or node we're looking at
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
listint_t *temp = head;
unsigned int count = 0;

while (temp != NULL)
{
if (count == index)
{
return (temp);
}
temp = temp->next;
count++;
}

return (NULL);
}
