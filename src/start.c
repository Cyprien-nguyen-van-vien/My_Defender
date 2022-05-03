/*
** EPITECH PROJECT, 2021
** start.c
** File description:
** Main function
*/

#include "htd.h"

void md_game_intialise_others(void)
{
    GAME.deltaclock = sfClock_create();
    GAME.permaclock = sfClock_create();
    for (int i = 0; i < ENEMIES_MAX; i++) {
        GAME.enemy[i].position = -1;
        GAME.enemy_object[i] = NULL;
    }
    for (int i = 0; i < HOPPIES_MAX; i++) {
        GAME.hoppy[i].owner = -1;
        GAME.hoppy_object[i] = NULL;
    }
    for (int i = 0; i < 10; i++)
        GAME.font[i] = NULL;
    GAME.font[0] = sfFont_createFromFile("fonts/Gooddog Plain.ttf");
    input_create_all(GAME.input);
    GAME.mouse_object = object_create("void.png");
    object_child_malloc(GAME.mouse_object, PLAYERS_MAX);
}

void md_game_initalise(void)
{
    md_game_intialise_others();
    GAME.bgm.music = NULL;
    GAME.coins = 0;
    md_prog2i_set(&GAME.hearts, 0, 0, 100);
    GAME.mouse.position.x = 0;
    GAME.mouse.position.y = 0;
    GAME.option.bgm = DEFAULT_BGM;
    GAME.option.fps = DEFAULT_FPS;
    GAME.option.sfx = DEFAULT_SFX;
    GAME.path = NULL;
    GAME.window_size.x = 0;
    GAME.window_size.y = 0;
    sfx_generate();
    GAME.hoppy_data_count = 0;
    hoppy_generate();
}

int md_game_errors(void)
{
    if (GAME.input == NULL)
        return 1;
    return 0;
}

void md_game_destroy(void)
{
    sfClock_destroy(GAME.deltaclock);
    sfClock_destroy(GAME.permaclock);
    for (int i = 0; GAME.font[i] != NULL; i++)
        sfFont_destroy(GAME.font[i]);
    if (GAME.mouse_object != NULL)
        object_destroy(GAME.mouse_object);
    path_destroy_all();
    sfRenderWindow_destroy(GAME.window);
    sfx_destroy();
}

int start(int ac, char **av)
{
    window_create();
    md_game_initalise();
    while (sfRenderWindow_isOpen(GAME.window)) {
        scene_title();
        if (sfRenderWindow_isOpen(GAME.window))
            scene_game_main();
    }
    bgm_play(NULL);
    md_game_destroy();
    return EXIT;
}
