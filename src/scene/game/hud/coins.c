/*
** EPITECH PROJECT, 2021
** scene/game/hud/coins.c
** File description:
** Main function
*/

#include "htd.h"

void scene_game_hud_coins_update(object_t *object)
{
    int coins = GAME.coins;
    char *text = NULL;

    text = my_int_to_str(coins);
    if (text != NULL) {
        sfText_setString(object->child[2]->text, text);
        free(text);
    }
}

static void scene_game_hud_coins_config(object_t *object)
{
    sfColor color = sfYellow;

    color.a = 150;
    sfSprite_setColor(object->sprite, COLOR_GRAY_50);
    sfSprite_setColor(object->child[1]->sprite, color);
    object_text_create(object->child[2], "100");
    object_set_size(object, HUD_X, 100, -1);
    object_add_position(object, 0, 0, -1);
}

object_t *scene_game_hud_coins_create(void)
{
    object_t *object = NULL;

    object = object_create("health_back.png");
    if (object == NULL)
        return NULL;
    object_child_malloc(object, 3);
    object->child[0] = object_create("health_back.png");
    object->child[1] = object_create("pixel.png");
    object->child[2] = object_create("health_front.png");
    scene_game_hud_coins_config(object);
    return object;
}
