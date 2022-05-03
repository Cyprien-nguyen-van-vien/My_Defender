/*
** EPITECH PROJECT, 2021
** input/manage_controller.c
** File description:
** Yeah, that's it.
*/

#include "htd.h"

float input_manage_controller_speed(void)
{
    float speed = ((float)GAME.delta / 100000) * ARROWS_SENSIBILITY * 2;

    return speed;
}

void input_manage_controller_move(int id, int cid)
{
    object_t *object = mouse_object_get(id);
    float speed = input_manage_controller_speed();
    sfVector2f axis = {sfJoystick_getAxisPosition(cid, sfJoystickX), 0};

    axis.y = sfJoystick_getAxisPosition(cid, sfJoystickY);
    object->position.x += speed * (axis.x * 0.01);
    object->position.y += speed * (axis.y * 0.01);
    object->position.x = MIN(MAX(object->position.x, SCR_X - 10), 0);
    object->position.y = MIN(MAX(object->position.y, SCR_Y - 10), 0);
}

int input_manage_controller_check(int *val, int button, int cid)
{
    if (sfJoystick_isButtonPressed(cid, button))
        *val += 1;
    else
        *val = 0;
    return *val;
}

void input_manage_controller(int id, int cid)
{
    md_inputs_t *inputs = &GAME.input[id];
    object_t *object = mouse_object_get(id);
    int *check_val[] = {&inputs->select, &inputs->exit, &inputs->back, NULL};
    int check_key[] = {JB_A, JB_START, JB_B};

    input_manage_controller_move(id, cid);
    for (int i = 0; check_val[i] != NULL; i++)
        input_manage_controller_check(check_val[i], check_key[i], cid);
}
