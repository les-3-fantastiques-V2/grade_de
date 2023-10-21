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
    layer_t *layer_ground = malloc(sizeof(layer_t));
    sfTexture *texture = game->assets->get(game->assets, "ground");
    sfRectangleShape *ground = sfRectangleShape_create();

    sfTexture_setRepeated(texture, sfTrue);
    sfRectangleShape_setTexture(ground, texture, sfTrue);
    sfRectangleShape_setTextureRect(ground, (sfIntRect){0, 0, (int)game->window->mode.width * 2, 256});
    sfRectangleShape_setScale(ground, (sfVector2f){3, 2});
    sfRectangleShape_setSize(ground, (sfVector2f){(float)game->window->mode.width, 256});
    sfRectangleShape_setPosition(ground, (sfVector2f){0, (float)game->window->mode.height - 256});
    layer_ground->speed = 1.0f;
    layer_ground->layer = ground;
    return layer_ground;
}
