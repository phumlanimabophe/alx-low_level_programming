#include "main.h"
/**
 * append_text_to_file - appand a text to the end of file
 * @filename: filename
 * 
 * @text_content: text content of the file
 * Return: 1 or -1
 */

int append_text_to_file(const char *filename, char *text_content)
{
    if (!filename)
        return -1;

    int fd = open(filename, O_APPEND | O_WRONLY);
    if (fd == -1)
        return -1;

    int len = 0;
    if (text_content) {
        while (text_content[len])
            len++;
        if (write(fd, text_content, len) == -1)
            return -1;
    }

    close(fd);
    return 1;
}
