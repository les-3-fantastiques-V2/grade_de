/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** drawGame.c
*/

#include "runner.h"

void drawGame(void)
{
    game_t *game = getGame();
    sfRenderWindow *window = game->window->window;

    for (d_node_t *node = game->decor.head; node; node = node->next) {
        sfRenderWindow_drawRectangleShape(
            window,
            ((layer_t *)node->data)->layer,
            NULL
        );
    }
}