/*
** EPITECH PROJECT, 2021
** hoppy/cursor.c
** File description:
** Main function
*/

#include "htd.h"

sfVector2i hoppy_cursor(int plyr)
{
    sfVector2i pos = {0, 0};
    sfVector2f cursor = GAME.mouse_object->child[plyr]->position;

    pos.x = (((int)cursor.x) / TILE) * TILE;
    pos.y = (((int)cursor.y) / TILE) * TILE;
    if (((int)cursor.x) % TILE < TILE / 2)
        pos.x -= TILE;
    if (((int)cursor.y) % TILE < TILE / 2)
        pos.y -= TILE;
    return pos;
}
