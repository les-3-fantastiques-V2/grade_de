/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneChooseGame.c
*/

#include "gradeDe.h"

SceneMenuChooseGame_t *getSceneMenuChooseGameStruct(void)
{
    static SceneMenuChooseGame_t sceneMenuChooseGameStruct;
    return &sceneMenuChooseGameStruct;
}

void _eventManager(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    if (windowConfig->event.mouseButton.type == sfEvtMouseButtonReleased && windowConfig->event.mouseButton.button == sfMouseRight) {
        int gameId = getGameSlotIdByMousePosition();
        if (gameId != -1) gradeDe->currentSceneId = EXIT;
    }
}

void renderSceneMenuChooseGame(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    sfRenderWindow_drawRectangleShape(windowConfig->window, sceneMenuChooseGame->background, NULL);
    sfRenderWindow_drawRectangleShape(windowConfig->window, sceneMenuChooseGame->backgroundMenu, NULL);
    renderGameSlotList();
    _eventManager();
}

void loadSceneMenuChooseGame(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();

    sceneMenuChooseGame->currentSlotId = 0;
    initGameSlotListStruct();
    sceneMenuChooseGame->emptySlot = getGameSlotById(-1);
    sceneMenuChooseGame->background = createRectangleShape(
        (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT},
        sfColor_fromRGB(50, 50, 50),
        (sfVector2f){0, 0}
    );
    sceneMenuChooseGame->backgroundMenu = createRectangleShape(
        (sfVector2f){WINDOW_WIDTH, percent(WINDOW_HEIGHT, 80)},
        sfColor_fromRGB(100, 100, 100),
        (sfVector2f){0, 0}
    );
}

void destroySceneMenuChooseGame(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();

    sfRectangleShape_destroy(sceneMenuChooseGame->background);
    sfRectangleShape_destroy(sceneMenuChooseGame->backgroundMenu);
}
