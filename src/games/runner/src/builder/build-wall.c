/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** initStruct.c
*/

#include "runner.h"

sfRectangleShape *buildWall()
{
    game_t *game = getGame();
    sfTexture *texture = game->assets->get(game->assets, "wall");
    sfRectangleShape *wall = sfRectangleShape_create();
    
    sfRectangleShape_setTexture(wall, texture, sfTrue);
    sfRectangleShape_setPosition(wall, (sfVector2f){0, (float)game->window->mode.height - 600});
    sfRectangleShape_setSize(wall, (sfVector2f){(float)game->window->mode.width, 500});
    return wall;
}
