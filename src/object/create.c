/*
** EPITECH PROJECT, 2021
** object/create.c
** File description:
** Objectu
*/

#include "htd.h"

void object_create_default(object_t *object)
{
    object->anchor = 0;
    object->centered_position = 0;
    object->centered_rotation = 0;
    object->child = NULL;
    object->circle = NULL;
    object->hover = 0;
    object->outline = 0;
    object->position.x = 0;
    object->position.y = 0;
    object->rotation = 0;
    object->text = NULL;
}

void object_create_texture(object_t *object, const char *path)
{
    char *filename = NULL;

    if (path == NULL)
        filename = CAT(GRAPHICS, DEFAULT_TEXTURE);
    else
        filename = CAT(GRAPHICS, path);
    if (!file_exists(filename)) {
        free(filename);
        filename = CAT(GRAPHICS, DEFAULT_TEXTURE);
        object->texture = sfTexture_create(1, 1);
    }
    object->texture = sfTexture_createFromFile(filename, NULL);
    if (filename != NULL)
        free(filename);
}

object_t *object_create(const char *path)
{
    object_t *object = NULL;

    object = malloc(sizeof(object_t));
    object->sprite = sfSprite_create();
    object_create_texture(object, path);
    object->size = sfTexture_getSize(object->texture);
    object->texture_size = sfTexture_getSize(object->texture);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    object_create_default(object);
    return object;
}
