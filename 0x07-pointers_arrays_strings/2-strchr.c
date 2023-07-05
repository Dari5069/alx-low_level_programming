#include "main.h"
/**
 * *_strchr - function that locates a character in a string
 * @s: input value
 * @c: input value
 *
 * Return: NULL if the character not found
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
				s++;
	}
	if (*s == c)
		return (s);
			return (NULL);
}
