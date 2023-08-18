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


/*==================== STRUCTURE =====================*/


    typedef struct structWindowConfig {
        sfRenderWindow *window;
        sfVideoMode videoMode;
        char *name;
        unsigned int frameRate;
        sfEvent event;
    } WindowConfig_t;

    typedef struct structSceneConfig {
        void (*renderFunction)(void);
        void (*loaderSceneElement)(void);
        int sceneId;
    } SceneConfig_t;

    typedef struct structGradeDe {
        WindowConfig_t *windowConfig;
        int currentScene;
        int exitStatus;
    } GradeDe_t;


/*==================== ENUM ====================*/


    enum SCENE {
        EXIT = -1,
        SCENE_MENU_CHOOSE_GAME,
    };


/*==================== FUNCTION ====================*/


    void eventManager(void);
    void sceneManager(void);
    void initGradeDeStruct(void);
    void sceneMenuChooseGame(void);
    void initWindowConfigStruct(void);
    void destroyWindowConfigStruct(void);

    bool sceneIsOpen(int currentSceneId);

    int destroyGradeDeStruct(void);

    GradeDe_t *getGradeDeStruct(void);
    WindowConfig_t *getWindowConfigStruct(void);


/*==================== MACRO ====================*/


#endif /*GRADE_DE_H_*/

