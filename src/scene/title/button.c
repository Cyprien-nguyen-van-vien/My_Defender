/*
** EPITECH PROJECT, 2021
** scene/title/button.c
** File description:
** Main function
*/

#include "htd.h"

static object_t *scene_title_button_create(int id)
{
    object_t *object = NULL;
    int png_size = 3;
    char *png[3] = {NULL, BUTTON_TITLE_PAW1, BUTTON_TITLE_PAW2};

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

object_t *scene_title_buttons(void)
{
    char *msg[4] = {"Play", "Options", "Exit", NULL};
    object_t *object = NULL;

    object = object_create("void.png");
    object->child = malloc(sizeof(object_t *) * 5);
    for (int i = 0; msg[i] != NULL; i++) {
        object->child[i + 1] = NULL;
        object->child[i] = scene_title_button_create(i);
        object->child[i]->position.y = SCR_Y_HALF * 1.5 - 150 * i + 100;
        object_text_create(object->child[i], msg[2 - i]);
    }
    return object;
}
