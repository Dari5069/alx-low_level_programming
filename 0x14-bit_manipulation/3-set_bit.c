#include "main.h"

/**
 * set_bit - a given index of a bit to set
 * @n: change the number to the pointer
 * @index: 1 is to be set to the index bit
 * Return: if success return 1 and -1 if it fails
 *
 */

int set_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
return (-1);

*n = ((1UL << index) | *n);
return (1);
}
