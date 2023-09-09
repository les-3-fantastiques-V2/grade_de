/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** initStruct.c
*/

#include "runner.h"

sfRectangleShape *buildMoon(void)
{
    game_t *game = getGame();
    sfTexture *texture = game->assets->get(game->assets, "moon");
    sfRectangleShape *moon = sfRectangleShape_create();
    
    sfRectangleShape_setTexture(moon, texture, sfTrue);
    sfRectangleShape_setSize(moon, (sfVector2f){1446, 512});
    sfRectangleShape_setPosition(moon, (sfVector2f){(float)game->window->mode.width / 5, 0});
    return moon;
}
