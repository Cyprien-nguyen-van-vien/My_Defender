/*
** EPITECH PROJECT, 2021
** object/child_malloc.c
** File description:
** Objectu
*/

#include "htd.h"

object_t *object_child_malloc(object_t *object, int size)
{
    object->child = malloc(sizeof(object_t *) * (size + 1));
    if (object->child == NULL)
        return object;
    for (int i = 0; i < size + 1; i++)
        object->child[i] = NULL;
    return object;
}
