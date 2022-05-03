/*
** EPITECH PROJECT, 2021
** object/draw_outline.c
** File description:
** Objectu
*/

#include "htd.h"

void object_draw_outlines(object_t *object, sfVector2f pos, float x, float y)
{
    pos.x += x * object->outline;
    pos.y += y * object->outline;
    sfSprite_setPosition(object->sprite, pos);
    sfRenderWindow_drawSprite(GAME.window, object->sprite, NULL);
}

void object_draw_outline(object_t *object)
{
    sfColor color = sfSprite_getColor(object->sprite);
    sfVector2f pos = sfSprite_getPosition(object->sprite);

    sfSprite_setColor(object->sprite, sfBlack);
    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++)
            object_draw_outlines(object, pos, x - 1, y - 1);
    sfSprite_setColor(object->sprite, color);
    sfSprite_setPosition(object->sprite, pos);
}
