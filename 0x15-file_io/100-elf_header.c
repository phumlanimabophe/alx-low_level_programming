#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int string_compare(const char *s1, const char *s2, size_t n)
{
	for (; n && *s1 && *s2; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	if (n)
	{
		if (*s1)
			return (1);
		if (*s2)
			return (-1);
	}
	return (0);
}

void close_file_descriptor(int fd)
{
	if (close(fd) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't close fd\n", 22);
	exit(98);
}

void read_file_descriptor(int fd, char *buf, size_t count)
{
	if (read(fd, buf, count) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't read from file\n", 28);
	close_file_descriptor(fd);
	exit(98);
}

void print_elf_magic(const unsigned char *buf)
{
	unsigned int i;

	if (string_compare((const char *) buf, ELFMAG, 4))
	{
		write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
		exit(98);
	}

	printf("ELF Header:\n  Magic:   ");

	for (i = 0; i < 16; ++i)
		printf("%02x%c", buf[i], i < 15 ? ' ' : '\n');
}

size_t print_elf_class(const unsigned char *buf)
{
	printf("  %-34s ", "Class:");

	if (buf[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
		return (64);
	}
	if (buf[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
		return (32);
	}
	printf("<unknown: %x>\n", buf[EI_CLASS]);
	return (32);
}

int print_elf_data(const unsigned char *buf)
{
	printf("  %-34s ", "Data:");

	if (buf[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
		return (1);
	}
	if (buf[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
		return (0);
	}
	printf("Invalid data encoding\n");
	return (0);
}

void print_elf_version(const unsigned char *buf)
{
	printf("  %-34s %u", "Version:", buf[EI_VERSION]);

	if (buf[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

void print_elf_osabi(const unsigned char *buf) {
    const char *os_table[19] = {
        "UNIX - System V",
        "UNIX - HP-UX",
        "UNIX - NetBSD",
        "UNIX - GNU",
        "<unknown: 4>",
        "<unknown: 5>",
        "UNIX - Solaris",
        "UNIX - AIX",
        "UNIX - IRIX",
        "UNIX - FreeBSD",
        "UNIX - Tru64",
        "Novell - Modesto",
        "UNIX - OpenBSD",
        "VMS - OpenVMS",
        "<unknown: 14>",
        "<unknown: 15>",
        "<unknown: 16>",
        "<unknown: 17>",
        "<unknown: 18>"
    };
    int osabi = buf[7];
    if (osabi >= 0 && osabi <= 18) {
        printf("OSABI: %s\n", os_table[osabi]);
    } else {
        printf("Unknown OSABI value: %d\n", osabi);
    }
}

int main() {
    unsigned char buf[16] = {0x7f, 0x45, 0x4c, 0x46, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    print_elf_osabi(buf);
    return 0;
}
