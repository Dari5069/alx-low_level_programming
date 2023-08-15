#include <elf.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/**
* check_elf - Verifies if a file is an ELF file.
* @e_ident: Array containing the ELF magic numbers.
*
* Exit with code 98 if not an ELF file.
*/
void check_elf(unsigned char *e_ident)
{
int i;

for (i = 0; i < 4; i++)
{
if (e_ident[i] != 127 &&
e_ident[i] != 'E' &&
e_ident[i] != 'L' &&
e_ident[i] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
* print_magic - Displays the magic numbers of an ELF header.
* @e_ident: Array containing the ELF magic numbers.
*/
void print_magic(unsigned char *e_ident)
{
int i;

printf(" Magic: ");

for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x", e_ident[i]);

if (i == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}


/**
* main - Displays information from the ELF header.
* @argc: Number of command-line arguments.
* @argv: Array of command-line arguments.
*
* Return: 0 on success.
*/
int main(int argc, char *argv[])
{
Elf64_Ehdr *header;
int fd, read_bytes;

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s <ELF-file>\n", argv[0]);
exit(98);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}

header = malloc(sizeof(Elf64_Ehdr));
if (!header)
{
close(fd);
dprintf(STDERR_FILENO, "Error: Memory allocation failed\n");
exit(98);
}

read_bytes = read(fd, header, sizeof(Elf64_Ehdr));
if (read_bytes != sizeof(Elf64_Ehdr))
{
free(header);
close(fd);
dprintf(STDERR_FILENO, "Error: Unable to read ELF header\n");
exit(98);
}

check_elf(header->e_ident);
printf("ELF Header:\n");
print_magic(header->e_ident);


free(header);
close(fd);
return (0);
}
