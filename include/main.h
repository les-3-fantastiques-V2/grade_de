/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** main.h
*/

#ifndef GRADE_DE_MAIN_H
    #define GRADE_DE_MAIN_H

    #include <SFML/Graphics.h>
    #include <SFML/Config.h>
    #include <string.h>
    #include <stdlib.h>

    #include "double_list.h"
    #include "map.h"

char *getFilePath(char *pathToDir, char *name);
map_t *loadAssets(char *game);
void destroyAssets(map_t *assets);

#endif //GRADE_DE_MAIN_H
