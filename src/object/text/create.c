/*
** EPITECH PROJECT, 2021
** object/text/create.c
** File description:
** Scribe Oyez Oyez
*/

#include "htd.h"

void object_text_create(object_t *object, char const *written)
{
    if (object->text != NULL)
        sfText_destroy(object->text);
    object->text = sfText_create();
    sfText_setFont(object->text, GAME.font[GOODDOG_PLAIN_TTF]);
    if (written != NULL)
        sfText_setString(object->text, written);
    sfText_setCharacterSize(object->text, 75);
    sfText_setFillColor(object->text, sfWhite);
}
