/*
** EPITECH PROJECT, 2021
** file/read.c
** File description:
** I teaching this file how to read
*/

#include "htd.h"

static char *copy_and_return(char *file)
{
    int i = 0;
    int length = LEN(file);
    char *copied_file = NULL;

    copied_file = malloc(sizeof(char) * (length + 1));
    for (i = 0; file[i] != '\0'; i++)
        copied_file[i] = file[i];
    copied_file[i] = '\0';
    free(file);
    return copied_file;
}

static char *file_read_malloc_error(int fd)
{
    close(fd);
    return NULL;
}

char *file_read(char const *path)
{
    int fd = 0;
    char *file = NULL;

    if (!file_exists(path))
        return NULL;
    fd = open(path, O_RDONLY);
    file = malloc(sizeof(char) * (10000 + 1));
    if (file == NULL)
        return file_read_malloc_error(fd);
    read(fd, file, 10000);
    file[10000] = '\0';
    close(fd);
    return copy_and_return(file);
}
