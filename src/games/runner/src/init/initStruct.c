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
    sfSprite *ground = sfSprite_create();
    sfSprite_setTexture(ground, assets->get(assets, "ground"), sfTrue);
    sfSprite_setPosition(ground, (sfVector2f){0, (float)game->window->mode.height - 256});
    sfSprite_setScale(ground, (sfVector2f){3, 1});
    sfSprite *stars = sfSprite_create();
    sfSprite_setTexture(stars, assets->get(assets, "stars"), sfTrue);
    sfSprite_setPosition(stars, (sfVector2f){0, 0});
    sfSprite_setScale(stars, (sfVector2f){3, 3});
    sfSprite *moon = sfSprite_create();
    sfSprite_setTexture(moon, assets->get(assets, "moon"), sfTrue);
    sfSprite_setScale(moon, (sfVector2f){2, 2});
    sfSprite_setPosition(moon, (sfVector2f){(float)game->window->mode.width / 5, 0});
    sfSprite *wall = sfSprite_create();
    sfSprite_setTexture(wall, assets->get(assets, "wall"), sfTrue);
    sfSprite_setPosition(wall, (sfVector2f){0, (float)game->window->mode.height - 600});
    sfSprite_setScale(wall, (sfVector2f){3, 1.5f});
    sfSprite *bulding = sfSprite_create();
    sfSprite_setTexture(bulding, assets->get(assets, "fgBulding"), sfTrue);
    sfSprite_setPosition(bulding, (sfVector2f){0, (float)game->window->mode.height - 800});
    sfSprite_setScale(bulding, (sfVector2f){3, 2});
    sfSprite *bulding2 = sfSprite_create();
    sfTexture_setRepeated(assets->get(assets, "bulding"), sfTrue);
    sfSprite_setTexture(bulding2, assets->get(assets, "bulding"), sfTrue);
    sfSprite_setPosition(bulding2, (sfVector2f){0, (float)game->window->mode.height - 800});
    sfSprite_setScale(bulding2, (sfVector2f){3, 2});
    sfSprite_setTextureRect(bulding2, (sfIntRect){0, 0, 723, 256});
    d_append_list(false, stars, &game->decor, D_OTHER);
    d_append_list(false, moon, &game->decor, D_OTHER);
    d_append_list(false, ground, &game->decor, D_OTHER);
    d_append_list(false, bulding2, &game->decor, D_OTHER);
    d_append_list(false, bulding, &game->decor, D_OTHER);
    d_append_list(false, wall, &game->decor, D_OTHER);
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
