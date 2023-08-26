/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** gradeDe.h
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
    #include "cursor.h"
    #include "font.h"
    #include "gameSlot.h"
    #include "mapScene.h"
    #include "provider.h"
    #include "service.h"


/*==================== ENUM ====================*/


/*==================== STRUCTURE =====================*/


/*==================== FUNCTION ====================*/


    void sceneManager(void);
    void renderGameSlotList(void);
    void eventManager(SceneConfig_t *sceneConfig);


/*==================== MACRO ====================*/


#endif /*GRADE_DE_H_*/

