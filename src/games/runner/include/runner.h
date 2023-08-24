/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** runner.h
*/

#ifndef GRADE_DE_RUNNER_H
    #define GRADE_DE_RUNNER_H

    #include <stdio.h>

    #include "main.h"

typedef struct windowConfig_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    char *title;
    sfEvent event;
    int fps;
} windowConfig_t;

typedef struct player_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfClock *clock;
} player_t;

typedef struct game_s {
    windowConfig_t *window;
    sfClock *clock;
    map_t *assets;
    d_list_t decor;
    player_t *player;
    int score;
} game_t;

void pollEvent(void);
game_t *getGame(void);
void fillGame(game_t *game, map_t *assets);
void drawGame(void);

#endif //GRADE_DE_RUNNER_H
