/*
** EPITECH PROJECT, 2021
** hoppy/to_scene_object.c
** File description:
** Conversion go brrrrrr
*/

#include "htd.h"

void hoppy_to_scene_object(object_t *scene_layer)
{
    int id = 0;

    for (int i = 0; i < HOPPIES_MAX; i++) {
        if (GAME.hoppy_object[i] != NULL) {
            scene_layer->child[id] = GAME.hoppy_object[i];
            id++;
        }
    }
    scene_layer->child[id] = NULL;
}
