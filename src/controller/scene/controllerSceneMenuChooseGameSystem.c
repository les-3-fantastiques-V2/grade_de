/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneMenuChooseGameSystem.c
*/

#include "gradeDe.h"

static void _renderGameTooltips(void)
{
    CURSOR_E cursorId = getMouseCursorId();
    CURSOR_TYPE_E cursorType = getMouseCursorType();
    if (cursorId == CURSOR_INFO) {
        cursorId = CURSOR_DEFAULT;
        cursorType = CURSOR_TYPE_POINTER;
    }

    GAME_E gameId = getGameSlotIdByMousePosition();
    if (gameId == -1) {
        changeMouseCursor(cursorId, cursorType);
        return;
    }
    GameSlot_t *gameSlot = getGameSlotById(gameId);
    if (gameSlot == NULL) {
        changeMouseCursor(cursorId, cursorType);
        return;
    }
    changeMouseCursor(CURSOR_INFO, CURSOR_TYPE_CENTER);
    renderTooltips(gameSlot->tooltips);
}

static void _modifyCurrentSlotId(int value)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();

    sceneMenuChooseGame->currentSlotId += 6 * value;

    if (sceneMenuChooseGame->currentSlotId <= 0) {
        sceneMenuChooseGame->asPrevious = false;
    }

    sceneMenuChooseGame->asPrevious = (sceneMenuChooseGame->currentSlotId > 0) ? true : false;
    sceneMenuChooseGame->asNext = (sceneMenuChooseGame->currentSlotId < GAME_MAX - 6) ? true : false;
}

/* System */


SceneMenuChooseGame_t *getSceneMenuChooseGameStruct(void)
{
    static SceneMenuChooseGame_t sceneMenuChooseGameStruct;
    return &sceneMenuChooseGameStruct;
}

void eventManagerSceneMenuChooseGame(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();

    if (clickOnButton(sceneMenuChooseGame->exitButton)) {
        changeScene(EXIT); return;
    }
    if (clickOnButton(sceneMenuChooseGame->leftArrowButton) && sceneMenuChooseGame->asPrevious) {
        _modifyCurrentSlotId(-1); return;
    }
    if (clickOnButton(sceneMenuChooseGame->rightArrowButton) && sceneMenuChooseGame->asNext) {
        _modifyCurrentSlotId(1); return;
    }
}

void renderSceneMenuChooseGame(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();

    renderRectangleShape(sceneMenuChooseGame->background);
    renderRoundedRectangle(sceneMenuChooseGame->backgroundMenu);
    renderGameSlotList();
    _renderGameTooltips();
    renderButton(sceneMenuChooseGame->exitButton);
    if (sceneMenuChooseGame->asPrevious) renderButton(sceneMenuChooseGame->leftArrowButton);
    if (sceneMenuChooseGame->asNext) renderButton(sceneMenuChooseGame->rightArrowButton);
}

void loadSceneMenuChooseGame(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();
    changeMouseCursor(CURSOR_DEFAULT, CURSOR_TYPE_POINTER);

    sceneMenuChooseGame->currentSlotId = 0;
    initGameSlotListStruct();
    sceneMenuChooseGame->emptySlot = getGameSlotById(-1);
    sceneMenuChooseGame->background = createRectangleShape(
        (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT},
        (sfColor) {99, 50, 79, 255},
        (sfVector2f){0, 0}
    );
    sceneMenuChooseGame->backgroundMenu = createRoundedRectangle(
        (sfVector3f){percent(WINDOW_WIDTH, 96), percent(WINDOW_HEIGHT, 78), 40},
        (sfColor){143, 87, 101, 255},
        (sfVector2f){percent(WINDOW_WIDTH, 2), percent(WINDOW_HEIGHT, 4)}
    );
    sceneMenuChooseGame->exitButton = createButton(
        (sfVector2f){70, 81},
        "assets/image/IconExit.png",
        (sfVector2f){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100}
    );
    sceneMenuChooseGame->leftArrowButton = createButton(
        (sfVector2f){42, 60},
        "assets/image/IconLeft.png",
        (sfVector2f) {20, percent(WINDOW_HEIGHT, 80) / 2 - 30}
    );
    sceneMenuChooseGame->rightArrowButton = createButton(
        (sfVector2f){42, 60},
        "assets/image/IconRight.png",
        (sfVector2f) {WINDOW_WIDTH - 62, percent(WINDOW_HEIGHT, 80) / 2 - 30}
    );
    sceneMenuChooseGame->asPrevious = false;
    sceneMenuChooseGame->asNext = (GAME_MAX > 6) ? true : false;
}

void destroySceneMenuChooseGame(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();

    // TODO: Fix segfault
    // destroyButton(sceneMenuChooseGame->LeftArrowButton);
    // destroyButton(sceneMenuChooseGame->RightArrowButton);
    // destroyButton(sceneMenuChooseGame->exitButton);

    sfRectangleShape_destroy(sceneMenuChooseGame->background);
    sfConvexShape_destroy(sceneMenuChooseGame->backgroundMenu);
    destroyButton(sceneMenuChooseGame->exitButton);
}
