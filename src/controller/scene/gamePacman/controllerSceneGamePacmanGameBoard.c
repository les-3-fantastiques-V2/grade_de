/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneGamePacmanGameBoard.c
*/

#include "gradeDe.h"

static sfTexture *_getTextureForCell(sfVector2i coord, int **mapWalls, sfVector2i mapSize)
{
    if (mapWalls[coord.y][coord.x] == PACMAN_MAP_WALL) {
        createWallTexture(coord, mapWalls, mapSize);
        return sfTexture_createFromFile("assets/games/Pacman/wall.png", NULL);
    }

    return sfTexture_createFromFile("assets/games/Pacman/empty.png", NULL);
}

static void _freeCell(PacmanGameBoardCell_t *cell)
{
    sfRectangleShape_destroy(cell->cell);
    sfTexture_destroy(cell->texture);
    free(cell);
}

static void _addCell(PacmanGameBoardCell_t **cell, sfVector2i position, sfVector2i coord, int **mapWalls, sfVector2i mapSize)
{
    PacmanGameBoardCell_t *newCell = malloc(sizeof(PacmanGameBoardCell_t));
    newCell->coord = coord;
    newCell->position = position;
    newCell->isWall = mapWalls[coord.y][coord.x] == -1;

    newCell->texture = _getTextureForCell(coord, mapWalls, mapSize);
    newCell->cell = createRectangleShape((sfVector2f){20, 20}, sfWhite, (sfVector2f){position.x, position.y});
    sfRectangleShape_setTexture(newCell->cell, newCell->texture, sfTrue);
    newCell->next = NULL;

    if (*cell == NULL) {
        *cell = newCell;
        return;
    }
    PacmanGameBoardCell_t *tmp = *cell;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = newCell;
}

static void _destroyCell(PacmanGameBoardCell_t *cell)
{
    while (cell != NULL) {
        PacmanGameBoardCell_t *tmp = cell;
        cell = cell->next;
        _freeCell(tmp);
    }
}

static void _createCell(PacmanGameBoard_t *gameBoard)
{
    gameBoard->cell = NULL;
    for (int i = 0; i < gameBoard->mapSize.y; i++) {
        for (int j = 0; j < gameBoard->mapSize.x; j++) {
            _addCell(
                &gameBoard->cell,
                (sfVector2i){
                    j * 20 + gameBoard->mapMargin.x,
                    i * 20 + gameBoard->mapMargin.y
                },
                (sfVector2i){j, i},
                gameBoard->mapWalls,
                gameBoard->mapSize
            );
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
    // gameBoard->mapSize = (sfVector2i){13, 13};
    gameBoard->mapMargin = (sfVector2f){
        percent(WINDOW_WIDTH, 96) / 2 - gameBoard->mapSize.x * 20 / 2 + percent(WINDOW_WIDTH, 2),
        percent(WINDOW_HEIGHT, 78) / 2 - gameBoard->mapSize.y * 20 / 2 + percent(WINDOW_HEIGHT, 4)
    };
    gameBoard->mapWalls = mazeImperfectGenerator(gameBoard->mapSize, 20);
    for (int x = 0; x < gameBoard->mapSize.x && gameBoard->mapWalls[gameBoard->mapSize.y / 2][x] == -1; x++)
        gameBoard->mapWalls[gameBoard->mapSize.y / 2][x] = PACMAN_MAP_WARP;
    for (int x = gameBoard->mapSize.x - 1; x > 0 && gameBoard->mapWalls[gameBoard->mapSize.y / 2][x] == -1; x--)
        gameBoard->mapWalls[gameBoard->mapSize.y / 2][x] = PACMAN_MAP_WARP;
    _createCell(gameBoard);

    sceneGamePacman->gameBoard = gameBoard;
}

void destroyPacmanGameBoard(void)
{
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();
    PacmanGameBoard_t *gameBoard = sceneGamePacman->gameBoard;

    _destroyCell(gameBoard->cell);
    for (int i = 0; i < gameBoard->mapSize.y; i++) free(gameBoard->mapWalls[i]);
    free(gameBoard);
}
