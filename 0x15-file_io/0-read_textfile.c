#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - read and print numbers of letters to STDOUT
 * @letters: read the numbers of letters
 * @filename: read text file
 * Return: 0 if can't opened or read,0 if NULL and 0 if fails amount of bytes
 */

ssize_t read_textfile(const char *filename, size_t letters)
{

char *buff;
ssize_t t;
ssize_t w;
ssize_t fd;

fd = open(filename, O_RDONLY);
if (fd == -1)

return (0);
buff = malloc(sizeof(char) * letters);
t = read(fd, buff, letters);
w = write(STDOUT_FILENO, buff, t);

free(buff);
close(fd);
return (w);
}
