/*
** EPITECH PROJECT, 2021
** scene/game/path.c
** File description:
** Main function
*/

#include "htd.h"

static object_t *create_object_segment(sfVector2f coor)
{
    object_t *object = NULL;
    sfColor color = {230, 170, 25, 255};

    object = object_create("pixel.png");
    if (object == NULL)
        return NULL;
    object->centered_position = 1;
    object->position.x = coor.x;
    object->position.y = coor.y;
    object->size.x = TILE * 1.5;
    object->size.y = TILE * 1.5;
    sfSprite_setColor(object->sprite, color);
    return object;
}

static void add_object_segment(object_t *object, sfVector2f coor)
{
    int size = 0;
    object_t **childs = object->child;

    for (size = 0; object->child[size] != NULL; size++);
    object->child = NULL;
    object_child_malloc(object, size + 1);
    for (int i = 0; i < size; i++)
        object->child[i] = childs[i];
    object->child[size] = create_object_segment(coor);
    free(childs);
}

static void generate_segments(object_t *object)
{
    int i = 0;
    sfVector2f *path_ptd = NULL;
    sfVector2f start = GAME.path[0].point;
    sfVector2f coor = {start.x * TILE, start.y * TILE};

    for (i = 0; path_ptd != NULL || i == 0; i++) {
        coor.x = start.x * TILE;
        coor.y = start.y * TILE;
        path_ptd = ept2f_seg(&coor, i, 0);
        add_object_segment(object, coor);
    }
}

object_t *scene_game_path_create(void)
{
    object_t *object = NULL;

    object = object_create(NULL);
    object->position.x = -100;
    object->position.y = -100;
    if (object == NULL)
        return NULL;
    sfSprite_setColor(object->sprite, sfTransparent);
    object_child_malloc(object, 0);
    generate_segments(object);
    return object;
}
