/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** gamePacman.h
*/

#ifndef GAME_PACMAN_H_
    #define GAME_PACMAN_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include
    #include "provider/button.h"
    #include "gamePacmanBoard.h"


/*==================== ENUM ====================*/


/*==================== STRUCTURE =====================*/

    typedef struct structSceneGamePacman {
        sfRectangleShape *background;
        sfConvexShape *backgroundGame;
        Button_t *backbutton;
        PacmanGameBoard_t *gameBoard;
    } SceneGamePacman_t;


/*==================== FUNCTION ====================*/


    // Scene Menu Choose Game
        void loadSceneGamePacman(void);
        void renderSceneGamePacman(void);
        void destroySceneGamePacman(void);
        void eventManagerSceneGamePacman(void);
        SceneGamePacman_t *getSceneGamePacmanStruct(void);


/*==================== MACRO ====================*/


#endif /*GAME_PACMAN_H_*/