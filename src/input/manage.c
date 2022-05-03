/*
** EPITECH PROJECT, 2021
** input/manage.c
** File description:
** Main function
*/

#include "htd.h"

object_t *mouse_object_get(int id)
{
    return GAME.mouse_object->child[id];
}

void input_manage_method(int id, int control_type)
{
    if (control_type == 1)
        input_manage_mouse(id);
    if (control_type == 2)
        input_manage_keyboard(id);
    if (control_type == 3)
        input_manage_numpad(id);
    for (int i = 0; i < INPUTS_CONTROLLER4 - INPUTS_CONTROLLER0; i++)
        if (control_type == INPUTS_CONTROLLER0 + i)
            input_manage_controller(id, i);
}

void input_manage(int id)
{
    object_t *object = mouse_object_get(id);

    if (GAME.input[id].control_type < 1)
        return;
    if (object == NULL) {
        GAME.mouse_object->child[id] = object_create("cursor2.png");
        GAME.mouse_object->child[id]->size.x = TILE * 4;
        GAME.mouse_object->child[id]->size.y = TILE * 2;
        object = mouse_object_get(id);
        sfSprite_setColor(object->sprite, color_player_get(id));
    }
    input_manage_method(id, GAME.input[id].control_type);
}
