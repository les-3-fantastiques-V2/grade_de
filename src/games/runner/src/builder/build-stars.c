/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** initStruct.c
*/

#include "runner.h"

layer_t *buildStars(void)
{
    game_t *game = getGame();
    sfTexture *texture = game->assets->get(game->assets, "stars");
    layer_t *layer_stars = malloc(sizeof(layer_t));
    sfRectangleShape *stars = sfRectangleShape_create();

    sfRectangleShape_setTexture(stars, texture, sfTrue);
    sfRectangleShape_setPosition(stars, (sfVector2f){0, 0});
    sfRectangleShape_setSize(stars, (sfVector2f){(float)game->window->mode.width, 1500});
    layer_stars->speed = 0.9f;
    layer_stars->layer = stars;
    return layer_stars;
}
