/*
** EPITECH PROJECT, 2021
** game_grid.c
** File description:
** Grid to go along the level
*/

#include "htd.h"

object_t *grid_square(object_t *child, sfVector2f *pos, sfColor color)
{
    child->position.x = pos->x;
    child->position.y = pos->y;
    child->size.x = TILE;
    child->size.y = TILE;
    sfSprite_setColor(child->sprite, color);
    pos->x += TILE * 2;
    if (pos->x >= LEVEL_X) {
        pos->x = 0 + TILE * ((int)(pos->y / TILE) % 2);
        pos->y += TILE;
    }
}

object_t *grid(void)
{
    int size = ((LEVEL_X / TILE) * (SCR_Y / TILE)) / 2;
    sfColor color = {0, 0, 0, 30};
    sfVector2f pos = {TILE, 0};
    object_t *object = object_create("void.png");

    if (object == NULL)
        return NULL;
    object_child_malloc(object, size);
    for (int i = 0; i < size; i++) {
        object->child[i] = object_create("pixel.png");
        grid_square(object->child[i], &pos, color);
    }
    return object;
}
