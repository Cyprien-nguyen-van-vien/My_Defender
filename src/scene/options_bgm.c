/*
** EPITECH PROJECT, 2021
** scene/options_bgm.c
** File description:
** Main function
*/

#include "htd.h"

static int bgm_select(int current_value, float const *values, int size)
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

void scene_options_bgm_display(object_t *button, float bgm)
{
    char *text = NULL;
    char *str_string = NULL;

    str_string = my_int_to_str(bgm);
    text = my_strcat("BGM: ", str_string);
    sfText_setString(button->text, text);
    free(text);
    free(str_string);
}

void scene_options_bgm(object_t *button)
{
    int values_size = sizeof(BGM_VALUES) / sizeof(BGM_VALUES[0]);
    float bgm = GAME.option.bgm;

    bgm = bgm_select(GAME.option.bgm, BGM_VALUES, values_size);
    scene_options_bgm_display(button, bgm);
    bgm_volume(bgm);
    GAME.option.bgm = bgm;
}
