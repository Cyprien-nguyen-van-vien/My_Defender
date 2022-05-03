/*
** EPITECH PROJECT, 2021
** object/set_anchor.c
** File description:
** Used when the user resize the window
*/

#include "htd.h"

void object_set_anchor(object_t *object, int anchor, int childs)
{
    if (object == NULL)
        return;
    object->anchor = anchor;
    if (childs == 0 || object->child == NULL)
        return;
    for (int i = 0; object->child[i] != NULL; i++)
        object_set_anchor(object->child[i], anchor, childs - 1);
}
