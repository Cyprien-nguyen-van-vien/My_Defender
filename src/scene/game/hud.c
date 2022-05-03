/*
** EPITECH PROJECT, 2021
** scene/game/hud.c
** File description:
** Main function
*/

#include "htd.h"

void scene_game_hud_update(object_t *object)
{
    scene_game_hud_health_update(object->child[0]);
    scene_game_hud_coins_update(object->child[1]);
    scene_game_hud_hoppy_update(object->child[2]);
    scene_game_hud_wave_update(object->child[3]);
    scene_game_hud_score_update(object->child[4]);
}

void scene_game_hud_config(object_t *object)
{
    object_child_malloc(object, 5);
    object->child[0] = scene_game_hud_health_create();
    object->child[1] = scene_game_hud_coins_create();
    object_add_position(object->child[1], 0, 100, -1);
    object->child[2] = scene_game_hud_hoppy_create();
    object->child[3] = scene_game_hud_wave_create();
    object_add_position(object->child[3], 0, HUD_Y - 250, -1);
    object->child[4] = scene_game_hud_score_create();
    object_add_position(object->child[4], 0, HUD_Y - 150, -1);
}

object_t *scene_game_hud_create(void)
{
    object_t *object = NULL;

    object = object_create("health_back.png");
    if (object == NULL)
        return NULL;
    object_set_size(object, HUD_X, HUD_Y, -1);
    sfSprite_setColor(object->sprite, COLOR_GRAY_50);
    object->outline = 5;
    scene_game_hud_config(object);
    object_add_position(object, SCR_X - HUD_X, 0, -1);
    return object;
}
