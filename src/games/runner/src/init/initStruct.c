/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** initStruct.c
*/

#include "runner.h"

game_t *getGame(void)
{
    static game_t game;
    return &game;
}

static void fillWindow(windowConfig_t *window)
{
    window->mode = (sfVideoMode){1920, 1080, 32};
    window->title = "Grade dé";
    window->fps = 60;
    window->window = sfRenderWindow_create(window->mode, window->title, sfFullscreen, NULL);
}

static void initDecor(void)
{
    game_t *game = getGame();
    map_t *assets = game->assets;
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, assets->get(assets, "ground"), sfTrue);
    d_append_list(false, sprite, &game->decor, D_OTHER);
}

void fillGame(game_t *game, map_t *assets)
{
    game->score = 0;
    game->assets = assets;
    game->clock = sfClock_create();
    game->player = NULL;
    game->decor = d_init_list();
    initDecor();
    game->window = malloc(sizeof(windowConfig_t));
    fillWindow(game->window);
}
