/*
** EPITECH PROJECT, 2021
** hoppy/attack.c
** File description:
** Main function
*/

#include "htd.h"

static int hoppy_attack_seg(int const id, int i, int target)
{
    sfVector2i poshoppyi = GAME.hoppy[id].position;
    sfVector2f poshoppy = {poshoppyi.x * TILE, poshoppyi.y * TILE};
    sfVector2f posenemy = {0, 0};

    if (GAME.enemy[i].position < 0)
        return target;
    if (target >= 0 && GAME.enemy[i].position <= GAME.enemy[target].position)
        return target;
    posenemy.x = enemy_position_to_2f(i).x;
    posenemy.y = enemy_position_to_2f(i).y;
    poshoppy.x += GAME.hoppy[id].size.x * 0.5 * TILE;
    poshoppy.y += GAME.hoppy[id].size.y * 0.5 * TILE;
    if (path_pythagore(posenemy, poshoppy) > GAME.hoppy[id].range * TILE)
        return target;
    return i;
}

static void update_animation(int const id, int const target)
{
    sfVector2f position1 = GAME.hoppy_object[id]->position;
    sfVector2f position2 = GAME.enemy_object[target]->position;
    float rotation = path_theta(position1, position2);
    sfIntRect rect = sfSprite_getTextureRect(GAME.hoppy_object[id]->sprite);

    rect.left += TILE * 2;
    if (rect.left >= TILE * 4)
        rect.left = 0;
    sfSprite_setTextureRect(GAME.hoppy_object[id]->sprite, rect);
    GAME.hoppy_object[id]->rotation = rotation * 57.2958 + 90;
    if (GAME.hoppy[id].damage > 0)
        sfx_play("Attack.ogg");
}

int hoppy_attack(int const id)
{
    int target = -1;

    for (int i = 0; i < ENEMIES_MAX; i++)
        target = hoppy_attack_seg(id, i, target);
    if (target < 0)
        return 0;
    update_animation(id, target);
    if (GAME.hoppy[id].special % 2 == 1)
        GAME.enemy[target].delta_slow += SEC_TO_DELTA(0.5);
    GAME.enemy[target].health -= GAME.hoppy[id].damage;
    if (GAME.enemy[target].health > 0)
        return 1;
    GAME.coins += GAME.enemy[target].coin;
    GAME.score += 1;
    enemy_destroy(target);
    return 1;
}
