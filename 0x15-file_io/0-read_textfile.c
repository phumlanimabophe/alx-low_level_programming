#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * read_textfile - that reads a text file and prints
 * @filename: variable pointer
 * @letters: size letters
 * Description: Write a function that reads a text file and prints it
 * to the POSIX standard output.
 * Return: the actual number of letters it could read and print, 0 otherwise
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1) return 0;

    char *buff = malloc(letters);
    ssize_t rd = read(fd, buff, letters);
    close(fd);
    if (rd == -1) {
        free(buff);
        return 0;
    }

    ssize_t wd = write(STDOUT_FILENO, buff, rd);
    free(buff);
    return wd;
}
