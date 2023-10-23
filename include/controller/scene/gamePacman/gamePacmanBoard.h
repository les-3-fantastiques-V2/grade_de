/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** gamePacmanBoard.h
*/

#ifndef GAME_PACMAN_BOARD_H_
    #define GAME_PACMAN_BOARD_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include


/*==================== ENUM ====================*/

    typedef enum PACMAN_MAP {
        PACMAN_MAP_WALL = -1,
        PACMAN_MAP_POINT = 0,
        PACMAN_MAP_EMPTY,
        PACMAN_MAP_WARP,
    } PACMAN_MAP_E;

/*==================== STRUCTURE =====================*/


    typedef struct structPacmanGameBoardCell {
        sfVector2i position;
        sfRectangleShape *cell;
        sfTexture *texture;
        bool isWall;
        sfVector2i coord;
        struct structPacmanGameBoardCell *next;
    } PacmanGameBoardCell_t;

    typedef struct structPacmanGameBoard {
        sfVector2i PacmanPosition;
        sfVector2i mapSize;
        sfVector2f mapMargin;
        int** mapWalls;
        PacmanGameBoardCell_t *cell;
    } PacmanGameBoard_t;


/*==================== FUNCTION ====================*/


    // Game Board
        void initPacmanGameBoard(void);
        void renderPacmanGameBoard(void);
        void destroyPacmanGameBoard(void);


/*==================== MACRO ====================*/


#endif /*GAME_PACMAN_BOARD_H_*/