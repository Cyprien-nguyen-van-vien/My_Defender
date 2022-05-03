/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-mydefender-virgile.berrier
** File description:
** my_putstr.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (0);
}
