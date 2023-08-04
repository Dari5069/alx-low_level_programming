#include "main.h"

/**
 * get_bit - output the index value of the bit in a decimal number
 * @n: look for the number
 * @index: the bit of the index
 * Return: return the bit value
 */
int get_bit(unsigned long int n, unsigned int index)
{
int bit_val;
{
if (index > 63)
return (-1);

bit_val = (n >> index) & 1;
}
return (bit_val);
}
