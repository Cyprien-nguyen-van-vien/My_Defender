/*
** EPITECH PROJECT, 2021
** hoppy/upgrade.c
** File description:
** Upgrades an hoppy
*/

#include "htd.h"

int upgrade_hoppy(int const id)
{
    int level = GAME.hoppy[id].level;
    sfCircleShape *circle = GAME.hoppy_object[id]->circle;

    if (level > 1 || GAME.coins < GAME.hoppy[id].cost)
        return 0;
    GAME.hoppy_object[id]->outline += 2;
    GAME.coins -= GAME.hoppy[id].cost;
    GAME.hoppy[id].range *= 1.1;
    if (level == 0)
        GAME.hoppy[id].speed *= 2;
    if (level == 1) {
        GAME.hoppy[id].damage *= 2;
        sfText_setString(GAME.hoppy_object[id]->text, "max");
    }
    sfCircleShape_setRadius(circle, TILE * GAME.hoppy[id].range);
    GAME.hoppy[id].level += 1;
    return 1;
}
