/*
** EPITECH PROJECT, 2021
** scene/game/h_hud.c
** File description:
** Hoppy Hud
*/

#include "htd.h"

object_t *scene_game_h_hud_plcmnt_seg(void)
{
    object_t *object = NULL;

    object = object_create("Placement.png");
    if (object == NULL)
        return NULL;
    sfSprite_setColor(object->sprite, sfTransparent);
    object_circle_create(object, TILE * 6, sfTransparent);
    object_text_create(object, "");
    sfText_setColor(object->text, sfTransparent);
    object->size.x = TILE * 2;
    object->size.y = TILE * 2;
    return object;
}

object_t *scene_game_h_hud_plcmnt(void)
{
    object_t *object = NULL;

    object = object_create("void.png");
    if (object == NULL)
        return NULL;
    object_child_malloc(object, PLAYERS_MAX);
    for (int i = 0; i < PLAYERS_MAX; i++) {
        object->child[i] = scene_game_h_hud_plcmnt_seg();
        GAME.hoppy_selected[i] = -1;
    }
    return object;
}

object_t *scene_game_h_hud_create(void)
{
    object_t *object = NULL;

    object = object_create("void.png");
    if (object == NULL)
        return NULL;
    object_child_malloc(object, 2);
    object->child[0] = object_create("void.png");
    object->child[1] = scene_game_h_hud_plcmnt();
    return object;
}
