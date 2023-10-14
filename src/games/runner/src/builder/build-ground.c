/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** initStruct.c
*/

#include "runner.h"

layer_t *buildGround(void)
{
    game_t *game = getGame();
    sfTexture *texture = game->assets->get(game->assets, "ground");
    layer_t *layer_ground = malloc(sizeof(layer_t));
    sfRectangleShape *ground = sfRectangleShape_create();
    
    sfRectangleShape_setTexture(ground, texture, sfTrue);
    sfRectangleShape_setPosition(ground, (sfVector2f){0, (float)game->window->mode.height - 256});
    sfRectangleShape_setSize(ground, (sfVector2f){(float)game->window->mode.width, 256});
    layer_ground->layer = ground;
    layer_ground->speed = 1.0f;
    return layer_ground;
}
