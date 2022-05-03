/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** Main function
*/

#include "htd.h"

md_game_t GAME;

static int check_dash_h(int ac, char **av)
{
    if (av[1][0] != '-')
        return 0;
    if (av[1][1] != 'h')
        return 0;
    if (av[1][2] != '\0')
        return 0;
    print_h();
    return 1;
}

int main(int ac, char **av, char **env)
{
    if (env == NULL || env[0] == NULL)
        return ERROR;
    if (ac == 2)
        if (check_dash_h(ac, av))
            return EXIT;
    return start(ac, av);
}
