/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-virgile.berrier
** File description:
** display.c
*/

#include "htd.h"

void scene_title_screen_display(object_t *scene)
{
    sfRenderWindow_clear(GAME.window, sfBlack);
    object_draw(scene);
    object_draw(GAME.mouse_object);
    sfRenderWindow_display(GAME.window);
}
