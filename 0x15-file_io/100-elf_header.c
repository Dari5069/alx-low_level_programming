#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
* check_elf - Verify if a file is an ELF file.
* @e_ident: Pointer to an array containing the ELF magic numbers.
*
* Description: Exit with code 98 if not an ELF file.
*/
void check_elf(unsigned char *e_ident)
{
int index;

for (index = 0; index < 4; index++)
{
if (e_ident[index] != 127 &&
e_ident[index] != 'E' &&
e_ident[index] != 'L' &&
e_ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
* print_magic - Display the magic numbers of an ELF header.
* @e_ident: Pointer to an array containing the ELF magic numbers.
*
* Description: Magic numbers are separated by spaces.
*/
void print_magic(unsigned char *e_ident)
{
int index;

printf(" Magic: ");

for (index = 0; index < EI_NIDENT; index++)
{
printf("%02x", e_ident[index]);

if (index == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}

/**
* print_class - Display the class of an ELF header.
* @e_ident: Pointer to an array containing the ELF class.
*/
void print_class(unsigned char *e_ident)
{
printf(" Class: ");

switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}


/**
* main - Display the information contained in the ELF header.
* @argc: Number of arguments supplied to the program.
* @argv: Array of pointers to the arguments.
*
* Return: 0 on success.
*
* Exit code 98 if the file is not an ELF file or if the function fails.
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *header;
int o, r;

o = open(argv[1], O_RDONLY);
if (o == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close_elf(o);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
r = read(o, header, sizeof(Elf64_Ehdr));
if (r == -1)
{
free(header);
close_elf(o);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

check_elf(header->e_ident);
printf("ELF Header:\n");
print_magic(header->e_ident);
print_class(header->e_ident);

free(header);
close_elf(o);
return (0);
}
