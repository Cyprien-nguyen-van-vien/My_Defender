/*
** EPITECH PROJECT, 2021
** scene/game/hud/hoppy.c
** File description:
** Main function
*/

#include "htd.h"

static void scene_game_hud_hoppy_config(object_t *object)
{
    object_add_position(object, 0, 210, -1);
}

static object_t *scene_game_hud_hoppy_icon(int id)
{
    object_t *object = NULL;
    int size = TILE * 2;
    sfIntRect rect = {0, size * GAME.hoppy_data[id].texture, size, size};
    char *cost = my_int_to_str(GAME.hoppy_data[id].cost);

    object = object_create("hoppies.png");
    object_set_size(object, HUD_X / 3, HUD_X / 3, 0);
    object->position.x += (HUD_X / 2 - HUD_X / 3) / 2;
    object->position.y += (HUD_X / 2 - HUD_X / 3) / 2;
    object->texture_size.x = size;
    object->texture_size.y = size;
    sfSprite_setTextureRect(object->sprite, rect);
    object_text_create(object, cost);
    free(cost);
    sfText_setColor(object->text, COLOR_GRAY_50);
    return object;
}

static object_t *scene_game_hud_hoppy_seg(int id)
{
    sfVector2f pos = {(HUD_X / 2) * (id % 2), (HUD_X / 2) * (id / 2)};
    object_t *object = NULL;

    object = object_create("buttons/hoppy_square.png");
    object_set_size(object, HUD_X / 2, HUD_X / 2, 0);
    sfSprite_setColor(object->sprite, COLOR_GRAY_50);
    object_child_malloc(object, 1);
    object->child[0] = scene_game_hud_hoppy_icon(id);
    object_add_position(object, pos.x, pos.y, -1);
    return object;
}

object_t *scene_game_hud_hoppy_create(void)
{
    int count = 0;
    sfVector2f pos = {0, 0};
    object_t *object = NULL;

    object = object_create("void.png");
    if (object == NULL)
        return NULL;
    object_child_malloc(object, HOPPY_COUNT);
    for (int i = 0; i < GAME.hoppy_data_count; i++)
        object->child[i] = scene_game_hud_hoppy_seg(i);
    scene_game_hud_hoppy_config(object);
    return object;
}
