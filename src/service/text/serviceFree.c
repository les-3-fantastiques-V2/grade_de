/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceFree.c
*/

#include "gradeDe.h"

void freeCharArray(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
