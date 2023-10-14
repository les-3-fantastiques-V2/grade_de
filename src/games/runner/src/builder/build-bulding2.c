/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** initStruct.c
*/

#include "runner.h"

layer_t *buildBulding2(void)
{
    game_t *game = getGame();
    layer_t *layer_building2 = malloc(sizeof(layer_t));
    sfTexture *texture = game->assets->get(game->assets, "bulding");
    sfRectangleShape *bulding2 = sfRectangleShape_create();
    
    sfTexture_setRepeated(texture, sfTrue);
    sfRectangleShape_setTexture(bulding2, texture, sfTrue);
    sfRectangleShape_setTextureRect(bulding2, (sfIntRect){0, 0, (int)(game->window->mode.width * 2), 256});
    sfRectangleShape_setScale(bulding2, (sfVector2f){2, 2});
    sfRectangleShape_setSize(bulding2, (sfVector2f){(float)game->window->mode.width, 300});
    sfRectangleShape_setPosition(bulding2, (sfVector2f){0, (float)game->window->mode.height - 750});
    layer_building2->layer = bulding2;
    layer_building2->speed = 1.0f;
    return layer_building2;
} 