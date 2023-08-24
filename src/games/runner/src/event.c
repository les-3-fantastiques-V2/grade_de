/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** event.c
*/

#include "runner.h"

void pollEvent(void)
{
    game_t *game = getGame();

    while (sfRenderWindow_pollEvent(game->window->window, &game->window->event)) {
        if (game->window->event.type == sfEvtClosed || game->window->event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->window->window);
    }
}
