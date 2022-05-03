/*
** EPITECH PROJECT, 2021
** scene/game/hud/hoppy_update.c
** File description:
** Main function
*/

#include "htd.h"

static int scene_game_hud_hoppy_hover(object_t *object, int player, int id)
{
    sfColor color = color_player_get(player);

    if (!object->hover)
        return 0;
    color.a = 200;
    sfSprite_setColor(object->sprite, color);
    sfText_setColor(object->child[0]->text, sfWhite);
    if (GAME.input[player].select == 1)
        GAME.hoppy_selected[player] = id;
    return 1;
}

static void scene_game_hud_hoppy_player(object_t *object, int player)
{
    object_is_hovering(object, GAME.mouse_object->child[player]->position, -1);
    for (int j = 0; object->child[j] != NULL; j++)
        if (scene_game_hud_hoppy_hover(object->child[j], player, j))
            return;
}

void scene_game_hud_hoppy_update(object_t *object)
{
    int i = 0;

    for (i = 0; object->child[i] != NULL; i++) {
        sfSprite_setColor(object->child[i]->sprite, sfBlack);
        sfText_setColor(object->child[i]->child[0]->text, COLOR_GRAY_50);
    }
    for (i = 0; i < PLAYERS_MAX && GAME.mouse_object->child[i] != NULL; i++) {
        scene_game_hud_hoppy_player(object, i);
    }
    return;
}
