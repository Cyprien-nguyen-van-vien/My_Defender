/*
** EPITECH PROJECT, 2021
** scene/game/main.c
** File description:
** Main function
*/

#include "htd.h"

static int scene_game_main_inputs(object_t *scene)
{
    for (int i = 0; i < PLAYERS_MAX; i++)
        if (GAME.input[i].exit == 1)
            scene_options(scene);
}

static int scene_game_main_loop(object_t *scene, md_wave_t *wave)
{
    tick();
    wave_generator(wave);
    scene_game_main_inputs(scene);
    for (int i = 0; i < HOPPIES_MAX; i++)
        GAME.hoppy[i].delta_stored = GAME.delta;
    hoppy_refresh_all();
    for (int i = 0; i < ENEMIES_MAX; i++)
        GAME.enemy[i].delta_stored = GAME.delta;
    enemy_refresh_all();
    hoppy_to_scene_object(scene->child[SCN_HOPPIES]);
    enemy_to_scene_object(scene->child[SCN_ENNEMIES]);
    scene_game_hud_update(scene->child[SCN_HUD]->child[0]);
    scene_game_h_hud_update(scene->child[SCN_HOPPY_HUD]);
    sfRenderWindow_clear(GAME.window, sfBlack);
    object_draw(scene);
    object_draw(GAME.mouse_object);
    if (GAME.scene_closing != 2)
        sfRenderWindow_display(GAME.window);
}

static object_t *scene_game_main_start(void)
{
    object_t *scene = scene_create();

    scene_replace(scene, SCN_BG, object_create("grass.jpg"));
    scene->child[SCN_BG]->size.x = LEVEL_X;
    scene->child[SCN_BG]->size.y = LEVEL_Y;
    scene_replace(scene, SCN_BG1, grid());
    scene_replace(scene, SCN_ENNEMIES, object_create("void.png"));
    object_child_malloc(scene->child[SCN_ENNEMIES], ENEMIES_MAX);
    scene_replace(scene, SCN_HOPPIES, object_create("void.png"));
    object_child_malloc(scene->child[SCN_HOPPIES], HOPPIES_MAX);
    scene_replace(scene, SCN_HOPPY_HUD, scene_game_h_hud_create());
    scene_replace(scene, SCN_HUD, object_create("void.png"));
    object_child_malloc(scene->child[SCN_HUD], 1);
    scene->child[SCN_HUD]->child[0] = scene_game_hud_create();
    return scene;
}

static int loop_condition(void)
{
    if (!sfRenderWindow_isOpen(GAME.window))
        return 0;
    if (GAME.scene_closing == 2)
        return 0;
    if (GAME.hearts.value <= 0)
        return 0;
    return 1;
}

int scene_game_main(void)
{
    object_t *scene = scene_game_main_start();
    md_wave_t wave = {0, 0, {-1}};

    GAME.coins = STARTING_COINS;
    GAME.score = 0;
    GAME.wave = 0;
    GAME.hearts.value = 100;
    file_to_level("levels/castle.htdl");
    GAME.path_object = scene_game_path_create();
    scene_replace(scene, SCN_PATH, GAME.path_object);
    while (loop_condition())
        scene_game_main_loop(scene, &wave);
    hoppy_destroy_all();
    enemy_destroy_all();
    scene->child[SCN_HOPPIES]->child[0] = NULL;
    scene->child[SCN_ENNEMIES]->child[0] = NULL;
    object_destroy(scene);
    return 0;
}
