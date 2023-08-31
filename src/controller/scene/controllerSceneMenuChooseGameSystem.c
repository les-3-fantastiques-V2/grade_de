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
        changeScene(EXIT);
        return;
    }
}

void renderSceneMenuChooseGame(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();

    renderRectangleShape(sceneMenuChooseGame->background);
    renderRectangleShape(sceneMenuChooseGame->backgroundMenu);
    renderGameSlotList();
    _renderGameTooltips();
    renderButton(sceneMenuChooseGame->exitButton);
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
        (sfColor) {50, 50, 50, 255},
        (sfVector2f){0, 0}
    );
    sceneMenuChooseGame->backgroundMenu = createRectangleShape(
        (sfVector2f){WINDOW_WIDTH, percent(WINDOW_HEIGHT, 80)},
        (sfColor){100, 100, 100, 255},
        (sfVector2f){0, 0}
    );
    sceneMenuChooseGame->exitButton = createButton(
        (sfVector2f){70, 81},
        "assets/image/IconExit.png",
        (sfVector2f){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100}
    );
}

void destroySceneMenuChooseGame(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();

    sfRectangleShape_destroy(sceneMenuChooseGame->background);
    sfRectangleShape_destroy(sceneMenuChooseGame->backgroundMenu);
    destroyButton(sceneMenuChooseGame->exitButton);
}
