/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerGameSlotList.c
*/

#include "gradeDe.h"

static void _addGameSlot(GAME_E gameId, GameSlotList_t **gameSlotList)
{
    GameSlot_t *gameSlot = createGameSlotById(gameId);

    if (gameSlot == NULL) return;

    GameSlotList_t *newGameSlotList = malloc(sizeof(GameSlotList_t));
    newGameSlotList->gameSlot = gameSlot;
    newGameSlotList->next = *gameSlotList;
    *gameSlotList = newGameSlotList;
}

void initGameSlotListStruct(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();
    GameSlotList_t *gameSlotList = NULL;

    for (int i = 0; i < GAME_MAX; i++) {
        _addGameSlot(i, &gameSlotList);
    }

    sceneMenuChooseGame->gameSlotList = gameSlotList;
    sceneMenuChooseGame->emptySlot = createEmptyGameSlot();
}

void destroyGameSlotListStruct(void)
{
    SceneMenuChooseGame_t *sceneMenuChooseGame = getSceneMenuChooseGameStruct();

    while (sceneMenuChooseGame->gameSlotList != NULL) {
        GameSlotList_t *next = sceneMenuChooseGame->gameSlotList->next;
        free(sceneMenuChooseGame->gameSlotList);
        sceneMenuChooseGame->gameSlotList = next;
    }
}
