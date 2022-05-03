/*
** EPITECH PROJECT, 2021
** window/create.c
** File description:
** Main function
*/

#include "htd.h"

void window_create_icon(void)
{
    unsigned int x = 0;
    unsigned int y = 0;
    sfImage *icon = sfImage_createFromFile("icon.png");

    if (icon == NULL)
        return;
    x = sfImage_getSize(icon).x;
    y = sfImage_getSize(icon).y;
    sfRenderWindow_setIcon(GAME.window, x, y, sfImage_getPixelsPtr(icon));
    sfImage_destroy(icon);
}

void window_create(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {DEFAULT_SCR_X, DEFAULT_SCR_Y, 32};

    window = sfRenderWindow_create(video_mode, GAME_NAME, WIN_PARAMS, NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_setFramerateLimit(window, DEFAULT_FPS);
    GAME.window = window;
    GAME.window_size.x = DEFAULT_SCR_X;
    GAME.window_size.y = DEFAULT_SCR_Y;
    if (file_exists("icon.png"))
        window_create_icon();
}
