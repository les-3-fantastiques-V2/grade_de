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


/*==================== ENUM ====================*/


/*==================== STRUCTURE =====================*/


    typedef struct structSceneGamePacman {
        sfRectangleShape *background;
        sfConvexShape *backgroundGame;
        Button_t *backbutton;
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