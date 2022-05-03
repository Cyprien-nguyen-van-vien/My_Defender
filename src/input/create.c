/*
** EPITECH PROJECT, 2021
** input/create.c
** File description:
** Main function
*/

#include "htd.h"

md_inputs_t *input_create(md_inputs_t *input)
{
    input->control_type = 0;
    input->select = 0;
    input->back = 0;
    input->exit = 0;
    input->up = 0;
    input->left = 0;
    input->down = 0;
    input->right = 0;
    return input;
}

void input_create_all(md_inputs_t *inputs)
{
    for (int i = 0; i < PLAYERS_MAX; i++) {
        input_create(&inputs[i]);
    }
}
