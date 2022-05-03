/*
** EPITECH PROJECT, 2021
** my_strfcts.c
** File description:
** Main function
*/

#include "htd.h"

int my_strlen(char const *string)
{
    int length = 0;

    while (string[length] != '\0')
        length++;
    return length;
}

void *my_strcat_fill(char const *str1, char const *str2, char *str3)
{
    int i = 0;

    for (int j = 0; str1[j] != '\0'; j++) {
        str3[i] = str1[j];
        i++;
    }
    for (int j = 0; str2[j] != '\0'; j++) {
        str3[i] = str2[j];
        i++;
    }
    str3[i] = '\0';
}

char *my_strcat(char const *str1, char const *str2)
{
    int length = my_strlen(str1) + my_strlen(str2) + 1;
    char *str3 = NULL;

    str3 = malloc(sizeof(char) * length);
    if (str3 == NULL)
        return NULL;
    my_strcat_fill(str1, str2, str3);
    return str3;
}
