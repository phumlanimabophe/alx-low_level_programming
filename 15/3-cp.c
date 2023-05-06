#include "main.h"
#include <stdio.h>

void error_file(int file, char *arg)
{
    if (file == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", arg);
        exit(98);
    }
}

int main(int argc, char *argv[])
{
    int file_from, file_to, err_close;
    ssize_t nchars, nwr;
    char buf[1024];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    file_from = open(argv[1], O_RDONLY);
    error_file(file_from, argv[1]);

    file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
    error_file(file_to, argv[2]);

    while ((nchars = read(file_from, buf, 1024)) > 0)
    {
        nwr = write(file_to, buf, nchars);
        if (nwr == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            exit(99);
        }
    }

    err_close = close(file_from);
    if (err_close == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
        exit(100);
    }

    err_close = close(file_to);
    if (err_close == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
        exit(100);
    }

    return (0);
}
