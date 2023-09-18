/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerMazeGenerator.c
*/

#include "gradeDe.h"

static int **_getInitialMaze(sfVector2i mazeSize)
{
    int **mapWalls = malloc(sizeof(int *) * mazeSize.y);
    for (int i = 0; i < mazeSize.y; i++) {
        mapWalls[i] = malloc(sizeof(int) * mazeSize.x);
        for (int j = 0; j < mazeSize.x; j++)
            mapWalls[i][j] = -1;
    }

    return mapWalls;
}

static int _getRandomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

static int **_buildMaze(int **maze, sfVector2i position, sfVector2i mazeSize)
{
    bool ok = true;

    while (ok) {
        int *directions = malloc(sizeof(int) * 4); ok = false;
        directions[0] = position.y - 2 > 0 && maze[position.y - 2][position.x];
        directions[1] = position.x + 2 < mazeSize.x && maze[position.y][position.x + 2];
        directions[2] = position.y + 2 < mazeSize.y && maze[position.y + 2][position.x];
        directions[3] = position.x - 2 > 0 && maze[position.y][position.x - 2];

        for (int i = 0; i < 4; i++) if (directions[i]) ok = true;

        if (!ok) break;

        int direction = _getRandomNumber(0, 3);
        while (!directions[direction]) direction = _getRandomNumber(0, 3);

        if (direction == 0) {
            maze[position.y - 1][position.x] = 0;
            maze[position.y - 2][position.x] = 0;
            position.y -= 2;
            directions[0] = false;
        }
        if (direction == 1) {
            maze[position.y][position.x + 1] = 0;
            maze[position.y][position.x + 2] = 0;
            position.x += 2;
            directions[1] = false;
        }
        if (direction == 2) {
            maze[position.y + 1][position.x] = 0;
            maze[position.y + 2][position.x] = 0;
            position.y += 2;
            directions[2] = false;
        }
        if (direction == 3) {
            maze[position.y][position.x - 1] = 0;
            maze[position.y][position.x - 2] = 0;
            position.x -= 2;
            directions[3] = false;
        }

        maze = _buildMaze(maze, position, mazeSize);
    }

    return maze;
}

int **mazePerfectGenerator(sfVector2i mazeSize)
{
    int **maze = _getInitialMaze(mazeSize);

    maze[1][1] = 0;
    maze = _buildMaze(maze, (sfVector2i){1, 1}, mazeSize);

    return maze;
}

int **mazeImperfectGenerator(sfVector2i mazeSize, int percentage)
{
    int **maze = mazePerfectGenerator(mazeSize);

    int count = 0;
    for (int y = 1; y < mazeSize.y - 1; y++) {
        for (int x = 1; x < mazeSize.x - 1; x++) {
            if (maze[y][x] == -1) {
                int block = 0;
                if (maze[y - 1][x] == -1 && maze[y + 1][x] == -1) block++;
                if (maze[y][x - 1] == -1 && maze[y][x + 1] == -1) block++;
                count += block == 1;
            }
        }
    }

    int toRemove = (count * percentage) / 100;

    while (toRemove > 0) {
        int x = _getRandomNumber(1, mazeSize.x - 2);
        int y = _getRandomNumber(1, mazeSize.y - 2);

        if (maze[y][x] == -1) {
            int block = 0;
            if (maze[y - 1][x] == -1 && maze[y + 1][x] == -1) block++;
            if (maze[y][x - 1] == -1 && maze[y][x + 1] == -1) block++;
            if (block == 1) {
                maze[y][x] = 0;
                toRemove--;
            }
        }
    }

    return maze;
}

// int block = 0;
// if (maze[y - 1][x] == -1 && maze[y + 1][x] == -1)
//     if (maze[y][x - 1] == 0 && maze[y][x + 1] == 0)
//         block++;
// if (maze[y][x - 1] == -1 && maze[y][x + 1] == -1)
//     if (maze[y - 1][x] == 0 && maze[y + 1][x] == 0)
//         block++;
