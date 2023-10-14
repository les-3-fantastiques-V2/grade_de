/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** initStruct.c
*/

#include "runner.h"

layer_t *buildMoon(void)
{
    game_t *game = getGame();
    sfTexture *texture = game->assets->get(game->assets, "moon");
    layer_t *layer_moon = malloc(sizeof(layer_t));
    sfRectangleShape *moon = sfRectangleShape_create();
    
    sfRectangleShape_setTexture(moon, texture, sfTrue);
    sfRectangleShape_setSize(moon, (sfVector2f){1446, 512});
    sfRectangleShape_setPosition(moon, (sfVector2f){(float)game->window->mode.width / 5, 0});
    layer_moon->layer = moon;
    layer_moon->speed = 1.0f;
    return layer_moon;
}
