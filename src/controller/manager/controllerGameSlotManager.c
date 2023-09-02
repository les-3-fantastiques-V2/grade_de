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
    GameSlotList_t *gameSlotList = sceneMenuChooseGame->gameSlotList;

    for (int j = 0; j < sceneMenuChooseGame->currentSlotId; j++) {
        if (gameSlotList == NULL) return;
        gameSlotList = gameSlotList->next;
    }
    for (int i = 0; i < 6; i++) {
        if (gameSlotList == NULL) {
            sfConvexShape_setPosition(sceneMenuChooseGame->emptySlot->iconBox, _getSlotPosition(i));
            renderRoundedRectangle(sceneMenuChooseGame->emptySlot->iconBox);
        } else {
            sfConvexShape_setPosition(gameSlotList->gameSlot->iconBox, _getSlotPosition(i));
            renderRoundedRectangle(gameSlotList->gameSlot->iconBox);
            gameSlotList = gameSlotList->next;
        }
    }
}

int getGameSlotPositionIdByMousePosition(void)
{
    for (int i = 0; i < 6; i++) {
        sfVector2f position = _getSlotPosition(i);
        sfVector2f size = (sfVector2f){GAME_SLOT_WIDTH, GAME_SLOT_HEIGHT};
        if (mouseIsOn(position, size)) {
            return i;
        }
    }
    return -1;
}