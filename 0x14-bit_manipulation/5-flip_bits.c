#include "main.h"
/**
 * flip_bits - check the bits changed
 * @n: the first digit
 * @m: the second digit
 * Return: bits changed
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{

int i, count = 0;
unsigned long int current;
unsigned long int exclusive  = n ^ m;

for (i = 63; i >= 0; i--)
{
current = exclusive >> i;
if (current & 1)
count++;
}
return (count);
}
