/*
** EPITECH PROJECT, 2021
** htd_objects.h
** File description:
** The swiss army knife of this game
*/

#pragma once
    #include "htd_filepaths.h"
    #include <SFML/Graphics.h>

enum ANCHOR {
    ANCHOR_TOP_LEFT,
    ANCHOR_TOP,
    ANCHOR_TOP_RIGHT,
    ANCHOR_LEFT,
    ANCHOR_CENTER,
    ANCHOR_RIGHT,
    ANCHOR_BOTTOM_LEFT,
    ANCHOR_BOTTOM,
    ANCHOR_BOTTOM_RIGHT,
};

//The swiss army knife of this game
//'text' is also based on what 'sprite' contains
//'anchor' can be used along with ANCHOR-type macros
//'outline' is given in (full-screen) pixels
//'hover' requires the usage of object_is_hovering()
//'child' contains every sub-objects, quite practical
typedef struct object_t object_t;

typedef struct object_t {
    sfSprite *sprite;
    sfTexture *texture;
    sfText *text;
    sfCircleShape *circle;
    int anchor;
    int centered_position;
    int centered_rotation;
    int outline;
    int hover;
    float rotation;
    sfVector2f position;
    sfVector2u size;
    sfVector2u texture_size;
    object_t **child;
} object_t;

//If (childs < 0), it will take all descendants
void object_add_position(object_t *object, float x, float y, int childs);
//Allows space for 'size' childs
object_t *object_child_malloc(object_t *, int size);
//Requires a GRAPHICS macro
object_t *object_create(const char *path);
void object_circle_create(object_t *object, float radius, sfColor color);
//Destroys an object
object_t *object_destroy(object_t *);
//Sets the value of an object to NULL after destroying it
//You can use 'object_destroy_null(&object);'
object_t *object_destroy_null(object_t **pointed_object);
//Draws on-screen an object and all its descendants
object_t *object_draw(object_t *);
void object_draw_outline(object_t *object);
//If (childs < 0), it will take all descendants
int object_is_hovering(object_t *, sfVector2f mouse, int childs);
//If (childs < 0), it will take all descendants
void object_set_anchor(object_t *object, int anchor, int childs);
//If (x < 0), the x position will remains unchanged.
//If (y < 0), the y position will also remains unchanged.
//If (childs < 0), it will take all descendants
void object_set_size(object_t *object, int x, int y, int childs);
void object_text_create(object_t *, char const *written);
