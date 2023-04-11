#include "main.h"

/**
 * read_textfile - read text ...
 * @letters:number of letters to read size_t
 * @filename: name of file char
 * 
 * Return: read the file display it or error 0
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
