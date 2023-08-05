#include "main.h"

/**
 * get_endianness - identify if a machine is a big or little endian.
 * Return: if it's 0 return big and if it's 1 return little.
 */
int get_endianness(void)
{
unsigned int i = 1;
char *c = (char *) &i;

return (*c);
}
