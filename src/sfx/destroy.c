/*
** EPITECH PROJECT, 2021
** sfx/destroy.c
** File description:
** Play Nevergonagiveuop.ogg
*/

#include "htd.h"

void sfx_destroy_channel(int id)
{
    if (GAME.sfx[id].buffer != NULL)
        sfSoundBuffer_destroy(GAME.sfx[id].buffer);
    if (GAME.sfx[id].sound != NULL) {
        sfSound_stop(GAME.sfx[id].sound);
        sfSound_destroy(GAME.sfx[id].sound);
    }
    if (GAME.sfx[id].clock != NULL)
        sfClock_destroy(GAME.sfx[id].clock);
    GAME.sfx[id].buffer = NULL;
    GAME.sfx[id].sound = NULL;
    GAME.sfx[id].clock = NULL;
}

void sfx_destroy(void)
{
    for (int i = 0; i < SFX_CHANNELS; i++)
        sfx_destroy_channel(i);
}
