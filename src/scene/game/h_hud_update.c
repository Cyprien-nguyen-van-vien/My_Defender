/*
** EPITECH PROJECT, 2021
** scene/game/h_hud_update.c
** File description:
** Hoppy Hud
*/

#include "htd.h"

static int scene_game_h_hud_update_invalid(object_t *object)
{
    sfSprite_setColor(object->sprite, COLOR_PLACEMENT_INVALID);
    sfCircleShape_setOutlineColor(object->circle, COLOR_PLACEMENT_INVALID);
    sfText_setColor(object->text, COLOR_PLACEMENT_INVALID);
    return 0;
}

static int scene_game_h_hud_update_plcmd(object_t *object, int plyr)
{
    sfVector2f cursor = GAME.mouse_object->child[plyr]->position;
    sfVector2i pos = hoppy_cursor(plyr);

    object->position.x = pos.x;
    object->position.y = pos.y;
    if (!scene_game_valid_placement(object->position, object->size))
        return scene_game_h_hud_update_invalid(object);
    if (GAME.input[plyr].select == 1) {
        hoppy_create(plyr);
        return 1;
    }
    sfSprite_setColor(object->sprite, COLOR_PLACEMENT_VALID);
    sfCircleShape_setOutlineColor(object->circle, COLOR_PLACEMENT_VALID);
    sfText_setColor(object->text, COLOR_PLACEMENT_VALID);
    return 0;
}

static void selct_hoppy(object_t *object, int plyr)
{
    float range = GAME.hoppy_data[GAME.hoppy_selected[plyr]].range * TILE;
    char *str1 = NULL;
    char *str2 = NULL;
    char *str3 = NULL;

    str1 = my_int_to_str(GAME.hoppy_data[GAME.hoppy_selected[plyr]].damage);
    str2 = my_strcat("\n", str1);
    free(str1);
    str1 = my_strcat(str2, " x ");
    free(str2);
    str3 = my_int_to_str(GAME.hoppy_data[GAME.hoppy_selected[plyr]].speed);
    str2 = my_strcat(str1, str3);
    free(str3);
    free(str1);
    str1 = my_strcat(str2, "/s");
    sfCircleShape_setRadius(object->circle, range);
    sfText_setString(object->text, str1);
    free(str1);
    free(str2);
}

static void scene_game_h_hud_update_selct(object_t *object, int plyr)
{
    int invisible = (sfSprite_getColor(object->sprite).a <= 0);
    int slct = GAME.hoppy_selected[plyr];
    int cond = invisible && slct < 0;

    if (GAME.input[plyr].back == 1)
        GAME.hoppy_selected[plyr] = -1;
    invisible = (slct < 0);
    if (!invisible && object != NULL)
        if (scene_game_h_hud_update_plcmd(object, plyr))
            invisible = 1;
    if (invisible) {
        sfSprite_setColor(object->sprite, sfTransparent);
        sfText_setColor(object->text, sfTransparent);
        sfCircleShape_setOutlineColor(object->circle, sfTransparent);
    }
    selct_hoppy(object, plyr);
}

void scene_game_h_hud_update(object_t *object)
{
    for (int i = 0; i < PLAYERS_MAX; i++)
        if (GAME.mouse_object->child[i] != NULL)
            scene_game_h_hud_update_selct(object->child[1]->child[i], i);
}
