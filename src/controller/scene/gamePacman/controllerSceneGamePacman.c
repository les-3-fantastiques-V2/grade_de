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
    playTransition(SCENE_MENU_CHOOSE_GAME);
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
    changeMouseCursor(CURSOR_DEFAULT, CURSOR_TYPE_POINTER);

    sceneGamePacman->background = createRectangleShape(
        (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT},
        (sfColor) {99, 50, 79, 255},
        (sfVector2f){0, 0}
    );
    sceneGamePacman->backgroundGame = createRoundedRectangle(
        (sfVector3f){percent(WINDOW_WIDTH, 96), percent(WINDOW_HEIGHT, 78), 40},
        (sfColor){0, 0, 0, 255},
        (sfVector2f){percent(WINDOW_WIDTH, 2), percent(WINDOW_HEIGHT, 4)}
    );
    sfConvexShape_setOutlineColor(sceneGamePacman->backgroundGame, (sfColor){255, 165, 66, 255});
    sfConvexShape_setOutlineThickness(sceneGamePacman->backgroundGame, 2);
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
