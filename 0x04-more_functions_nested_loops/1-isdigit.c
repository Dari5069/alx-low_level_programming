#include "main.h"

/**
 *_isdigit - checkes for a digit
 * @c: The digit to be ckhecked
 * Return 1 for a digit character ot 0 for anything else
 */
int _isdigit(int c)
{
if (c >= 45 && c <= 57)
{
return (1);
}
return (0);
}
