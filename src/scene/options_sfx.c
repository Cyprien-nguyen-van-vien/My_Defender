/*
** EPITECH PROJECT, 2021
** scene/options_sfx.c
** File description:
** Main function
*/

#include "htd.h"

static int sfx_select(int current_value, float const *values, int size)
{
    float value = 0;
    int value_position = 0;

    for (int i = 0; i < size; i++) {
        if (values[i] <= current_value && value < values[i]) {
            value = values[i];
            value_position = i;
        }
    }
    return values[(value_position + 1) % size];
}

void scene_options_sfx_display(object_t *button, float sfx)
{
    char *text = NULL;
    char *str_string = NULL;

    str_string = my_int_to_str(sfx);
    text = my_strcat("SFX: ", str_string);
    sfText_setString(button->text, text);
    free(text);
    free(str_string);
}

void scene_options_sfx(object_t *button)
{
    int values_size = sizeof(SFX_VALUES) / sizeof(SFX_VALUES[0]);
    float sfx = GAME.option.sfx;

    sfx = sfx_select(GAME.option.sfx, SFX_VALUES, values_size);
    scene_options_sfx_display(button, sfx);
    GAME.option.sfx = sfx;
}
