/*
** EPITECH PROJECT, 2021
** object/if_hovering.c
** File description:
** Objectu
*/

#include "htd.h"

int object_is_hovering_lines(sfVector2f *start, sfVector2f *end, int outline)
{
    start->x -= outline;
    start->y -= outline;
    end->x += outline;
    end->y += outline;
}

int object_is_hovering_seg(object_t *object, sfVector2f mouse)
{
    sfVector2f pos = object->position;
    sfVector2u size = object->size;
    sfVector2f start = {pos.x, pos.y};
    sfVector2f end = {pos.x + size.x, pos.y + size.y};

    if (object->outline > 0)
        object_is_hovering_lines(&start, &end, object->outline);
    if (object->centered_position) {
        start.x -= size.x / 2;
        start.y -= size.y / 2;
        end.x -= size.x / 2;
        end.y -= size.y / 2;
    }
    if (start.x <= mouse.x && mouse.x <= end.x)
        if (start.y <= mouse.y && mouse.y <= end.y)
            return 1;
    return 0;
}

int object_is_hovering(object_t *object, sfVector2f mouse, int childs)
{
    int hover = 0;

    object->hover = 0;
    if (object_is_hovering_seg(object, mouse))
        object->hover = 1;
    if (childs != 0 && object->child != NULL)
        for (int i = 0; object->child[i] != NULL; i++)
            hover += object_is_hovering(object->child[i], mouse, childs - 1);
    if (object->hover == 1)
        return 1;
    if (hover > 0)
        hover = 1;
    object->hover = hover;
    return hover;
}
