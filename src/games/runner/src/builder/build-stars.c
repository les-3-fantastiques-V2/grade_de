/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** initStruct.c
*/

#include "runner.h"

sfRectangleShape *buildStars(void)
{
    game_t *game = getGame();
    sfTexture *texture = game->assets->get(game->assets, "stars");
    sfRectangleShape *stars = sfRectangleShape_create();

    sfRectangleShape_setTexture(stars, texture, sfTrue);
    sfRectangleShape_setPosition(stars, (sfVector2f){0, 0});
    sfRectangleShape_setSize(stars, (sfVector2f){(float)game->window->mode.width, 700});
    return stars;
}
