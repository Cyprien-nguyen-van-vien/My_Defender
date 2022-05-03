/*
** EPITECH PROJECT, 2021
** scene/create.c
** File description:
** Main function
*/

#include "htd.h"

object_t *scene_create(void)
{
    object_t *scene = NULL;

    scene = object_create("void.png");
    if (scene == NULL)
        return NULL;
    object_child_malloc(scene, SCN_SIZE);
    if (scene->child == NULL) {
        object_destroy(scene);
        return NULL;
    }
    for (int i = 0; i < SCN_SIZE; i++)
        scene->child[i] = object_create("void.png");
    return scene;
}
