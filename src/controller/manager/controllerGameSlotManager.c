/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerGameSlotManager.c
*/

#include "gradeDe.h"

static sfVector2f _getSlotPosition(int i)
{
    sfVector2f slotPosition[6] = {
        {WINDOW_WIDTH / 6 * 1 - GAME_SLOT_WIDTH / 2, percent(WINDOW_HEIGHT, 80) / 8 * 2 - GAME_SLOT_HEIGHT / 2},
        {WINDOW_WIDTH / 6 * 3 - GAME_SLOT_WIDTH / 2, percent(WINDOW_HEIGHT, 80) / 8 * 2 - GAME_SLOT_HEIGHT / 2},
        {WINDOW_WIDTH / 6 * 5 - GAME_SLOT_WIDTH / 2, percent(WINDOW_HEIGHT, 80) / 8 * 2 - GAME_SLOT_HEIGHT / 2},
        {WINDOW_WIDTH / 6 * 1 - GAME_SLOT_WIDTH / 2, percent(WINDOW_HEIGHT, 80) / 8 * 6 - GAME_SLOT_HEIGHT / 2},
        {WINDOW_WIDTH / 6 * 3 - GAME_SLOT_WIDTH / 2, percent(WINDOW_HEIGHT, 80) / 8 * 6 - GAME_SLOT_HEIGHT / 2},
        {WINDOW_WIDTH / 6 * 5 - GAME_SLOT_WIDTH / 2, percent(WINDOW_HEIGHT, 80) / 8 * 6 - GAME_SLOT_HEIGHT / 2},
    };

    return slotPosition[i];
}

void renderGameSlotList(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();
    WindowConfig_t *windowConfig = getWindowConfigStruct();
    GameSlotList_t *gameSlotList = sceneMenuChooseGame->gameSlotList;

    for (int j = 0; j < sceneMenuChooseGame->currentSlotId; j++) {
        if (gameSlotList == NULL) return;
        gameSlotList = gameSlotList->next;
    }
    for (int i = 0; i < 6; i++) {
        if (gameSlotList == NULL) {
            sfRectangleShape_setPosition(sceneMenuChooseGame->emptySlot->icon, _getSlotPosition(i));
            sfRenderWindow_drawRectangleShape(windowConfig->window, sceneMenuChooseGame->emptySlot->icon, NULL);
        } else {
            sfRectangleShape_setPosition(gameSlotList->gameSlot->icon, _getSlotPosition(i));
            sfRenderWindow_drawRectangleShape(windowConfig->window, gameSlotList->gameSlot->icon, NULL);
            gameSlotList = gameSlotList->next;
        }
    }
}

