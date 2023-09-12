/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** menuChooseGame.h
*/

#ifndef MENU_CHOOSE_GAME_H_
    #define MENU_CHOOSE_GAME_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include
    #include "gameSlot.h"
    #include "provider/button.h"


/*==================== ENUM ====================*/


/*==================== STRUCTURE =====================*/


    typedef struct structSceneMenuChooseGame {
        bool asNext;
        bool asPrevious;
        int currentSlotId;
        sfRectangleShape *background;
        sfConvexShape *backgroundMenu;
        GameSlotList_t *gameSlotList;
        GameSlot_t *emptySlot;
        Button_t *exitButton;
        Button_t *settingsButton;
        Button_t *statsButton;
        Button_t *leftArrowButton;
        Button_t *rightArrowButton;
    } SceneMenuChooseGame_t;


/*==================== FUNCTION ====================*/


    // Scene Menu Choose Game
        void loadSceneMenuChooseGame(void);
        void renderSceneMenuChooseGame(void);
        void destroySceneMenuChooseGame(void);
        void eventManagerSceneMenuChooseGame(void);
        SceneMenuChooseGame_t *getSceneMenuChooseGameStruct(void);


/*==================== MACRO ====================*/


#endif /*MENU_CHOOSE_GAME_H_*/