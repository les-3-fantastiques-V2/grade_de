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
    sfConvexShape_destroy(gameSlot->iconBox);
    sfTexture_destroy(gameSlot->icon);
    destroyGameTooltips(gameSlot->tooltips);
    free(gameSlot);
}

GameSlot_t *createEmptyGameSlot()
{
    GameSlot_t *emptySlot = malloc(sizeof(GameSlot_t));
    emptySlot->id = -1;
    emptySlot->iconBox = createRoundedRectangle(GAME_SLOT_WIDTH, GAME_SLOT_HEIGHT, 40);
    emptySlot->icon = sfTexture_createFromFile("assets/games/Empty.png", NULL);
    sfConvexShape_setFillColor(emptySlot->iconBox, sfColor_fromRGB(150, 150, 150));
    emptySlot->tooltips = createGameTooltips("empty slot", "empty slot");

    return emptySlot;
}

GAME_E getGameSlotIdByMousePosition() {
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();
    GameSlotList_t *gameSlotList = sceneMenuChooseGame->gameSlotList;

    for (int j = 0; j < sceneMenuChooseGame->currentSlotId; j++) {
        if (gameSlotList == NULL) return NO_GAME;
        gameSlotList = gameSlotList->next;
    }
    for (int i = 0; i < 6; i++) {
        if (gameSlotList == NULL) break;
        sfVector2f slotPosition = sfConvexShape_getPosition(gameSlotList->gameSlot->iconBox);
        if (mouseIsOn(slotPosition, (sfVector2f){GAME_SLOT_WIDTH, GAME_SLOT_HEIGHT}))
            return gameSlotList->gameSlot->id;
        gameSlotList = gameSlotList->next;
    }

    return NO_GAME;
}

GameSlot_t *createGameSlotById(GAME_E gameId)
{
    GameSlot_t *gameSlot = malloc(sizeof(GameSlot_t));
    gameSlot->id = gameId;
    gameSlot->tooltips = createGameTooltips(gameName[gameId], gameDescription[gameId]);
    gameSlot->iconBox = createRoundedRectangle(GAME_SLOT_WIDTH, GAME_SLOT_HEIGHT, 40);

    char *gameIconPath = malloc(sizeof(char) * (strlen("assets/games/") + strlen(gameName[gameId]) + strlen(".png") + 1));
    strcpy(gameIconPath, "assets/games/");
    strcat(gameIconPath, gameName[gameId]);
    strcat(gameIconPath, ".png");
    gameSlot->icon = sfTexture_createFromFile(gameIconPath, NULL);
    sfConvexShape_setTexture(gameSlot->iconBox, gameSlot->icon, sfTrue);

    free(gameIconPath);
    return gameSlot;
}

GameSlot_t *getGameSlotById(GAME_E gameId)
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
