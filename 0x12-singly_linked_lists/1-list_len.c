#include <stdlib.h>
#include "lists.h"

/**
 * list_len - the number of elements in linked list
 * @h: pointer to the list_t list
 *
 * Return: elements in h
 */
size_t list_len(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		x++;
		h = h->next;
	}
	return (x);
}
