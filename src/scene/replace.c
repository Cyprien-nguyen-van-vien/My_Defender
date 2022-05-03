/*
** EPITECH PROJECT, 2021
** scene/replace.c
** File description:
** Main function
*/

#include "htd.h"

object_t *scene_replace(object_t *scene, int index, object_t *object)
{
    object_destroy_null(&scene->child[index]);
    scene->child[index] = object;
    return scene;
}
