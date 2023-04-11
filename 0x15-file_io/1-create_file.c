#include "main.h"

/**
 *  create_file - create a file and write in it
 * 
 * @filename:file to be created
 * 
 * @text_content: content of the file created
 * 
 * Return: 1 or -1;
 */
int create_file(const char *filename, char *text_content)
{
    int fd = -1, len = 0, w = 0;
    
    if (!filename)
        return -1;
    
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (fd == -1)
        return -1;
    
    if (text_content)
    {
        len = strlen(text_content);
        w = write(fd, text_content, len);
        if (w == -1)
            return -1;
    }
    
    close(fd);
    return 1;
}
