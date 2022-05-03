/*
** EPITECH PROJECT, 2021
** window/close.c
** File description:
** Close window, then go on Fedora
*/

#include "htd.h"

int window_crash(char const *message)
{
    window_close();
    write(2, message, LEN(message));
    return ERROR;
}

char *window_crash_null(char const *message)
{
    window_crash(message);
    return NULL;
}

int window_close(void)
{
    if (!sfRenderWindow_isOpen(GAME.window))
        return 0;
    sfRenderWindow_close(GAME.window);
    return 1;
}
