/*
** EPITECH PROJECT, 2021
** object/set_size.c
** File description:
** Objectu
*/

#include "htd.h"

void object_set_size(object_t *object, int x, int y, int childs)
{
    if (object == NULL)
        return;
    if (object->size.x >= 0)
        object->size.x = x;
    if (object->size.y >= 0)
        object->size.y = y;
    if (childs == 0 || object->child == NULL)
        return;
    for (int i = 0; object->child[i] != NULL; i++)
        object_set_size(object->child[i], x, y, childs - 1);
}
