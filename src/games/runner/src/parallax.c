/*
** EPITECH PROJECT, 2023
** src
** File description:
** parallax.c
*/

#include "runner.h"
#include <SFML/Graphics.h>

void parallaxEffect(int parallax_spd)
{
    game_t *game = getGame();
    float len = sfView_getSize(game->camera).x;
    float temp = sfView_getCenter(game->camera).x * (1 - parallax_spd); //TODO: @H4rdeol
    float dist = sfView_getCenter(game->camera).x * parallax_spd;

    sfView_setCenter(game->camera, (sfVector2f) {game->startPos + dist, sfView_getCenter(game->camera).y});

    if (temp > game->startPos + len) 
        game->startPos += len; 
    else if (temp < game->startPos - len)
        game->startPos -= len;
}
