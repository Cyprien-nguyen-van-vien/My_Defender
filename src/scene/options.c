/*
** EPITECH PROJECT, 2021
** scene/options.c
** File description:
** Main function
*/

#include "htd.h"

void scene_options_display(object_t **objects, sfRectangleShape *blur)
{
    object_t *title = objects[0];
    object_t *scene = objects[1];

    sfRenderWindow_clear(GAME.window, sfBlack);
    object_draw(title);
    sfRenderWindow_drawRectangleShape(GAME.window, blur, NULL);
    object_draw(scene);
    object_draw(GAME.mouse_object);
    sfRenderWindow_display(GAME.window);
}

int scene_options_loop_mouse(object_t *scene, int id)
{
    int selected = 0;
    object_t *buttons = scene->child[SCN_HUD];

    if (GAME.input[id].control_type < 1)
        return -1;
    object_is_hovering(buttons, GAME.mouse_object->child[id]->position, -1);
    for (int i = 0; buttons->child[i] != NULL; i++) {
        selected = buttons->child[i]->hover && GAME.input[id].select == 1;
        if (buttons->child[i]->hover) {
            sfText_setColor(buttons->child[i]->text, COLOR_GRAY_50);
            sfText_setStyle(buttons->child[i]->text, sfTextUnderlined);
        }
        if (buttons->child[i]->hover && GAME.input[id].select >= 1)
            sfText_setColor(buttons->child[i]->text, sfWhite);
        if (selected)
            return i;
    }
    return -1;
}

void scene_options_loop(object_t *tit, object_t *scene, sfRectangleShape *blur)
{
    object_t *buttons = scene->child[SCN_HUD];
    object_t *objects[2] = {tit, scene};

    tick();
    for (int i = 0; buttons->child[i] != NULL; i++) {
        sfText_setColor(buttons->child[i]->text, sfBlack);
        sfText_setStyle(buttons->child[i]->text, sfTextRegular);
    }
    for (int i = 0; i < PLAYERS_MAX; i++) {
        scene_options_buttons_evt(buttons, scene_options_loop_mouse(scene, i));
        if (GAME.input[i].exit == 1)
            GAME.scene_closing = 1;
    }
    scene_options_display(objects, blur);
}

int scene_options(object_t *title)
{
    object_t *scene = scene_create();
    sfRectangleShape *blur = sfRectangleShape_create();
    sfColor blur_color = {0, 0, 0, 150};
    sfVector2f blur_size = {SCR_X, SCR_Y};

    GAME.scene_closing = 0;
    sfRectangleShape_setFillColor(blur, blur_color);
    sfRectangleShape_setSize(blur, blur_size);
    scene_replace(scene, SCN_HUD, scene_options_buttons());
    while (sfRenderWindow_isOpen(GAME.window) && !GAME.scene_closing)
        scene_options_loop(title, scene, blur);
    sfRectangleShape_destroy(blur);
    scene->child[SCN_BG] = NULL;
    object_destroy(scene);
    return 0;
}
