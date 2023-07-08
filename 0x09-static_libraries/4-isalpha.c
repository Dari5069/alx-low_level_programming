#include "main.h"
/**
 * _isalpha - checkes for alphabetic character
 * @c: characters to be checked
 * Return: 1 if c is a letter and 0 if it's not
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
