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
        SCENE_MENU_SETTINGS,
        SCENE_MENU_STATS,
        SCENE_GAME_PACMAN,
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


/*==================== FUNCTION ====================*/


    // Scene Config
        SceneConfig_t *createSceneConfigById(SCENE_E sceneId);
        void destroySceneConfig(SceneConfig_t *sceneConfig);

    // Scene Map
        void initSceneMapStruct(void);
        void destroySceneMapStruct(void);


/*==================== MACRO ====================*/

    #define SCENE_GAME_START SCENE_GAME_PACMAN

#endif /*MAP_SCENE_H_*/
