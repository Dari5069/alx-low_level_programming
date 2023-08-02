#include "lists.h"

/**
 * sum_listint - adds rhe sum of the data in the listint_t list
 * @head: the first linked list node
 * Return: sum
 */

int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *temp = head;

while (temp != NULL)
{
sum += head->n;
temp = temp->next;
}
return (sum);

}
