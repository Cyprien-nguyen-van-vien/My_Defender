/*
** EPITECH PROJECT, 2021
** scene/game/hud/health.c
** File description:
** Main function
*/

#include "htd.h"

int regen(void)
{
    int hearts = GAME.hearts.value;

    if (hearts >= GAME.hearts.max)
        return hearts;
    if (hearts % 20 != 0)
        GAME.hearts.value += 1;
    return hearts + 1;
}

void scene_game_hud_health_update(object_t *object)
{
    int hearts = GAME.hearts.value;
    char text[4] = "100";

    text[0] = (hearts / 100) % 10 + '0';
    if (hearts < 100)
        text[0] = ' ';
    text[1] = (hearts / 10) % 10 + '0';
    if (hearts < 10)
        text[1] = ' ';
    text[2] = (hearts / 1) % 10 + '0';
    if (hearts < 1)
        text[2] = '0';
    sfText_setString(object->child[2]->text, text);
    object->child[1]->size.x = MIN(hearts, 0) * (HUD_X / GAME.hearts.max);
}

void scene_game_hud_health_config(object_t *object)
{
    sfColor color = sfRed;

    color.a = 150;
    sfSprite_setColor(object->sprite, COLOR_GRAY_50);
    sfSprite_setColor(object->child[1]->sprite, color);
    object_text_create(object->child[2], "100");
    object_set_size(object, HUD_X, 100, -1);
    object_add_position(object, 0, 0, -1);
}

object_t *scene_game_hud_health_create(void)
{
    object_t *object = NULL;

    object = object_create("health_back.png");
    if (object == NULL)
        return NULL;
    object_child_malloc(object, 3);
    object->child[0] = object_create("health_back.png");
    object->child[1] = object_create("pixel.png");
    object->child[2] = object_create("health_front.png");
    scene_game_hud_health_config(object);
    return object;
}
