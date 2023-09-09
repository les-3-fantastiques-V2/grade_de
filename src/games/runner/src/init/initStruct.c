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
    window->mode = sfVideoMode_getDesktopMode();
    window->title = "Grade dé";
    window->fps = 60;
    window->window = sfRenderWindow_create(window->mode, window->title, sfFullscreen, NULL);
}

static void initDecor(void)
{
    game_t *game = getGame();

    d_append_list(false, buildStars(), &game->decor, D_OTHER);
    d_append_list(false, buildMoon(), &game->decor, D_OTHER);
    d_append_list(false, buildGround(), &game->decor, D_OTHER);
    d_append_list(false, buildBulding2(), &game->decor, D_OTHER);
    d_append_list(false, buildBulding(), &game->decor, D_OTHER);
    d_append_list(false, buildWall(), &game->decor, D_OTHER);
}

void fillGame(game_t *game, map_t *assets)
{
    game->window = malloc(sizeof(windowConfig_t));
    fillWindow(game->window);
    game->score = 0;
    game->assets = assets;
    game->clock = sfClock_create();
    game->player = NULL;
    game->decor = d_init_list();
    initDecor();
}