/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** getFileName.c
*/

#include "main.h"

char *getFilePath(char *pathToDir, char *name)
{
    char *path = malloc(sizeof(char) * (strlen(pathToDir) + strlen(name) + 2));
    memset(path, 0, strlen(pathToDir) + strlen(name) + 2);
    strcpy(path, pathToDir);
    strcat(path, "/");
    strcat(path, name);
    return path;
}
