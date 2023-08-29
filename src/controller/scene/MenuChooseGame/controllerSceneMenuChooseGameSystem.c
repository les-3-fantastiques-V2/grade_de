/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneMenuChooseGameSystem.c
*/

#include "gradeDe.h"

SceneMenuChooseGame_t *getSceneMenuChooseGameStruct(void)
{
    static SceneMenuChooseGame_t sceneMenuChooseGameStruct;
    return &sceneMenuChooseGameStruct;
}

static bool _clickOnGame(void)
{
    GAME_E gameId = getGameSlotIdByMousePosition();
    if (gameId != NO_GAME) {
        printf("gameId: %d\n", gameId);
        return true;
    }
    return false;
}

static void _renderGameTooltips(void)
{
    GAME_E gameId = getGameSlotIdByMousePosition();
    if (gameId == -1) {
        return;
    }
    GameSlot_t *gameSlot = getGameSlotById(gameId);
    if (gameSlot == NULL) {
        return;
    }
    changeMouseCursor(CURSOR_INFO, CURSOR_TYPE_HINT);
    renderTooltips(gameSlot->tooltips);
}

static bool _mouseIsOnExit(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();
    sfVector2f circlePosition = sfCircleShape_getPosition(sceneMenuChooseGame->exitButton);
    float circleRadius = sfCircleShape_getRadius(sceneMenuChooseGame->exitButton);
    sfVector2f circleSize = (sfVector2f){circleRadius * 2, circleRadius * 2};

    return mouseIsOn(circlePosition, circleSize);
}

static bool _clickOnExit(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    if (_mouseIsOnExit()) {
        gradeDe->currentSceneId = EXIT;
        return true;
    }
    return false;
}

static bool _renderMouseOnExit(void)
{
    if (_mouseIsOnExit()) {
        changeMouseCursor(CURSOR_EXIT, CURSOR_TYPE_CENTER);
        return true;
    }
    return false;
}

static bool _mouseIsOnSettings(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();
    sfVector2f circlePosition = sfCircleShape_getPosition(sceneMenuChooseGame->settingsButton);
    float circleRadius = sfCircleShape_getRadius(sceneMenuChooseGame->settingsButton);
    sfVector2f circleSize = (sfVector2f){circleRadius * 2, circleRadius * 2};

    return mouseIsOn(circlePosition, circleSize);
}

static bool _clickOnSettings(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    if (_mouseIsOnSettings()) {
        gradeDe->currentSceneId = SCENE_MENU_SETTINGS;
        return true;
    }
    return false;
}

static bool _renderMouseOnSettings(void)
{
    if (_mouseIsOnSettings()) {
        changeMouseCursor(CURSOR_SETTINGS, CURSOR_TYPE_CENTER);
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
        if (_clickOnSettings()) return;
    }

    if (_renderMouseOnExit()) return;
    if (_renderMouseOnSettings()) return;
    changeMouseCursor(CURSOR_DEFAULT, CURSOR_TYPE_POINTER);
}

void renderSceneMenuChooseGame(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();

    renderRectangleShape(sceneMenuChooseGame->background);
    renderRectangleShape(sceneMenuChooseGame->backgroundMenu);
    renderCircleShape(sceneMenuChooseGame->exitButton);
    renderCircleShape(sceneMenuChooseGame->settingsButton);
    renderGameSlotList();
    _renderGameTooltips();
    _renderMouseOnExit();
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
    sceneMenuChooseGame->settingsButton = createCircleShape(
        40,
        sfColor_fromRGB(163, 92, 214),
        (sfVector2f){20, WINDOW_HEIGHT - 100}
    );
}

void destroySceneMenuChooseGame(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();

    sfCircleShape_destroy(sceneMenuChooseGame->exitButton);
    sfRectangleShape_destroy(sceneMenuChooseGame->background);
    sfRectangleShape_destroy(sceneMenuChooseGame->backgroundMenu);
}
