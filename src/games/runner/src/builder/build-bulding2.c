/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** initStruct.c
*/

#include "runner.h"

sfRectangleShape *buildBulding2()
{
    game_t *game = getGame();
    sfTexture *texture = game->assets->get(game->assets, "bulding");
    sfRectangleShape *bulding2 = sfRectangleShape_create();
    
    sfTexture_setRepeated(texture, sfTrue);
    sfRectangleShape_setTexture(bulding2, texture, sfTrue);
    sfRectangleShape_setTextureRect(bulding2, (sfIntRect){0, 0, game->window->mode.width, 256});
    sfRectangleShape_setScale(bulding2, (sfVector2f){2, 2});
    sfRectangleShape_setSize(bulding2, (sfVector2f){game->window->mode.width, 300});
    sfRectangleShape_setPosition(bulding2, (sfVector2f){0, (float)game->window->mode.height - 750});
    return bulding2;
} 