/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneGamePacman.c
*/

#include "gradeDe.h"

/* Button Action */

static void backButtonPressed(void)
{
    changeScene(SCENE_MENU_CHOOSE_GAME);
}


/* System */

SceneGamePacman_t *getSceneGamePacmanStruct(void)
{
    static SceneGamePacman_t sceneGamePacmanStruct;
    return &sceneGamePacmanStruct;
}

void eventManagerSceneGamePacman(void)
{
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();

    if (clickOnButton(sceneGamePacman->backbutton, &backButtonPressed)) return;
}

void renderSceneGamePacman(void)
{
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();

    renderRectangleShape(sceneGamePacman->background);
    renderRoundedRectangle(sceneGamePacman->backgroundGame);
    renderButton(sceneGamePacman->backbutton);
}

void loadSceneGamePacman(void)
{
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();

    sceneGamePacman->background = createRectangleShape(
        (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT},
        (sfColor) {99, 50, 79, 255},
        (sfVector2f){0, 0}
    );
    sceneGamePacman->backgroundGame = createRoundedRectangle(
        (sfVector3f){percent(WINDOW_WIDTH, 96), percent(WINDOW_HEIGHT, 78), 40},
        (sfColor){143, 87, 101, 255},
        (sfVector2f){percent(WINDOW_WIDTH, 2), percent(WINDOW_HEIGHT, 4)}
    );
    sceneGamePacman->backbutton = createButton(
        (sfVector2f){70, 70},
        "assets/image/IconArrowLeft.png",
        (sfVector2f){ 20, WINDOW_HEIGHT - 90}
    );
}

void destroySceneGamePacman(void)
{
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();

    destroyButton(sceneGamePacman->backbutton);
    sfRectangleShape_destroy(sceneGamePacman->background);
    sfConvexShape_destroy(sceneGamePacman->backgroundGame);
}
