#include <stdio.h>

/**
 * print_binary - equivalent binary number to be print
 *@n: print Binary numbers
 */

void print_binary(unsigned long int n)
{
int count = 0;
unsigned long int current;

while (current > 0)
{
current >>= 1;
if (n & current)
{
putchar('1');
count = 1;
}
else if (count)
{
putchar('0');
}

}

if (!count)
{
putchar('0');
}
}
