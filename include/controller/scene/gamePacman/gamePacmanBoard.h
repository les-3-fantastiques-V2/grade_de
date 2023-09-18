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


/*==================== STRUCTURE =====================*/


    typedef struct structPacmanGameBoardCell {
        sfVector2i position;
        sfRectangleShape *cell;
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