/*
** EPITECH PROJECT, 2021
** enemy/to_scene_object.c
** File description:
** Conversion go brrrrrr
*/

#include "htd.h"

void enemy_to_scene_object(object_t *scene_layer)
{
    int id = 0;

    for (int i = 0; i < ENEMIES_MAX; i++) {
        if (GAME.enemy_object[i] != NULL) {
            scene_layer->child[id] = GAME.enemy_object[i];
            id++;
        }
    }
    scene_layer->child[id] = NULL;
}
