/*
** EPITECH PROJECT, 2021
** tick.c
** File description:
** Every tick
*/

#include "htd.h"

static void resize_view(void)
{
    sfFloatRect view_rect = {0, 0, 1, 1};
    sfView *view = sfView_copy(sfRenderWindow_getView(GAME.window));
    float ratio_xy = (float)SCR_X / (float)SCR_Y;
    float ratio_yx = (float)SCR_Y / (float)SCR_X;

    ratio_xy *= GAME.window_size.y;
    ratio_yx *= GAME.window_size.x;
    if (GAME.window_size.x > ratio_xy)
        view_rect.width = ratio_xy / GAME.window_size.x;
    else
        view_rect.height = ratio_yx / GAME.window_size.y;
    view_rect.left += (1 - view_rect.width) / 2;
    view_rect.top += (1 - view_rect.height) / 2;
    sfView_setViewport(view, view_rect);
    sfRenderWindow_setView(GAME.window, view);
    sfView_destroy(view);
}

static void tick_window_size(void)
{
    sfVector2u osize = sfRenderWindow_getSize(GAME.window);
    sfVector2u nsize = {0, 0};
    sfVector2f ratio = {((float)SCR_Y / SCR_X), ((float)SCR_X / SCR_Y)};

    nsize.x = MAX(MIN(osize.x, 800), SCR_X);
    nsize.y = MAX(MIN(osize.y, 600), SCR_Y);
    sfRenderWindow_setSize(GAME.window, nsize);
    GAME.window_size.x = nsize.x;
    GAME.window_size.y = nsize.y;
    resize_view();
}

static int add_player_input(int control_type, int id)
{
    if (GAME.input[id].control_type == 0) {
        GAME.input[id].control_type = control_type;
        GAME.input[id].select = 100;
        GAME.input[id].exit = 100;
        if (control_type == 1)
            sfRenderWindow_setMouseCursorVisible(GAME.window, sfFalse);
        return 1;
    }
    return 0;
}

static int tick_check_new_player(int control_type)
{
    int keys[INPUTS_SIZE + 1] = {INPUTS_SIZE, 0, 0, 0, 0, 0, 0, 0, 0};

    keys[INPUTS_MOUSE] = sfMouse_isButtonPressed(sfMouseLeft);
    keys[INPUTS_KEYBOARD] = sfKeyboard_isKeyPressed(sfKeySpace);
    keys[INPUTS_NUMPAD] = sfKeyboard_isKeyPressed(sfKeyAdd);
    for (int i = 0; i < INPUTS_CONTROLLER4 - INPUTS_CONTROLLER0; i++)
        keys[INPUTS_CONTROLLER0 + i] = sfJoystick_isButtonPressed(i, JB_HOME);
    for (int i = 0; i < PLAYERS_MAX; i++) {
        if (GAME.input[i].control_type == control_type)
            return -1;
    }
    if (!keys[(control_type - 1) % keys[0] + 1])
        return -1;
    for (int i = 0; i < PLAYERS_MAX; i++) {
        if (add_player_input(control_type, i))
            return i;
    }
    return -1;
}

void tick(void)
{
    sfEvent event;
    sfTime delatime = sfClock_restart(GAME.deltaclock);

    GAME.delta = sfTime_asMicroseconds(delatime);
    GAME.mouse.position = sfMouse_getPositionRenderWindow(GAME.window);
    for (int i = 0; i < INPUTS_SIZE; i++)
        tick_check_new_player(i + 1);
    for (int i = 0; i < PLAYERS_MAX; i++)
        input_manage(i);
    while (sfRenderWindow_pollEvent(GAME.window, &event)) {
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ))
            sfRenderWindow_close(GAME.window);
        tick_window_size();
    }
}
