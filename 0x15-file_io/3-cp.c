#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * cp - copies src to desinations
 * 
 * @file_to: the destination file.
 * @file_from: the source file
 *
 * Return: integer
 */

#define BUFF_SIZE 1024

int cp(char *file_to, char *file_from) {
    char buffer[BUFF_SIZE];
    int td, fd, fr, fw;

    fd = open(file_from, O_RDONLY);
    if (fd < 0) return 98;

    td = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (td < 0) return 99;

    while ((fr = read(fd, buffer, BUFF_SIZE)) > 0) {
        if ((fw = write(td, buffer, fr)) != fr) return 99;
    }

    close(fd);
    close(td);
    return (fr < 0) ? 98 : 0;
}


int main(int ac, char **av) {
    if (ac != 3) {
        fprintf(stderr, "Usage: cp file_from file_to\n");
        exit(97);
    }

    int ret = cp(av[2], av[1]);

    if (ret != 0) {
        fprintf(stderr, "Error: ");
        if (ret == 98) fprintf(stderr, "Can't read from file %s\n", av[1]);
        else if (ret == 99) fprintf(stderr, "Can't write to %s\n", av[2]);
        else fprintf(stderr, "Can't close file descriptor\n");
        exit(ret);
    }

    return 0;

}
