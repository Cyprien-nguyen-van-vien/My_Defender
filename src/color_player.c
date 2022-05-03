/*
** EPITECH PROJECT, 2021
** color_player.c
** File description:
** Gets a color
*/

#include "htd.h"

sfColor color_player_get(int id)
{
    sfColor color0[4] = {COLOR_P1, COLOR_P2, COLOR_P3, COLOR_P4};
    sfColor color1[4] = {COLOR_P5, COLOR_P6, COLOR_P7, COLOR_P8};
    sfColor *color[2] = {color0, color1};

    return color[(id / 4) % 2][id % 4];
}
