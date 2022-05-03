/*
** EPITECH PROJECT, 2021
** md_prog.c
** File description:
** Main function
*/

#include "htd.h"

int md_prog2i_set(md_prog2i_t *prog2i, int value, int min, int max)
{
    prog2i->value = value;
    prog2i->min = min;
    prog2i->max = max;
    return value;
}
