/*
** EPITECH PROJECT, 2021
** file/to_level.c
** File description:
** if a file exists
*/

#include "htd.h"

void ftl_conv(char const *level)
{
    int path_size = 0;
    char **args = my_str_to_array(level, "\n");

    for (int i = 0; args[i] != NULL; i++)
        if (args[i][0] == '|')
            path_size++;
    path_malloc(path_size);
    for (int i = 0; args[i] != NULL; i++)
        ftl_analyze(args[i]);
    for (int i = 0; args[i] != NULL; i++)
        free(args[i]);
    free(args);
}

int file_to_level(char const *path)
{
    char *content = NULL;

    if (!file_exists(path))
        return 0;
    content = file_read(path);
    if (content == NULL) {
        window_crash(ER_MSG_MALLOC);
        return 0;
    }
    ftl_conv(content);
    free(content);
    return 1;
}
