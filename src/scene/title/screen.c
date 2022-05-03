/*
** EPITECH PROJECT, 2021
** scene/title/screen.c
** File description:
** Main function
*/

#include "htd.h"

static void scene_title_loop_seg(object_t *scene, int id, int i)
{
    object_t *buttons = scene->child[SCN_HUD];
    int selected = buttons->child[i]->hover && GAME.input[id].select == 1;

    if (buttons->child[i]->hover) {
        sfText_setColor(buttons->child[i]->text, COLOR_GRAY_50);
        sfText_setStyle(buttons->child[i]->text, sfTextUnderlined);
    }
    if (buttons->child[i]->hover && GAME.input[id].select >= 1)
        sfText_setColor(buttons->child[i]->text, sfWhite);
    if (selected && i == 0)
        sfRenderWindow_close(GAME.window);
    if (selected && i == 1) {
        scene_options(scene);
        GAME.scene_closing = 0;
    }
    if (selected && i == 2)
        GAME.scene_closing = 1;
}

static void scene_title_loop_mouse(object_t *scene, int id)
{
    int selected = 0;
    object_t *buttons = scene->child[SCN_HUD];

    if (GAME.input[id].control_type < 1)
        return;
    object_is_hovering(buttons, GAME.mouse_object->child[id]->position, -1);
    for (int i = 0; buttons->child[i] != NULL; i++)
        scene_title_loop_seg(scene, id, i);
}

static void scene_title_loop(object_t *scene)
{
    object_t *buttons = scene->child[SCN_HUD];

    tick();
    for (int i = 0; buttons->child[i] != NULL; i++) {
        sfText_setColor(buttons->child[i]->text, sfBlack);
        sfText_setStyle(buttons->child[i]->text, sfTextRegular);
    }
    for (int i = 0; i < PLAYERS_MAX; i++)
        scene_title_loop_mouse(scene, i);
    scene_title_screen_display(scene);
}

int scene_title_screen(object_t *title)
{
    object_t *scene = scene_create();

    GAME.scene_closing = 0;
    scene_replace(scene, SCN_BG, title);
    scene_replace(scene, SCN_HUD, scene_title_buttons());
    sfSprite_setColor(GAME.mouse_object->sprite, COLOR_P1);
    while (sfRenderWindow_isOpen(GAME.window) && !GAME.scene_closing)
        scene_title_loop(scene);
    scene->child[SCN_BG] = NULL;
    object_destroy(scene);
    return 0;
}
