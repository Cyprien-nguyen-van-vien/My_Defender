/*
** EPITECH PROJECT, 2021
** scene/game/hud/wave.c
** File description:
** Main function
*/

#include "htd.h"

void scene_game_hud_wave_update(object_t *object)
{
    int wave = GAME.wave;
    char *text_wave = NULL;
    char *text = NULL;

    text_wave = my_int_to_str(wave);
    if (text_wave == NULL)
        return;
    text = my_strcat("Wave: ", text_wave);
    free(text_wave);
    if (text != NULL) {
        sfText_setString(object->child[2]->text, text);
        free(text);
    }
}

static void scene_game_hud_wave_config(object_t *object)
{
    sfColor color = sfGreen;

    color.a = 150;
    sfSprite_setColor(object->sprite, COLOR_GRAY_50);
    sfSprite_setColor(object->child[1]->sprite, color);
    object_text_create(object->child[2], "wave: 0");
    object_set_size(object, HUD_X, 100, -1);
    object_add_position(object, 0, 0, -1);
}

object_t *scene_game_hud_wave_create(void)
{
    object_t *object = NULL;

    object = object_create("health_back.png");
    if (object == NULL)
        return NULL;
    object_child_malloc(object, 3);
    object->child[0] = object_create("health_back.png");
    object->child[1] = object_create("pixel.png");
    object->child[2] = object_create("health_front.png");
    scene_game_hud_wave_config(object);
    return object;
}
