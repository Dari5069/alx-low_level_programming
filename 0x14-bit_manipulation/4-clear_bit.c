#include "main.h"
/**
 * clear_bit - 0 is given to set the value of the bit
 * @n: change the number to the pointer
 * @index: clear the bit index
 * Return: if success return 1 but if it fails return -1
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
return (-1);

*n = (~(1UL << index) & *n);

return (1);
}
