/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerGameSlot.c
*/

#include "gradeDe.h"

char *gameName[GAME_MAX] = {
    "Pacman",
};

char *gameDescription[GAME_MAX] = {
    "Try to escape the ghost as long as possible !",
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
    emptySlot->iconBox = createRoundedRectangle(
        (sfVector3f) {GAME_SLOT_WIDTH, GAME_SLOT_HEIGHT, 40},
        sfWhite,
        (sfVector2f) {0, 0}
    );
    sfConvexShape_setOutlineColor(emptySlot->iconBox, (sfColor){255, 165, 66, 255});
    sfConvexShape_setOutlineThickness(emptySlot->iconBox, 2);
    emptySlot->icon = sfTexture_createFromFile("assets/games/Empty.png", NULL);
    sfConvexShape_setTexture(emptySlot->iconBox, emptySlot->icon, sfTrue);
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
    gameSlot->iconBox = createRoundedRectangle(
        (sfVector3f) {GAME_SLOT_WIDTH, GAME_SLOT_HEIGHT, 40},
        sfWhite,
        (sfVector2f) {0, 0}
    );

    char *gameIconPath = malloc(sizeof(char) * (strlen("assets/games/") + strlen(gameName[gameId]) + strlen(".png") + 1));
    strcpy(gameIconPath, "assets/games/");
    strcat(gameIconPath, gameName[gameId]);
    strcat(gameIconPath, ".png");
    gameSlot->icon = sfTexture_createFromFile(gameIconPath, NULL);
    sfConvexShape_setTexture(gameSlot->iconBox, gameSlot->icon, sfTrue);
    sfConvexShape_setOutlineColor(gameSlot->iconBox, (sfColor){255, 165, 66, 255});
    sfConvexShape_setOutlineThickness(gameSlot->iconBox, 2);

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
