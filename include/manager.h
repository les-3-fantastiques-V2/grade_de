/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** manager.h
*/

#ifndef MANAGER_H_
    #define MANAGER_H_

/*=========================== INCLUDE ========================*/


//General Include

//Personal Include
    #include "mapScene.h"


/*==================== ENUM ====================*/


/*==================== STRUCTURE =====================*/


/*==================== FUNCTION ====================*/


    // Event
        void eventManager(SceneConfig_t *sceneConfig);

    // Game Slot
        void renderGameSlotList(void);
        int getGameSlotPositionIdByMousePosition(void);

    // Scene
        void sceneManager(void);
        void changeScene(SCENE_E sceneId);


/*==================== MACRO ====================*/


#endif /*MANAGER_H_*/

