/*
** EPITECH PROJECT, 2021
** object/add_position.c
** File description:
** Objectu
*/

#include "htd.h"

void object_add_position(object_t *object, float x, float y, int childs)
{
    if (object == NULL)
        return;
    object->position.x += x;
    object->position.y += y;
    if (childs == 0 || object->child == NULL)
        return;
    for (int i = 0; object->child[i] != NULL; i++)
        object_add_position(object->child[i], x, y, childs - 1);
}
