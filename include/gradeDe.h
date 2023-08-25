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
    #include "font.h"


/*==================== STRUCTURE =====================*/


/*==================== ENUM ====================*/


    enum SCENE {
        EXIT = -1,
        SCENE_MENU_CHOOSE_GAME,
        SCENE_MAX,
    };

    enum GAME {
        GAME_TESTING,
        GAME_EMPTY,
        GAME_ABC,
        GAME_RUNNER,
        GAME_MAX,
    };


/*==================== FUNCTION ====================*/


    void eventManager(void);
    void sceneManager(void);
    void renderGameSlotList(void);
    void renderText(sfText *text);
    void renderCircleShape(sfCircleShape *circleShape);
    void renderRectangleShape(sfRectangleShape *rectangleShape);

    bool sceneIsOpen(int currentSceneId);
    bool mouseIsOn(sfVector2f position, sfVector2f size);

    int percent(int value, int percent);

    char *mergeCharToString(char *string, char c);
    char *mergeStringToString(char *string1, char *string2);
    char *splitText(char *text, int maxWidth, int fontSize, int fontId);

    char **stringToWordArray(char *string);

    sfCircleShape *createCircleShape(float radius, sfColor color, sfVector2f position);
    sfRectangleShape *createRectangleShape(sfVector2f size, sfColor color, sfVector2f position);
    sfText *createText(char *textContent, sfVector2f position, unsigned int fontSize, int fontId);


/*==================== MACRO ====================*/


#endif /*GRADE_DE_H_*/

