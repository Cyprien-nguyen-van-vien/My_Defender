/*
** EPITECH PROJECT, 2021
** file/to_level_analyze.c
** File description:
** convert level file into actual informations
*/

#include "htd.h"

int ftl_skip(char const *str, int *idx)
{
    if (*idx > 0)
        if (str[*idx - 1] == '\\')
            return *idx;
    while (str[*idx] == ' ')
        *idx += 1;
    if (str[*idx] == '\\')
        *idx += 1;
    return *idx;
}

int ftl_remaining(char const *str, int idx)
{
    int length = 0;

    while (str[idx] != '\0') {
        ftl_skip(str, &idx);
        if (str[idx] != '\0')
            length++;
        idx++;
    }
    return length;
}

char *ftl_extract_str(char const *str, int idx)
{
    int idx2 = 0;
    int length = ftl_remaining(str, idx);
    char *arg = NULL;

    arg = malloc(sizeof(char) * (length + 1));
    while (str[ftl_skip(str, &idx)] != '\0') {
        arg[idx2] = str[idx];
        idx++;
        idx2++;
    }
    arg[length] = '\0';
    return arg;
}

void ftl_analyze(char const *str)
{
    int idx = 0;
    char keys[] = "B|";
    void (*fcts[])(char const *) = {&bgm_play, &path_add_str};
    char *arg = NULL;

    if (LEN(str) < 2)
        return;
    if (!char_in_str(str[ftl_skip(str, &idx)], keys))
        return;
    arg = ftl_extract_str(str, idx + 1);
    for (int i = 0; keys[i] != '\0'; i++)
        if (str[idx] == keys[i])
            (*fcts[i])(arg);
    free(arg);
}
