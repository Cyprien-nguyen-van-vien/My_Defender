/*
** EPITECH PROJECT, 2021
** sfx/generate.c
** File description:
** Play Nevergonagiveuop.ogg
*/

#include "htd.h"

static void generate_channel(int id)
{
    GAME.sfx[id].buffer = NULL;
    GAME.sfx[id].sound = NULL;
    GAME.sfx[id].clock = NULL;
}

void sfx_generate(void)
{
    for (int i = 0; i < SFX_CHANNELS; i++)
        generate_channel(i);
}
