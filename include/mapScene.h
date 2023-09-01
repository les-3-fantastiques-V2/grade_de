/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** mapScene.h
*/

#ifndef MAP_SCENE_H_
    #define MAP_SCENE_H_

/*=========================== INCLUDE ========================*/


//General Include

//Personal Include


/*==================== ENUM ====================*/


    typedef enum SCENE {
        EXIT = -1,
        SCENE_MENU_CHOOSE_GAME,
        SCENE_MAX,
    } SCENE_E;


/*==================== STRUCTURE =====================*/


    typedef struct structSceneConfig {
        void (*renderFunction)(void);
        void (*loadSceneElement)(void);
        void (*eventSceneManager)(void);
        void (*destroySceneElement)(void);
        SCENE_E sceneId;
    } SceneConfig_t;

    typedef struct structSceneMap {
        SceneConfig_t *sceneConfig;
        struct structSceneMap *next;
    } SceneMap_t;


    typedef struct structSceneMenuChooseGame {
        bool asNext;
        bool asPrevious;
        int currentSlotId;
        sfRectangleShape *background;
        sfConvexShape *backgroundMenu;
        GameSlotList_t *gameSlotList;
        GameSlot_t *emptySlot;
        Button_t *exitButton;
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


#endif /*MAP_SCENE_H_*/
