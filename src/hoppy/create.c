/*
** EPITECH PROJECT, 2021
** hoppy/create.c
** File description:
** Main function
*/

#include "htd.h"

static int hoppy_create_search_space(void)
{
    for (int i = 0; i < HOPPIES_MAX; i++)
        if (GAME.hoppy[i].owner < 0)
            return i;
    return -1;
}

static void hoppy_copy_struct(int const id, int const type)
{
    GAME.hoppy[id].texture = GAME.hoppy_data[type].texture;
    GAME.hoppy[id].damage = GAME.hoppy_data[type].damage;
    GAME.hoppy[id].speed = GAME.hoppy_data[type].speed;
    GAME.hoppy[id].range = GAME.hoppy_data[type].range;
    GAME.hoppy[id].cost = GAME.hoppy_data[type].cost;
    GAME.hoppy[id].special = GAME.hoppy_data[type].special;
}

static void hoppy_create_struct(int const id)
{
    GAME.hoppy[id].cooldown = 0;
    GAME.hoppy[id].damage = 0;
    GAME.hoppy[id].delta_stored = 0;
    GAME.hoppy[id].range = 0;
    GAME.hoppy[id].size.x = 2;
    GAME.hoppy[id].size.y = 2;
    GAME.hoppy[id].speed = 0;
    GAME.hoppy[id].owner = 0;
    GAME.hoppy[id].position.x = 0;
    GAME.hoppy[id].position.y = 0;
    GAME.hoppy[id].texture = 0;
    GAME.hoppy[id].cost = 0;
    GAME.hoppy[id].level = 0;
    GAME.hoppy[id].special = 0;
}

static object_t *hoppy_create_object(int const id)
{
    object_t *object = NULL;
    sfIntRect rect = {0, 0, TILE * 2, TILE * 2};

    rect.top = TILE * 2 * GAME.hoppy[id].texture;
    object = object_create("hoppies.png");
    if (object == NULL)
        return NULL;
    object->centered_rotation = 1;
    object->texture_size.x = TILE * 2;
    object->texture_size.y = TILE * 2;
    object_circle_create(object, TILE * GAME.hoppy[id].range, sfTransparent);
    object_set_size(object, TILE * 2, TILE * 2, 0);
    sfSprite_setTextureRect(object->sprite, rect);
    return object;
}

int hoppy_create(int const plyr)
{
    int id = hoppy_create_search_space();
    char *cost = NULL;

    if (id < 0 || GAME.hoppy_data[GAME.hoppy_selected[plyr]].cost > GAME.coins)
        return -1;
    hoppy_create_struct(id);
    hoppy_copy_struct(id, GAME.hoppy_selected[plyr]);
    GAME.hoppy[id].owner = plyr;
    GAME.hoppy[id].position.x = hoppy_cursor(plyr).x / TILE;
    GAME.hoppy[id].position.y = hoppy_cursor(plyr).y / TILE;
    GAME.hoppy_object[id] = hoppy_create_object(id);
    GAME.coins -= GAME.hoppy[id].cost;
    cost = my_int_to_str(GAME.hoppy[id].cost);
    object_text_create(GAME.hoppy_object[id], cost);
    sfText_setColor(GAME.hoppy_object[id]->text, sfTransparent);
    free(cost);
    sfx_play("Meow1.ogg");
    return id;
}
