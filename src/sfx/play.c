/*
** EPITECH PROJECT, 2021
** sfx/play.c
** File description:
** Play Nevergonagiveuop.ogg
*/

#include "htd.h"

static int check_channel(int id, float *time)
{
    float channel_time = 0;
    sfTime channel_sftime = sfTime_Zero;

    if (GAME.sfx[id].clock == NULL) {
        *time = -1;
        return 1;
    }
    channel_sftime = sfClock_getElapsedTime(GAME.sfx[id].clock);
    channel_time = sfTime_asMilliseconds(channel_sftime);
    if (channel_time < *time || *time < 0)
        return 0;
    *time = channel_time;
    return 1;
}

static void play_in_channel(char const *path, int id)
{
    sfx_destroy_channel(id);
    GAME.sfx[id].clock = sfClock_create();
    GAME.sfx[id].buffer = sfSoundBuffer_createFromFile(path);
    GAME.sfx[id].sound = sfSound_create();
    sfSound_setVolume(GAME.sfx[id].sound, GAME.option.sfx);
    sfSound_setBuffer(GAME.sfx[id].sound, GAME.sfx[id].buffer);
    sfSound_play(GAME.sfx[id].sound);
}

static void search_channel(char const *path)
{
    int channel = 0;
    float time = 0;

    for (int i = 0; i < SFX_CHANNELS; i++) {
        if (check_channel(i, &time))
            channel = i;
    }
    play_in_channel(path, channel);
}

void sfx_play(char const *path)
{
    char *filename = NULL;

    filename = CAT(SFX, path);
    if (filename == NULL)
        return;
    if (file_exists(filename))
        search_channel(filename);
    free(filename);
}
