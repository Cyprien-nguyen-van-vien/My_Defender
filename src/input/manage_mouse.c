/*
** EPITECH PROJECT, 2021
** input/manage_mouse.c
** File description:
** Keys go brrrrr
*/

#include "htd.h"

sfVector2i mouse_get_cursor_position(void)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(GAME.window);

    return mouse_pos;
}

void input_manage_mouse(int id)
{
    object_t *object = mouse_object_get(id);

    if (sfMouse_isButtonPressed(sfMouseLeft))
        GAME.input[id].select += 1;
    else
        GAME.input[id].select = 0;
    if (sfMouse_isButtonPressed(sfMouseRight))
        GAME.input[id].back += 1;
    else
        GAME.input[id].back = 0;
    GAME.input[id].exit = 0;
    object->position.x = mouse_get_cursor_position().x;
    object->position.y = mouse_get_cursor_position().y;
}
