/*
** EPITECH PROJECT, 2021
** hoppy/refresh.c
** File description:
** Updates an hoppy from his delta_stored
*/

#include "htd.h"

static void hoppy_hover(int const id, int const pl)
{
    sfColor color = sfWhite;

    color.a = 100;
    sfSprite_setColor(GAME.hoppy_object[id]->sprite, color_player_get(pl));
    sfText_setColor(GAME.hoppy_object[id]->text, sfWhite);
    sfCircleShape_setOutlineColor(GAME.hoppy_object[id]->circle, color);
    if (GAME.input[pl].select == 1)
        upgrade_hoppy(id);
    if (GAME.input[pl].back == 1) {
        GAME.coins += GAME.hoppy[id].cost * (GAME.hoppy[id].level + 1);
        hoppy_destroy(id);
    }
}

static void refresh_text(int const id)
{
    int pl = GAME.hoppy[id].owner;
    sfVector2f mouse = GAME.mouse_object->child[pl]->position;
    int selected = object_is_hovering(GAME.hoppy_object[id], mouse, -1);
    sfColor transp = sfTransparent;

    if (selected && GAME.hoppy_selected[pl] < 0) {
        hoppy_hover(id, pl);
    } else {
        sfCircleShape_setOutlineColor(GAME.hoppy_object[id]->circle, transp);
        sfSprite_setColor(GAME.hoppy_object[id]->sprite, sfWhite);
        sfText_setColor(GAME.hoppy_object[id]->text, sfTransparent);
    }
}

static void hoppy_refreh_object(int const id)
{
    sfVector2f pos = {0, 0};

    pos.x = GAME.hoppy[id].position.x * TILE;
    pos.y = GAME.hoppy[id].position.y * TILE;
    if (GAME.hoppy_object[id] == NULL)
        return;
    GAME.hoppy_object[id]->position.x = pos.x;
    GAME.hoppy_object[id]->position.y = pos.y;
}

void hoppy_refresh(int const id)
{
    int attack = 1;

    refresh_text(id);
    if (GAME.hoppy[id].owner < 0)
        return;
    GAME.hoppy[id].cooldown -= GAME.hoppy[id].delta_stored;
    GAME.hoppy[id].delta_stored = 0;
    while (GAME.hoppy[id].cooldown <= 0 && attack == 1) {
        attack = hoppy_attack(id);
        if (attack == 1)
            GAME.hoppy[id].cooldown += SEC_TO_DELTA(1) / GAME.hoppy[id].speed;
    }
    if (GAME.hoppy[id].cooldown < 0)
        GAME.hoppy[id].cooldown = 0;
    hoppy_refreh_object(id);
}

void hoppy_refresh_all(void)
{
    for (int i = 0; i < HOPPIES_MAX; i++) {
        if (GAME.hoppy[i].owner >= 0)
            hoppy_refresh(i);
    }
}
