/*
** EPITECH PROJECT, 2021
** wave/generator.c
** File description:
** weeeeeeeve
*/

#include "htd.h"

static int enemy_count(void)
{
    int count = 0;

    for (int i = 0; i < ENEMIES_MAX; i++) {
        if (GAME.enemy[i].position >= 0) {
            count += 1;
        }
    }
    return count;
}

static int get_delay(int type)
{
    int speed = MAX(5 * (type + 1), 40);
    int delay = SEC_TO_DELTA(0.2);

    delay /= (float)((float)speed / 7);
    return delay;
}

static int wave_spawn(md_wave_t *wave)
{
    int i = 0;

    for (i = 0; wave->enemy_list[i] >= 0; i++);
    while (wave->enemy_delta <= 0) {
        if (i == 0) {
            if (enemy_count() <= 0)
                wave_new(wave);
            return 0;
        }
        i--;
        if (enemy_create(wave->enemy_list[i]) < 0)
            return 0;
        wave->enemy_delta += get_delay(wave->enemy_list[i]);
        wave->enemy_list[i] = -1;
    }
    wave->enemy_delta -= GAME.delta;
    return 1;
}

int wave_generator(md_wave_t *wave)
{
    wave_spawn(wave);
}
