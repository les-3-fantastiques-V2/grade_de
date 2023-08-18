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

map_t *load_assets(char *game);
void destroy_assets(map_t *assets);

#endif //GRADE_DE_MAIN_H
