/*
** EPITECH PROJECT, 2023
** src
** File description:
** parallax.c
*/

#include "runner.h"
#include <SFML/Graphics.h>

void parallaxEffect(float parallax_spd, sfRectangleShape *layer)
{
    game_t *game = getGame();
    float len = sfView_getSize(game->camera).x;
    float dist = sfView_getCenter(game->camera).x * (float)(1 - parallax_spd);
    float temp = sfView_getCenter(game->camera).x * (float)parallax_spd;

    sfView_setCenter(
        game->camera,
        (sfVector2f) {
            game->startPos + dist,
            sfView_getCenter(game->camera).y
        }
    );
    sfVector2f new_pos =
        sfRectangleShape_getPosition(layer);
    sfRectangleShape_setPosition(layer,
        (sfVector2f) {new_pos.x + dist, new_pos.y});
    if (temp > game->startPos + len)
        game->startPos += len;
    else if (temp < game->startPos - len)
        game->startPos -= len;
    sfRenderWindow_setView(game->window->window, game->camera);
}
