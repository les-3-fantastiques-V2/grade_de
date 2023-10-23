/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneGamePacmanWallBuilder.c
*/

#include "gradeDe.h"

static void _mergeTileWall(sfImage *newWall, sfImage **wallsImages, int type)
{
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            sfColor color = sfImage_getPixel(wallsImages[type], i, j);
            if (color.a != sfTransparent.a)
                sfImage_setPixel(newWall, i, j, color);
        }
    }
}

static bool *_getWalls(sfVector2i coord, int **mapWalls, sfVector2i mapSize)
{
    bool *walls = malloc(sizeof(bool) * 4);
    for (int i = 0; i < 4; i++) walls[i] = false;

    if (coord.y > 0) walls[0] = mapWalls[coord.y - 1][coord.x] == PACMAN_MAP_WALL;
    if (coord.x < mapSize.x - 1) walls[1] = mapWalls[coord.y][coord.x + 1] == PACMAN_MAP_WALL;
    if (coord.y < mapSize.y - 1) walls[2] = mapWalls[coord.y + 1][coord.x] == PACMAN_MAP_WALL;
    if (coord.x > 0) walls[3] = mapWalls[coord.y][coord.x - 1] == PACMAN_MAP_WALL;

    return walls;
}

void createWallTexture(sfVector2i coord, int **mapWalls, sfVector2i mapSize)
{
    sfImage *newWall = sfImage_createFromFile("assets/games/Pacman/wallCenter.png");
    sfImage **wallsImages = malloc(sizeof(sfImage *) * 4);
    wallsImages[0] = sfImage_createFromFile("assets/games/Pacman/wallNorth.png");
    wallsImages[1] = sfImage_createFromFile("assets/games/Pacman/wallEast.png");
    wallsImages[2] = sfImage_createFromFile("assets/games/Pacman/wallSouth.png");
    wallsImages[3] = sfImage_createFromFile("assets/games/Pacman/wallWest.png");
    bool *walls = _getWalls(coord, mapWalls, mapSize);

    for (int i = 0; i < 4; i++)
        if (walls[i])
            _mergeTileWall(newWall, wallsImages, i);

    free(walls);
    for (int i = 0; i < 4; i++) sfImage_destroy(wallsImages[i]);
    free(wallsImages);
    sfImage_saveToFile(newWall, "assets/games/Pacman/wall.png");
    sfImage_destroy(newWall);
}
