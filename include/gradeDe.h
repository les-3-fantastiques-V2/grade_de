/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** MenuChooseGame.h
*/

#ifndef GRADE_DE_H_
    #define GRADE_DE_H_

/*=========================== INCLUDE ========================*/


//General Include
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>

//Personal Include
    #include "mapScene.h"
    #include "provider.h"


/*==================== STRUCTURE =====================*/


/*==================== ENUM ====================*/


    enum SCENE {
        EXIT = -1,
        SCENE_MENU_CHOOSE_GAME,
        SCENE_MAX,
    };


/*==================== FUNCTION ====================*/


    void eventManager(void);
    void sceneManager(void);

    bool sceneIsOpen(int currentSceneId);


/*==================== MACRO ====================*/


#endif /*GRADE_DE_H_*/

