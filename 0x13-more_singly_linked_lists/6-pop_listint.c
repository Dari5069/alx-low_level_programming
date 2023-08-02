#include "lists.h"


/**
 * pop_listint - deleting the node head of the linked list
 * @head: first element in the linked list
 * Return: element tha was delet and 0 if list is empty
 *
 */
int pop_listint(listint_t **head)
{
listint_t *temp;
int num;

if (head == NULL || *head == NULL)
{
return (0);
}

temp = *head;
num = temp->n;
*head = temp->next;
free(temp);

return (num);
}
