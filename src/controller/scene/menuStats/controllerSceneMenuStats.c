/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneMenuStats.c
*/

#include "gradeDe.h"

/* Button */

static void _backButtonPressed(void)
{
    changeScene(SCENE_MENU_CHOOSE_GAME);
}


/* System */

SceneMenuStats_t *getSceneMenuStatsStruct(void)
{
    static SceneMenuStats_t SceneMenuStatsStruct;
    return &SceneMenuStatsStruct;
}

void eventManagerSceneMenuStats(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    if (clickOnButton(sceneMenuStats->backButton, &_backButtonPressed)) return;
}

void renderSceneMenuStats(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    renderRectangleShape(sceneMenuStats->background);
    renderRoundedRectangle(sceneMenuStats->backgroundMenu);
    renderRoundedRectangle(sceneMenuStats->line);
    renderButton(sceneMenuStats->backButton);
    renderStatsSection();
}

void loadSceneMenuStats(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();
    changeMouseCursor(CURSOR_DEFAULT, CURSOR_TYPE_POINTER);
    changeMusic(MUSIC_HOME_AMBIENT);


    sceneMenuStats->background = createRectangleShape(
        (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT},
        (sfColor) {99, 50, 79, 255},
        (sfVector2f){0, 0}
    );
    sceneMenuStats->backgroundMenu = createRoundedRectangle(
        (sfVector3f){percent(WINDOW_WIDTH, 96), percent(WINDOW_HEIGHT, 78), 40},
        (sfColor){143, 87, 101, 255},
        (sfVector2f){percent(WINDOW_WIDTH, 2), percent(WINDOW_HEIGHT, 4)}
    );
    sceneMenuStats->line = createRoundedRectangle(
        (sfVector3f){10, percent(WINDOW_HEIGHT, 70), 4},
        (sfColor) {99, 50, 79, 255},
        (sfVector2f){400, percent(WINDOW_HEIGHT, 8)}
    );
    sceneMenuStats->backButton = createButton(
        (sfVector2f){80, 70},
        "assets/image/IconArrowLeft.png",
        (sfVector2f){20, WINDOW_HEIGHT - 100}
    );
    initStatsSection();
}

void destroySceneMenuStats(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    destroyStatsSection();
    destroyButton(sceneMenuStats->backButton);
    sfRectangleShape_destroy(sceneMenuStats->background);
    sfConvexShape_destroy(sceneMenuStats->backgroundMenu);
    sfConvexShape_destroy(sceneMenuStats->line);
}
