/*
** EPITECH PROJECT, 2021
** object/destroy.c
** File description:
** Objectu destroyu
*/

#include "htd.h"

object_t *object_destroy(object_t *object)
{
    if (object == NULL)
        return NULL;
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
    if (object->text != NULL)
        sfText_destroy(object->text);
    if (object->circle != NULL)
        sfCircleShape_destroy(object->circle);
    if (object->child != NULL) {
        for (int i = 0; object->child[i] != NULL; i++)
            object_destroy(object->child[i]);
        free(object->child);
    }
    free(object);
    return NULL;
}

object_t *object_destroy_null(object_t **pointed_object)
{
    *pointed_object = object_destroy(*pointed_object);
    return *pointed_object;
}
