/*
** EPITECH PROJECT, 2021
** enemy/destroy.c
** File description:
** Main function
*/

#include "htd.h"

void enemy_destroy(int const id)
{
    GAME.enemy[id].position = -1;
    if (GAME.enemy_object[id] != NULL)
        object_destroy_null(&GAME.enemy_object[id]);
}

void enemy_destroy_all(void)
{
    for (int i = 0; i < ENEMIES_MAX; i++)
        enemy_destroy(i);
}
