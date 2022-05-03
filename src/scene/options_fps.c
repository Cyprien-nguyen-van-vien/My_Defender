/*
** EPITECH PROJECT, 2021
** scene/options_fps.c
** File description:
** Main function
*/

#include "htd.h"

static int fps_select(int current_value, int const *values, int size)
{
    int value = 0;
    int value_position = 0;

    for (int i = 0; i < size; i++) {
        if (values[i] <= current_value && value < values[i]) {
            value = values[i];
            value_position = i;
        }
    }
    return values[(value_position + 1) % size];
}

void scene_options_fps_display(object_t *button, int fps)
{
    char *text = NULL;
    char *str_string = NULL;

    str_string = my_int_to_str(fps);
    text = my_strcat("Max FPS: ", str_string);
    sfText_setString(button->text, text);
    free(text);
    free(str_string);
}

void scene_options_fps(object_t *button)
{
    int values_size = sizeof(FPS_VALUES) / sizeof(FPS_VALUES[0]);
    int fps = GAME.option.fps;

    fps = fps_select(GAME.option.fps, FPS_VALUES, values_size);
    scene_options_fps_display(button, fps);
    sfRenderWindow_setFramerateLimit(GAME.window, fps);
    GAME.option.fps = fps;
}
