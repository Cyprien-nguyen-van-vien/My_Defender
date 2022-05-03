/*
** EPITECH PROJECT, 2021
** scene/options_buttons.c
** File description:
** Main function
*/

#include "htd.h"

object_t *scene_options_buttons_create(int id)
{
    object_t *object = NULL;
    int png_size = 4;
    char *png[6] = {BUTTON_TITLE_PAW2, NULL, NULL, NULL, NULL, NULL};

    if (id >= png_size || png[id] == NULL)
        object = object_create(BUTTON_TITLE);
    else
        object = object_create(png[id]);
    object->position.x = SCR_X_HALF;
    object->position.y = SCR_Y_HALF;
    object->centered_position = 1;
    object->outline = 10;
    return object;
}

object_t *scene_options_buttons_window(void)
{
    object_t *object = NULL;

    object = object_create("enemies.png");
    if (object == NULL)
        return NULL;
    object->size.x = 300 + 500 + 100;
    object->size.y = 400 + 450 + 200 + 75 - 200;
    object->position.x = SCR_X_HALF - object->size.x / 2;
    object->position.y = SCR_Y_HALF - object->size.y / 2;
    object->outline = 10;
    return object;
}

object_t *scene_options_buttons(void)
{
    char *msg[7] = {"?", "?", "?", "Return", "Back to menu", "Exit HTD", NULL};
    object_t *object = NULL;

    object = scene_options_buttons_window();
    object->child = malloc(sizeof(object_t *) * 7);
    for (int i = 0; msg[i] != NULL; i++) {
        object->child[i + 1] = NULL;
        object->child[i] = scene_options_buttons_create(i);
        object->child[i]->position.y = SCR_Y_HALF - 150 * i + 375;
        object_text_create(object->child[i], msg[5 - i]);
    }
    scene_options_fps_display(object->child[3], GAME.option.fps);
    scene_options_sfx_display(object->child[4], GAME.option.sfx);
    scene_options_bgm_display(object->child[5], GAME.option.bgm);
    return object;
}

void scene_options_buttons_evt(object_t *buttons, int id)
{
    if (id < 0)
        return;
    if (id == 0)
        sfRenderWindow_close(GAME.window);
    if (id == 1 || id == 2)
        GAME.scene_closing = 3 - id;
    if (id == 3)
        scene_options_fps(buttons->child[id]);
    if (id == 4)
        scene_options_sfx(buttons->child[id]);
    if (id == 5)
        scene_options_bgm(buttons->child[id]);
}
