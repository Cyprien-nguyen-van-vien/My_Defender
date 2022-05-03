/*
** EPITECH PROJECT, 2021
** path.c
** File description:
** Generate a part of a path
*/

#include "htd.h"

void path_destroy_all(void)
{
    if (GAME.path == NULL)
        return;
    free(GAME.path);
    GAME.path = NULL;
}

void path_malloc(int size)
{
    path_destroy_all();
    if (size > 0)
        GAME.path = malloc(sizeof(md_path_t) * (size + 1));
    else
        return;
    for (int i = 0; i < size + 1; i++)
        GAME.path[i].distance = -1;
    GAME.path[0].size = 0;
}

void path_add(float x, float y)
{
    int idx = GAME.path[0].size;
    sfVector2f *new = NULL;
    sfVector2f *previous = NULL;

    new = &GAME.path[idx].point;
    new->x = x;
    new->y = y;
    GAME.path[0].size += 1;
    if (idx == 0)
        return;
    previous = &GAME.path[idx - 1].point;
    GAME.path[idx - 1].distance = path_pythagore(*previous, *new);
    GAME.path[idx - 1].theta = path_theta(*previous, *new);
}

float path_add_str_seg(char a, float *mem)
{
    if (IS_DIGIT(a))
        *mem = *mem * 10 + a - '0';
    if (a == 'e')
        return ENEMIES_BORDER * -1;
    if (a == 'E')
        return ENEMIES_BORDER;
    return 0;
}

void path_add_str(char const *arg)
{
    int i = 0;
    float mem = 0;
    sfVector2f values = {0, 0};

    for (i = 0; arg[i] != 44 && arg[i] != '\0'; i++)
        values.x += path_add_str_seg(arg[i], &mem);
    values.x += (mem * 0.01 * LEVEL_X) / TILE;
    mem = 0;
    for (i = i; arg[i] != '\0'; i++)
        values.y += path_add_str_seg(arg[i], &mem);
    values.y += (mem * 0.01 * SCR_Y) / TILE;
    path_add(values.x, values.y);
}
