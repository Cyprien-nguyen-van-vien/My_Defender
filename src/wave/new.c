/*
** EPITECH PROJECT, 2021
** wave/new.c
** File description:
** weeeeeeeve but new
*/

#include "htd.h"

static void spawn(md_wave_t *wave, int type, int size)
{
    int i = 0;

    if (size <= 0 || type <= 0)
        return;
    for (i = 0; wave->enemy_list[i] > 0; i++);
    for (int j = 0; j < size; j++) {
        if (j >= ENEMY_LIST_MAX - 2)
            return;
        wave->enemy_list[i] = type;
        wave->enemy_list[i + 1] = -1;
        i++;
    }
}

static int count(md_wave_t *wave, int start, int end, int count)
{
    if (wave->wave < start)
        return 0;
    if (wave-wave > end && end >= 0)
        return 0;
    return count;
}

static void waves(md_wave_t *wave, int upgrade, int stronger, int indexsub)
{
    if (wave->wave % (upgrade * 2) == 0 && wave->wave > 2)
        spawn(wave, stronger - 2, 8);
    if (wave->wave % (upgrade * 2) == upgrade && wave->wave > 2)
        spawn(wave, stronger + 3, 1);
    spawn(wave, stronger, 3);
    if (indexsub >= 4) {
        for (int i = 0; i < 5; i++) {
            spawn(wave, stronger - 1, 1);
            spawn(wave, stronger, 1);
        }
    }
    if (indexsub >= 2)
        spawn(wave, stronger - 1, 5);
    if (indexsub >= 3)
        spawn(wave, stronger - 2, 5);
}

int wave_new(md_wave_t *wave)
{
    int upgrade = 4;
    int stronger = 1 + (wave->wave / upgrade);
    int indexsub = wave->wave % upgrade + 1;

    regen();
    waves(wave, upgrade, stronger, indexsub);
    wave->wave += 1;
    GAME.wave = wave->wave;
    return 0;
}
