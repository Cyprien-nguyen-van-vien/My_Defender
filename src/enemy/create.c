/*
** EPITECH PROJECT, 2021
** enemy/create.c
** File description:
** Main function
*/

#include "htd.h"

static int enemy_create_search_space(void)
{
    for (int i = 0; i < ENEMIES_MAX; i++)
        if (GAME.enemy[i].position < 0)
            return i;
    return -1;
}

static void enemy_create_struct(int const id, int const type)
{
    GAME.enemy[id].position = 0;
    GAME.enemy[id].speed = MAX(5 + 3 * type, 40);
    GAME.enemy[id].delta_stored = 0;
    GAME.enemy[id].delta_slow = 0;
    GAME.enemy[id].health = type;
    GAME.enemy[id].camo = 0;
    GAME.enemy[id].lead = 0;
    GAME.enemy[id].regrow = 0;
    GAME.enemy[id].coin = 5 + (type / 8);
}

static object_t *enemy_create_object(int const type)
{
    object_t *object = NULL;
    sfColor colors[] = {sfBlue, sfRed, sfGreen, sfYellow, sfMagenta};
    sfColor color = colors[ABS(type - 1) % 5];
    sfIntRect rect = {TILE * ((type - 1) % 3) * 2, 0, TILE * 2, TILE * 2};

    object = object_create("enemies.png");
    if (object == NULL)
        return NULL;
    object->centered_position = 1;
    object->size.x = TILE * 2;
    object->size.y = TILE * 2;
    object->texture_size.x = rect.width;
    object->texture_size.y = rect.height;
    sfSprite_setColor(object->sprite, color);
    sfSprite_setTextureRect(object->sprite, rect);
    return object;
}

int enemy_create(int type)
{
    int id = enemy_create_search_space();

    if (id < 0)
        return -1;
    enemy_create_struct(id, type);
    GAME.enemy_object[id] = enemy_create_object(type);
    return id;
}
