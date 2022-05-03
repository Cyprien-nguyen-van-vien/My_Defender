/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-virgile.berrier
** File description:
** option_h.c
*/

#include "htd.h"

static void controls_keyboard(void)
{
    my_putstr("\tKEYBOARD - ARROWS\n");
    my_putstr("\t\tSpace: Select\n");
    my_putstr("\t\tX: Unselect / Sell\n");
    my_putstr("\t\tShift: Change cursor speed\n");
    my_putstr("\tKEYBOARD - NUMPAD\n");
    my_putstr("\t\t+: Select\n");
    my_putstr("\t\t-: Unselect / Sell\n");
    my_putstr("\t\t3 / 9: Change cursor speed\n");
}

static void controls(void)
{
    my_putstr("\tMOUSE\n");
    my_putstr("\t\tLeft Click: Select\n");
    my_putstr("\t\tRight Click: Unselect / Sell\n");
    controls_keyboard();
    my_putstr("\tCONTROLLER\n");
    my_putstr("\t\tA / Circle: Select\n");
    my_putstr("\t\tB / Cross: Unselect / Sell\n");
    my_putstr("\t\t+ / Start: Options\n");
}

static void lore(void)
{
    my_putstr("LORE\n");
    my_putstr("\tThere's a castle,\n");
    my_putstr("\tThere's Hoppy in it,\n");
    my_putstr("\tAPEs want to come in,\n");
    my_putstr("\tHoppy wants to be alone.\n");
}

int print_h(void)
{
    my_putstr("DESCRIPTION\n");
    my_putstr("\tBTD2 but it's Hoppy and the Hoppies\n");
    my_putstr("USAGE\n");
    my_putstr("\t./my_defender\n");
    my_putstr("CONTROLS\n");
    my_putstr("\tEscape: Options\n");
    controls();
    lore();
    my_putstr("CREDITS\n");
    my_putstr("\tCypriend and Virgile - The actual game\n");
    my_putstr("\tWaterflame - Music (we didn't ask for permission lol)\n");
    my_putstr("\tHoppy - Well, that's obvious why\n");
    my_putstr("\tI-don't-remember-who - We stole the cursor\n");
    return 0;
}
