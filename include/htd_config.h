/*
** EPITECH PROJECT, 2021
** htd_config.h
** File description:
** Configuration
*/

#pragma once
    #define DEFAULT_FPS (int)60
    #define DEFAULT_BGM (float)50
    #define DEFAULT_SFX (float)50
    #define STARTING_COINS (int)400
    #define ARROWS_SENSIBILITY (int)60
    #define GAME_NAME "Hoppy Tower Defense"

    #include <SFML/Graphics.h>

static const int FPS_VALUES[5] = {24, 60, 90, 120, 9001};
static const float BGM_VALUES[5] = {0, 25, 50, 75, 100};
static const float SFX_VALUES[5] = {0, 25, 50, 75, 100};
static const sfColor COLOR_P1 = {0, 128, 255, 255};
static const sfColor COLOR_P2 = {255, 64, 64, 255};
static const sfColor COLOR_P3 = {0, 255, 0, 255};
static const sfColor COLOR_P4 = {255, 255, 0, 255};
static const sfColor COLOR_P5 = {255, 168, 0, 255};
static const sfColor COLOR_P6 = {255, 255, 0, 255};
static const sfColor COLOR_P7 = {255, 0, 255, 255};
static const sfColor COLOR_P8 = {128, 128, 128, 255};
static const sfColor COLOR_PLACEMENT_VALID = {0, 255, 0, 200};
static const sfColor COLOR_PLACEMENT_INVALID = {255, 0, 0, 200};
static const sfColor COLOR_GRASS = {50, 150, 30, 255};
