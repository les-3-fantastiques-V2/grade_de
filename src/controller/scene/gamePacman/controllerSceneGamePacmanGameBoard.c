/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneGamePacmanGameBoard.c
*/

#include "gradeDe.h"

static void _addCell(PacmanGameBoardCell_t **cell, int x, int y, int isWall)
{
    PacmanGameBoardCell_t *newCell = malloc(sizeof(PacmanGameBoardCell_t));
    newCell->position = (sfVector2i){x, y};
    newCell->cell = createRectangleShape((sfVector2f){20, 20}, (isWall == -1) ? sfWhite : sfBlack, (sfVector2f){x, y});
    newCell->next = NULL;

    if (*cell == NULL) {
        *cell = newCell;
        return;
    }
    PacmanGameBoardCell_t *tmp = *cell;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = newCell;
}

static void _createCell(PacmanGameBoard_t *gameBoard)
{
    gameBoard->cell = NULL;
    for (int i = 0; i < gameBoard->mapSize.y; i++) {
        for (int j = 0; j < gameBoard->mapSize.x; j++) {
            _addCell(&gameBoard->cell, j * 20 + gameBoard->mapMargin.x, i * 20 + gameBoard->mapMargin.y, gameBoard->mapWalls[i][j]);
        }
    }
}

/* System */

static void _renderBoard(PacmanGameBoardCell_t *cell)
{
    while (cell != NULL) {
        renderRectangleShape(cell->cell);
        cell = cell->next;
    }
}

void renderPacmanGameBoard(void)
{
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();

    _renderBoard(sceneGamePacman->gameBoard->cell);
}

void initPacmanGameBoard(void)
{
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();

    PacmanGameBoard_t *gameBoard = malloc(sizeof(PacmanGameBoard_t));
    gameBoard->PacmanPosition = (sfVector2i){0, 0};
    gameBoard->mapSize = (sfVector2i){57, 23};
    gameBoard->mapMargin = (sfVector2f){
        percent(WINDOW_WIDTH, 96) / 2 - gameBoard->mapSize.x * 20 / 2 + percent(WINDOW_WIDTH, 2),
        percent(WINDOW_HEIGHT, 78) / 2 - gameBoard->mapSize.y * 20 / 2 + percent(WINDOW_HEIGHT, 4)
    };
    gameBoard->mapWalls = mazeImperfectGenerator(gameBoard->mapSize, 20);
    _createCell(gameBoard);

    sceneGamePacman->gameBoard = gameBoard;
}

void destroyPacmanGameBoard(void)
{
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();
    PacmanGameBoard_t *gameBoard = sceneGamePacman->gameBoard;

    for (int i = 0; i < gameBoard->mapSize.y; i++) free(gameBoard->mapWalls[i]);
    free(gameBoard);
}
