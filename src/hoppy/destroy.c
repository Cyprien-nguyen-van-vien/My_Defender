/*
** EPITECH PROJECT, 2021
** hoppy/destroy.c
** File description:
** Main function
*/

#include "htd.h"

void hoppy_destroy(int const id)
{
    GAME.hoppy[id].owner = -1;
    if (GAME.hoppy_object[id] != NULL)
        object_destroy_null(&GAME.hoppy_object[id]);
}

void hoppy_destroy_all(void)
{
    for (int i = 0; i < HOPPIES_MAX; i++)
        hoppy_destroy(i);
}
