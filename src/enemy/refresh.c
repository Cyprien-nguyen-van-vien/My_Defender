/*
** EPITECH PROJECT, 2021
** enemy/refresh.c
** File description:
** Updates an enemy from his delta_stored
*/

#include "htd.h"

static void frame_management(int const id, float time)
{
    sfIntRect rect = sfSprite_getTextureRect(GAME.enemy_object[id]->sprite);
    int frame = time;

    frame %= 3;
    rect.top = TILE * 2 * frame;
    sfSprite_setTextureRect(GAME.enemy_object[id]->sprite, rect);
}

static void enemy_size(int const id)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(GAME.permaclock));
    float time_seg = (float)time - (int)time;

    time_seg /= 2;
    GAME.enemy_object[id]->size.x = TILE * 3 - TILE * time_seg;
    GAME.enemy_object[id]->size.y = TILE * 3 - TILE * time_seg;
    frame_management(id, time);
}

void enemy_refreh_object(int const id)
{
    sfVector2f pos = enemy_position_to_2f(id);

    if (GAME.enemy_object[id] == NULL)
        return;
    GAME.enemy_object[id]->position.x = pos.x;
    GAME.enemy_object[id]->position.y = pos.y;
}

void enemy_refresh(int const id)
{
    float movement = 0;

    if (GAME.enemy[id].position < 0)
        return;
    movement = GAME.enemy[id].speed;
    movement *= ((float)GAME.enemy[id].delta_stored / SEC_TO_DELTA(1));
    if (GAME.enemy[id].delta_slow > 0)
        movement *= 0.2;
    GAME.enemy[id].delta_slow -= GAME.enemy[id].delta_stored;
    if (GAME.enemy[id].delta_slow < 0)
        GAME.enemy[id].delta_slow = 0;
    GAME.enemy[id].position += movement;
    enemy_size(id);
    GAME.enemy[id].delta_stored = 0;
    enemy_refreh_object(id);
}

void enemy_refresh_all(void)
{
    for (int i = 0; i < ENEMIES_MAX; i++)
        enemy_refresh(i);
}
