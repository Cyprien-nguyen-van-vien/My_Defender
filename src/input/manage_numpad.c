/*
** EPITECH PROJECT, 2021
** input/manage_numbad.c
** File description:
** Henry t'es dans le projet maintenant
*/

#include "htd.h"

float input_manage_numpad_speed(void)
{
    float speed = ((float)GAME.delta / 100000) * ARROWS_SENSIBILITY;

    if (sfKeyboard_isKeyPressed(sfKeyNumpad3))
        return speed / 2;
    if (sfKeyboard_isKeyPressed(sfKeyNumpad9))
        return speed * 2;
    return speed;
}

void input_manage_numpad_move(int id)
{
    object_t *object = mouse_object_get(id);
    int keys[4] = {sfKeyNumpad4, sfKeyNumpad6, sfKeyNumpad8, sfKeyNumpad2};
    float keys_x[4] = {-1, 1, 0, 0};
    float keys_y[4] = {0, 0, -1, 1};
    float speed = input_manage_numpad_speed();

    for (int i = 0; i < 4; i++) {
        if (sfKeyboard_isKeyPressed(keys[i])) {
            object->position.x += speed * keys_x[i];
            object->position.y += speed * keys_y[i];
        }
    }
    object->position.x = MIN(MAX(object->position.x, SCR_X - 10), 0);
    object->position.y = MIN(MAX(object->position.y, SCR_Y - 10), 0);
}

int input_manage_numpad_check(int *val, int key)
{
    if (sfKeyboard_isKeyPressed(key))
        *val += 1;
    else
        *val = 0;
    return *val;
}

void input_manage_numpad(int id)
{
    md_inputs_t *inputs = &GAME.input[id];
    object_t *object = mouse_object_get(id);
    int *check_val[] = {&inputs->select, &inputs->exit, &inputs->back, NULL};
    int check_key[] = {sfKeyAdd, sfKeyNumpad0, sfKeySubtract};

    input_manage_numpad_move(id);
    for (int i = 0; check_val[i] != NULL; i++)
        input_manage_numpad_check(check_val[i], check_key[i]);
}
