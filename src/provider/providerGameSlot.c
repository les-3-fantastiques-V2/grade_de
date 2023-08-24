/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerGameSlot.c
*/

#include "gradeDe.h"

char *gameName[GAME_MAX] = {
};

char *gameDescription[GAME_MAX] = {
};

void destroyGameSlot(GameSlot_t *gameSlot)
{
    sfRectangleShape_destroy(gameSlot->icon);
    destroyGameTooltips(gameSlot->tooltips);
    free(gameSlot);
}

GameSlot_t *createEmptyGameSlot()
{
    GameSlot_t *emptySlot = malloc(sizeof(GameSlot_t));
    emptySlot->id = -1;
    emptySlot->icon = createRectangleShape((sfVector2f){GAME_SLOT_WIDTH, GAME_SLOT_HEIGHT}, sfColor_fromRGB(150, 150, 150), (sfVector2f){0, 0});
    emptySlot->tooltips = createGameTooltips("empty slot", "empty slot");

    return emptySlot;
}

int getGameSlotIdByMousePosition() {
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();
    GameSlotList_t *gameSlotList = sceneMenuChooseGame->gameSlotList;

    for (int j = 0; j < sceneMenuChooseGame->currentSlotId; j++) {
        if (gameSlotList == NULL) return -1;
        gameSlotList = gameSlotList->next;
    }
    for (int i = 0; i < 6; i++) {
        if (gameSlotList == NULL) break;
        sfVector2f slotPosition = sfRectangleShape_getPosition(gameSlotList->gameSlot->icon);
        if (mouseIsOn(slotPosition, (sfVector2f){GAME_SLOT_WIDTH, GAME_SLOT_HEIGHT}))
            return gameSlotList->gameSlot->id;
        gameSlotList = gameSlotList->next;
    }

    return -1;
}

GameSlot_t *createGameSlotById(int gameId)
{
    GameSlot_t *gameSlot = malloc(sizeof(GameSlot_t));
    gameSlot->id = gameId;
    gameSlot->icon = createRectangleShape((sfVector2f){GAME_SLOT_WIDTH, GAME_SLOT_HEIGHT}, sfColor_fromRGB(255, 255, 255), (sfVector2f){0, 0});
    gameSlot->tooltips = createGameTooltips(gameName[gameId], gameDescription[gameId]);

    return gameSlot;
}

GameSlot_t *getGameSlotById(int gameId)
{

    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();
    GameSlotList_t *gameSlotList = sceneMenuChooseGame->gameSlotList;

    if (gameId < 0 || gameId > GAME_MAX) return sceneMenuChooseGame->emptySlot;
    while (gameSlotList != NULL) {
        if (gameSlotList->gameSlot->id == gameId)
            return gameSlotList->gameSlot;
        gameSlotList = gameSlotList->next;
    }
    return NULL;
}
