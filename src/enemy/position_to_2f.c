/*
** EPITECH PROJECT, 2021
** enemy/position_to_2f.c
** File description:
** Gets a vector2f from enemy position
*/

#include "htd.h"

float path_pythagore(sfVector2f start, sfVector2f end)
{
    float x = ABS(end.x - start.x);
    float y = ABS(end.y - start.y);
    float square = x * x + y * y;

    return sqrtf(square);
}

float path_theta(sfVector2f start, sfVector2f end)
{
    float x = end.x - start.x;
    float y = end.y - start.y;
    float theta = atan2f(ABS(y), ABS(x));
    float pi = 3.141592653589793238;

    if (x < 0)
        theta = pi - theta;
    if (y < 0)
        theta = 0 - theta;
    return theta;
}

sfVector2f *ept2f_seg(sfVector2f *coor, float pos, int path_idx)
{
    sfVector2f start = GAME.path[path_idx].point;
    sfVector2f end = GAME.path[path_idx + 1].point;
    float theta = GAME.path[path_idx].theta;
    float max_pos = GAME.path[path_idx].distance;

    coor->x += cosf(theta) * MAX(pos, max_pos) * TILE;
    coor->y += sinf(theta) * MAX(pos, max_pos) * TILE;
    if (pos > max_pos) {
        if (GAME.path[path_idx + 1].distance < 0)
            return NULL;
        return ept2f_seg(coor, pos - max_pos, path_idx + 1);
    }
    return coor;
}

sfVector2f enemy_position_to_2f(int const id)
{
    float position = GAME.enemy[id].position;
    sfVector2f *path_ptd = NULL;
    sfVector2f start = GAME.path[0].point;
    sfVector2f coor = {start.x * TILE, start.y * TILE};

    path_ptd = ept2f_seg(&coor, position, 0);
    if (path_ptd == NULL) {
        GAME.hearts.value -= 5;
        enemy_destroy(id);
    }
    return coor;
}
