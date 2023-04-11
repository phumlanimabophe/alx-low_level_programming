#ifndef _main_H_
#define _main_H_

#include <sys/stat.h>
#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int append_text_to_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int cp(char *file_to, char *file_from);

#endif
