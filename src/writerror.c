/*
** EPITECH PROJECT, 2021
** writerror.c
** File description:
** Write something, then return ERROR
*/

#include "htd.h"

int writerror(char const *string)
{
    write(2, string, LEN(string));
    return ERROR;
}
