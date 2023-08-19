/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** MenuChooseGame.h
*/

#ifndef MAP_SCENE_H_
    #define MAP_SCENE_H_

/*=========================== INCLUDE ========================*/


//General Include

//Personal Include


/*==================== STRUCTURE =====================*/


    typedef struct structSceneConfig {
        void (*renderFunction)(void);
        void (*loadSceneElement)(void);
        void (*destroySceneElement)(void);
        int sceneId;
    } SceneConfig_t;

    typedef struct structSceneMap {
        SceneConfig_t *sceneConfig;
        struct structSceneMap *next;
    } SceneMap_t;


/*==================== ENUM ====================*/


/*==================== FUNCTION ====================*/


        // Scene Menu Choose Game
    void loadSceneMenuChooseGame(void);
    void renderSceneMenuChooseGame(void);
    void destroySceneMenuChooseGame(void);


/*==================== MACRO ====================*/


#endif /*MAP_SCENE_H_*/

