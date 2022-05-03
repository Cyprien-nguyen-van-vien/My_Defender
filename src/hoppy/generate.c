/*
** EPITECH PROJECT, 2021
** hoppy/generate.c
** File description:
** Main function
*/

#include "htd.h"

static int read_data(char const *file, int *index)
{
    int value = 0;

    while (file[*index] < '0' || '9' < file[*index]) {
        if (file[*index] == '\0')
            return 0;
        *index += 1;
    }
    while ('0' <= file[*index] && file[*index] <= '9') {
        value = value * 10 + file[*index] - '0';
        *index += 1;
    }
    return value;
}

static int struct_create(char const *path, md_hoppy_t *hoppy)
{
    int index = 0;
    char *file = NULL;
    char *new_path = my_strcat(HOPPY_PATH, path);

    file = file_read(new_path);
    free(new_path);
    if (file == NULL)
        return 0;
    hoppy->texture = read_data(file, &index);
    hoppy->damage = read_data(file, &index);
    hoppy->speed = read_data(file, &index);
    hoppy->range = read_data(file, &index);
    hoppy->cost = read_data(file, &index);
    hoppy->special = read_data(file, &index);
    return 1;
}

static md_hoppy_t generate_single(char const *path, int *idx)
{
    sfVector2f vec0 = {0, 0};
    md_hoppy_t hoppy = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    if (struct_create(path, &hoppy) == 1) {
        *idx += 1;
        GAME.hoppy_data_count += 1;
    }
    return hoppy;
}

void hoppy_generate(void)
{
    int j = 0;
    char *conf = NULL;
    char **ary = NULL;

    conf = file_read(HOPPIES_CONF);
    if (conf == NULL)
        return;
    ary = my_str_to_array(conf, "\n");
    free(conf);
    if (ary == NULL || ary[0] == NULL)
        return;
    for (int i = 0; j < HOPPY_COUNT && ary[i] != NULL; i++)
        GAME.hoppy_data[j] = generate_single(ary[i], &j);
    for (int i = 0; ary[i] != NULL; i++)
        free(ary[i]);
    free(ary);
}
