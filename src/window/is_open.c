/*
** EPITECH PROJECT, 2021
** window/is_open.c
** File description:
** Writing sfRender... is too long obviously, dah -.-
*/

#include "htd.h"

sfBool window_is_open(void)
{
    return sfRenderWindow_isOpen(GAME.window);
}
