#include "main.h"

/**
 * create_file - a function that creates a file
 * @filename: the name of the file to creat to the pointer
 * @text_content: A string to a pointer to write the file
 * Return: --1 if function fails and -1 otherwise
 *
 */

int create_file(const char *filename, char *text_content)
{
int fd, w, len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
for (len = 0; text_content[len];)
len++;
}
fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
w = write(fd, text_content, len);

if (fd == -1 || w == -1)
return (-1);

close(fd);

return (1);
}
