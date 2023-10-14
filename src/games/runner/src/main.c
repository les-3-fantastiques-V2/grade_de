/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** main.c
*/

#include "runner.h"

static void startRunner(void)
{
    game_t *game = getGame();
    fillGame(game, loadAssets("runner"));
}

static void loopRunner(void)
{
    game_t *game = getGame();
    sfRenderWindow *window = game->window->window;

    sfRenderWindow_setFramerateLimit(window, game->window->fps);
    while (sfRenderWindow_isOpen(window)) {
        pollEvent();
        sfRenderWindow_clear(window, sfBlack);
        drawGame();
        sfRenderWindow_display(window);
    }
}

static void stopRunner(void)
{
    game_t *game = getGame();

    sfClock_destroy(game->clock);
    sfRenderWindow_destroy(game->window->window);
    destroyAssets(game->assets);
    for (d_node_t *curr = game->decor.head; curr; curr = curr->next) {
        sfRectangleShape_destroy(((layer_t *) curr->data)->layer);
        free(curr->data);
    }
    d_free_list(&game->decor, NULL, 0);
    free(game->window);
}

int main(void)
{
    startRunner();
    loopRunner();
    stopRunner();
    return 0;
}
