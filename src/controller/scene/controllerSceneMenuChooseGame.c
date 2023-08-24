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

static bool _clickOnGame(void)
{
    int gameId = getGameSlotIdByMousePosition();
    if (gameId != -1) {
        printf("gameId: %d\n", gameId);
        return true;
    }
    return false;
}

static bool _clickOnExit(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();
    sfVector2f circlePosition = sfCircleShape_getPosition(sceneMenuChooseGame->exitButton);
    float circleRadius = sfCircleShape_getRadius(sceneMenuChooseGame->exitButton);
    sfVector2f circleSize = (sfVector2f){circleRadius * 2, circleRadius * 2};

    if (mouseIsOn(circlePosition, circleSize)) {
        gradeDe->currentSceneId = EXIT;
        return true;
    }
    return false;
}

void eventManagerSceneMenuChooseGame(void)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    if (windowConfig->event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (_clickOnGame()) return;
        if (_clickOnExit()) return;
    }
}

void renderGamePopUp(void)
{
    int gameId = getGameSlotIdByMousePosition();
    if (gameId == -1) return;
    GameSlot_t *gameSlot = getGameSlotById(gameId);
    if (gameSlot == NULL) return;
    renderTooltips(gameSlot->tooltips);
}

void renderSceneMenuChooseGame(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();

    eventManagerSceneMenuChooseGame();
    renderRectangleShape(sceneMenuChooseGame->background);
    renderRectangleShape(sceneMenuChooseGame->backgroundMenu);
    renderCircleShape(sceneMenuChooseGame->exitButton);
    renderGameSlotList();
    renderGamePopUp();
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
    sceneMenuChooseGame->exitButton = createCircleShape(
        40,
        sfColor_fromRGB(229, 9, 20),
        (sfVector2f){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100}
    );
}

void destroySceneMenuChooseGame(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();

    sfCircleShape_destroy(sceneMenuChooseGame->exitButton);
    sfRectangleShape_destroy(sceneMenuChooseGame->background);
    sfRectangleShape_destroy(sceneMenuChooseGame->backgroundMenu);
}
