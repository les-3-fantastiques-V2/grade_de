/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneGamePacmanPlayer.c
*/

#include "gradeDe.h"

static bool _isOnWarpCase(void)
{
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();
    GamePacmanPlayer_t *player = sceneGamePacman->player;

    if (player->coord.x % 20 != 0 || player->coord.y % 20 != 0) return false;
    if (sceneGamePacman->gameBoard->mapWalls[player->coord.y / 20][player->coord.x / 20] != PACMAN_MAP_WARP) return false;

    sfVector2i warpCoord[2] = {(sfVector2i){0, 0}, (sfVector2i){0, 0}};
    int i = 0;
    for (int y = 0; y < sceneGamePacman->gameBoard->mapSize.y; y++) {
        for (int x = 0; x < sceneGamePacman->gameBoard->mapSize.x; x++) {
            if (sceneGamePacman->gameBoard->mapWalls[y][x] == PACMAN_MAP_WARP) {
                warpCoord[i] = (sfVector2i){x, y}; i++;
            }
        }
    }

    sfVector2i newCoord = {0, 0};
    if (player->coord.x == warpCoord[0].x * 20 && player->coord.y == warpCoord[0].y * 20) {
        newCoord.x = (warpCoord[1].x * 20 - 1) - player->coord.x;
        newCoord.y = (warpCoord[1].y * 20) - player->coord.y;
    } else {
        newCoord.x = (warpCoord[0].x * 20 + 1) - player->coord.x;
        newCoord.y = (warpCoord[0].y * 20) - player->coord.y;
    }

    player->coord.x += newCoord.x; player->position.x += newCoord.x;
    player->coord.y += newCoord.y; player->position.y += newCoord.y;
    sfRectangleShape_setPosition(player->player, player->position);
    return true;
}

static bool _directionIsPossible(PACMAN_PLAYER_DIRECTION_E direction, sfVector2i coord)
{
    bool isPossible = false;
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();

    sfVector2i coordToTest = (sfVector2i){coord.x, coord.y};
    if (direction == PLAYER_PACMAN_DIRECTION_UP) coordToTest.y -= 1;
    if (direction == PLAYER_PACMAN_DIRECTION_RIGHT) coordToTest.x += 20;
    if (direction == PLAYER_PACMAN_DIRECTION_DOWN) coordToTest.y += 20;
    if (direction == PLAYER_PACMAN_DIRECTION_LEFT) coordToTest.x -= 1;
    sfVector2i coordRatio = (sfVector2i){coordToTest.x / 20, coordToTest.y / 20};

    isPossible = sceneGamePacman->gameBoard->mapWalls[coordRatio.y][coordRatio.x] != -1;
    if (coordToTest.x % 20 != 0) {
        if (direction == PLAYER_PACMAN_DIRECTION_UP || direction == PLAYER_PACMAN_DIRECTION_DOWN) {
            isPossible = false;
        }
    }
    if (coordToTest.y % 20 != 0) {
        if (direction == PLAYER_PACMAN_DIRECTION_RIGHT || direction == PLAYER_PACMAN_DIRECTION_LEFT) {
            isPossible = false;
        }
    }

    return isPossible;
}

static void updatePacmanGamePlayer(void)
{
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();
    GamePacmanPlayer_t *player = sceneGamePacman->player;
    float time = getTime(sceneGamePacman->player->movingClock);
    if (time < 0.007) return;
    resetTime(sceneGamePacman->player->movingClock);
    if (_isOnWarpCase()) return;
    if (player->direction == PLAYER_PACMAN_DIRECTION_NONE) player->direction = player->nextDirection;
    if (player->nextDirection != PLAYER_PACMAN_DIRECTION_NONE) {
        if (_directionIsPossible(player->nextDirection, player->coord)) {
            player->direction = player->nextDirection;
            player->nextDirection = PLAYER_PACMAN_DIRECTION_NONE;
        }
    }

    if (_directionIsPossible(player->direction, player->coord)) {
        sfVector2i newCoord = {0, 0};
        if (player->direction == PLAYER_PACMAN_DIRECTION_UP) newCoord.y -= 1;
        if (player->direction == PLAYER_PACMAN_DIRECTION_RIGHT) newCoord.x += 1;
        if (player->direction == PLAYER_PACMAN_DIRECTION_DOWN) newCoord.y += 1;
        if (player->direction == PLAYER_PACMAN_DIRECTION_LEFT) newCoord.x -= 1;
        player->coord.x += newCoord.x; player->position.x += newCoord.x;
        player->coord.y += newCoord.y; player->position.y += newCoord.y;
        sfRectangleShape_setPosition(player->player, player->position);
    }
}

static sfVector2f _initPacmanPlayerPosition(PacmanGameBoardCell_t *cell)
{
    for (; cell != NULL; cell = cell->next) {
        if (cell->isWall == false) {
            return (sfVector2f){cell->position.x, cell->position.y};
        }
    }
    return (sfVector2f){0, 0};
}


/* System */

void eventPacmanGamePlayer(void)
{
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();

    int key[PLAYER_PACMAN_DIRECTION_NONE] = {
        sfKeyUp,
        sfKeyRight,
        sfKeyDown,
        sfKeyLeft
    };

    for (int i = 0; i < PLAYER_PACMAN_DIRECTION_NONE; i++) {
        if (sfKeyboard_isKeyPressed(key[i])) {
            sceneGamePacman->player->nextDirection = i;
            return;
        }
    }
}

void renderPacmanGamePlayer(void)
{
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();

    updatePacmanGamePlayer();
    renderRectangleShape(sceneGamePacman->player->player);
}

void initPacmanGamePlayer(void)
{
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();
    GamePacmanPlayer_t *player = malloc(sizeof(GamePacmanPlayer_t));

    player->coord = (sfVector2i){20, 20};
    player->position = _initPacmanPlayerPosition(sceneGamePacman->gameBoard->cell);
    player->direction = PLAYER_PACMAN_DIRECTION_NONE;
    player->nextDirection = PLAYER_PACMAN_DIRECTION_NONE;
    player->player = createRectangleShape(
        (sfVector2f){20, 20},
        (sfColor){255, 255, 255, 255},
        player->position
    );
    player->movingClock = sfClock_create();

    sceneGamePacman->player = player;
}

void destroyPacmanGamePlayer(void)
{
    SceneGamePacman_t *sceneGamePacman = getSceneGamePacmanStruct();

    sfClock_destroy(sceneGamePacman->player->movingClock);
    sfRectangleShape_destroy(sceneGamePacman->player->player);
    free(sceneGamePacman->player);
}
