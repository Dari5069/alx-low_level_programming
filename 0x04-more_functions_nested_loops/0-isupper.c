#include "main.h"

/**
 * _isupper - checkes for  lowercase letters
 * @c:The characters to be checked
 * return 1 for uppercase latters or 0 for anything else
 */

int _isupper(int c)

{
if (c >= 65 && c <= 90)
{
return (1);
}
else
return (0);
}
