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
        if (game->window->event.key.code == sfKeyRight) {
            sfVector2f pos = sfView_getCenter(game->camera);
                sfView_setCenter(
                    game->camera,
                    (sfVector2f) {pos.x + 5, pos.y}
                );
            sfRenderWindow_setView(game->window->window, game->camera);
            sfView *tmp = game->camera;
            game->camera = sfView_copy(sfRenderWindow_getView(game->window->window));
            sfView_destroy(tmp);
            for (d_node_t *node = game->decor.head; node; node = node->next)
                parallaxEffect(((layer_t *)node->data)->speed);
        }
    }
}
