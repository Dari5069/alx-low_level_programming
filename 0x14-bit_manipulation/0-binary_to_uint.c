#include "main.h"
#include <stddef.h>
/**
 * binary_to_uint - Binary number to unsignedint to be converted
 * @b: binary number containing a string
 * Return: the number to convert
 *
 */

unsigned int binary_to_uint(const char *b)
{
int i;
unsigned int dec_val = 0;

if (!b)
return (0);

while (b[i] != '\0')
{

if (b[i] != '0' && b[i] != '1')
return (0);

dec_val = (dec_val << 1) + (b[i] - '0');
i++;
}

return (dec_val);
}
