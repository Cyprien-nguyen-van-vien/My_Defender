/*
** EPITECH PROJECT, 2021
** object/draw.c
** File description:
** Objectu
*/

#include "htd.h"

static void object_draw_text(object_t *object)
{
    sfVector2f pos = sfSprite_getPosition(object->sprite);
    sfFont *font = NULL;

    if (object->text == NULL)
        return;
    pos.x += (object->size.x - sfText_getGlobalBounds(object->text).width) / 2;
    sfText_setPosition(object->text, pos);
    sfText_setOrigin(object->text, sfSprite_getOrigin(object->sprite));
    sfRenderWindow_drawText(GAME.window, object->text, NULL);
}

static void draw_rotation(object_t *object, sfVector2f *pos, sfVector2f *scl)
{
    sfVector2f origin = {0, 0};

    if (object->size.x != object->texture_size.x)
        return;
    if (object->size.y != object->texture_size.y)
        return;
    origin.x += object->size.x / 2;
    origin.y += object->size.y / 2;
    pos->x += (scl->x * object->texture_size.x) / 2;
    pos->y += (scl->y * object->texture_size.y) / 2;
    sfSprite_setRotation(object->sprite, object->rotation);
    sfSprite_setOrigin(object->sprite, origin);
}

static void object_draw_values(object_t *object)
{
    sfVector2f setposition = {object->position.x, object->position.y};
    sfVector2f setscale = {1, 1};

    setscale.x = (1 / (float)object->texture_size.x) * object->size.x;
    setscale.y = (1 / (float)object->texture_size.y) * object->size.y;
    if (object->centered_position) {
        setposition.x -= (setscale.x * object->texture_size.x) / 2;
        setposition.y -= (setscale.y * object->texture_size.y) / 2;
    }
    if (object->centered_rotation)
        draw_rotation(object, &setposition, &setscale);
    sfSprite_setPosition(object->sprite, setposition);
    sfSprite_setScale(object->sprite, setscale);
}

static void object_draw_circle(object_t *object)
{
    sfVector2f pos = sfSprite_getPosition(object->sprite);
    float radius = 0;
    sfCircleShape *circle = NULL;

    if (object->circle == NULL)
        return;
    circle = object->circle;
    radius = sfCircleShape_getRadius(circle);
    pos.x -= radius - (object->size.x / 2);
    pos.y -= radius - (object->size.y / 2);
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setOrigin(circle, sfSprite_getOrigin(object->sprite));
    sfRenderWindow_drawCircleShape(GAME.window, circle, NULL);
}

object_t *object_draw(object_t *object)
{
    if (object == NULL)
        return NULL;
    object_draw_values(object);
    if (object->outline > 0)
        object_draw_outline(object);
    object_draw_circle(object);
    sfRenderWindow_drawSprite(GAME.window, object->sprite, NULL);
    object_draw_text(object);
    if (object->child != NULL)
        for (int i = 0; object->child[i] != NULL; i++)
            object_draw(object->child[i]);
    return object;
}
