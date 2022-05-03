/*
** EPITECH PROJECT, 2021
** scene/title.c
** File description:
** Main function
*/

#include "htd.h"

int scene_title(void)
{
    object_t *scene = scene_create();

    scene_replace(scene, SCN_BG, object_create("title.jpg"));
    scene->child[SCN_BG]->size.x = SCR_X;
    scene->child[SCN_BG]->size.y = SCR_Y;
    bgm_play("Toy soliders Orchestral.ogg");
    scene_title_screen(scene);
    object_destroy(scene);
    return 0;
}
