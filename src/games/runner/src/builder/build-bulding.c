/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** initStruct.c
*/

#include "runner.h"

layer_t *buildBulding(void)
{
    game_t *game = getGame();
    layer_t *layer_building = malloc(sizeof(layer_t));
    sfTexture *texture = game->assets->get(game->assets, "fgBulding");
    sfRectangleShape *bulding = sfRectangleShape_create();

    sfTexture_setRepeated(texture, sfTrue);
    sfRectangleShape_setTexture(bulding, texture, sfTrue);
    sfRectangleShape_setTextureRect(bulding, (sfIntRect){0, 0, (int)game->window->mode.width * 2, 256});
    sfRectangleShape_setScale(bulding, (sfVector2f){3, 2});
    sfRectangleShape_setSize(bulding, (sfVector2f){(float)game->window->mode.width, 256});
    sfRectangleShape_setPosition(bulding, (sfVector2f){0, (float)game->window->mode.height - 700});
    layer_building->speed = 0.4f;
    layer_building->layer = bulding;
    return layer_building;
}
