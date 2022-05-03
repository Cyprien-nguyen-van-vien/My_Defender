/*
** EPITECH PROJECT, 2021
** scene/game/valid_placement.c
** File description:
** Hoppy Hud
*/

#include "htd.h"

static int placement_path(sfVector2f pos, sfVector2u size, int id)
{
    if (object_is_hovering(GAME.path_object->child[id], pos, 0))
        return 0;
    return 1;
}

static int placement_path_mult(sfVector2f pos, sfVector2u size, int id)
{
    int obstacles = 0;
    sfVector2f original_position = pos;

    for (int i = 0; i < 3; i++) {
        pos.x = original_position.x;
        for (int j = 0; j < 3; j++) {
            obstacles += 1 - placement_path(pos, size, id);
            pos.x += size.x / 2;
        }
        pos.y += size.y / 2;
    }
    if (obstacles != 0)
        return 0;
    return 1;
}

static int placement_colision(sfVector2f pos, sfVector2u size, int id)
{
    sfVector2f detect = {pos.x + TILE, pos.y + TILE};

    if (GAME.hoppy[id].owner >= 0) {
        object_is_hovering(GAME.hoppy_object[id], detect, -1);
        if (GAME.hoppy_object[id]->hover)
            return 0;
    }
    return 1;
}

int scene_game_valid_placement(sfVector2f pos, sfVector2u size)
{
    if (pos.x + size.x >= LEVEL_X || pos.x < 0)
        return 0;
    if (pos.y + size.y >= LEVEL_Y || pos.y < 0)
        return 0;
    for (int i = 0; i < HOPPIES_MAX; i++)
        if (!placement_colision(pos, size, i))
            return 0;
    for (int i = 0; GAME.path_object->child[i] != NULL; i++)
        if (!placement_path_mult(pos, size, i))
            return 0;
    return 1;
}
