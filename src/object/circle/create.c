/*
** EPITECH PROJECT, 2021
** object/circle/create.c
** File description:
** En cercle les enfants
*/

#include "htd.h"

void object_circle_create(object_t *object, float radius, sfColor color)
{
    if (object->circle != NULL)
        sfCircleShape_destroy(object->circle);
    object->circle = sfCircleShape_create();
    sfCircleShape_setRadius(object->circle, radius);
    sfCircleShape_setOutlineColor(object->circle, color);
    sfCircleShape_setOutlineThickness(object->circle, 5);
    sfCircleShape_setFillColor(object->circle, sfTransparent);
}
