/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerGameSlot.c
*/

#include "gradeDe.h"

char *gameName[GAME_MAX] = {
    "Test",
};

char *gameDescription[GAME_MAX] = {
    "Testing Slot",
};

static GameSlot_t *_getEmptyGameSlot()
{
    GameSlot_t *emptySlot = malloc(sizeof(GameSlot_t));
    emptySlot->id = -1;
    emptySlot->name = "";
    emptySlot->description = "";
    emptySlot->icon = createRectangleShape((sfVector2f){GAME_SLOT_WIDTH, GAME_SLOT_HEIGHT}, sfColor_fromRGB(255, 255, 255), (sfVector2f){0, 0});

    return emptySlot;
}

GameSlot_t *getGameSlotById(int gameId)
{
    if (gameId == -1) return _getEmptyGameSlot();
    if (gameId < 0 || gameId >= GAME_MAX) return NULL;

    GameSlot_t *gameSlot = malloc(sizeof(GameSlot_t));
    gameSlot->id = gameId;
    gameSlot->name = gameName[gameId];
    gameSlot->description = gameDescription[gameId];
    gameSlot->icon = createRectangleShape((sfVector2f){GAME_SLOT_WIDTH, GAME_SLOT_HEIGHT}, sfColor_fromRGB(150, 150, 150), (sfVector2f){0, 0});

    return gameSlot;
}

int getGameSlotIdByMousePosition() {
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();
    WindowConfig_t *windowConfig = getWindowConfigStruct();
    GameSlotList_t *gameSlotList = sceneMenuChooseGame->gameSlotList;
    sfVector2i mousePosition =  sfMouse_getPositionRenderWindow(windowConfig->window);

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < sceneMenuChooseGame->currentSlotId; j++) {
            gameSlotList = gameSlotList->next;
        }
        if (gameSlotList == NULL) break;

        sfVector2f slotPosition = sfRectangleShape_getPosition(gameSlotList->gameSlot->icon);
        if (mousePosition.x >= slotPosition.x && mousePosition.x <= slotPosition.x + GAME_SLOT_WIDTH &&
            mousePosition.y >= slotPosition.y && mousePosition.y <= slotPosition.y + GAME_SLOT_HEIGHT) {
            return gameSlotList->gameSlot->id;
        }
    }

    return -1;
}
