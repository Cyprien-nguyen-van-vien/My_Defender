/*
** EPITECH PROJECT, 2021
** bgm/play.c
** File description:
** Play Rikudorolu.ogg
*/

#include "htd.h"

void bgm_volume(float volume)
{
    GAME.option.bgm = volume;
    if (GAME.bgm.music == NULL)
        return;
    sfMusic_setVolume(GAME.bgm.music, volume);
}

void bgm_play(char const *path)
{
    char *filename = NULL;

    if (GAME.bgm.music != NULL) {
        sfMusic_stop(GAME.bgm.music);
        sfMusic_destroy(GAME.bgm.music);
        GAME.bgm.music = NULL;
    }
    if (path == NULL)
        return;
    filename = CAT(BGM, path);
    if (file_exists(filename)) {
        GAME.bgm.music = sfMusic_createFromFile(filename);
        sfMusic_setVolume(GAME.bgm.music, GAME.option.bgm);
        sfMusic_setLoop(GAME.bgm.music, sfTrue);
        sfMusic_play(GAME.bgm.music);
    }
    free(filename);
}
