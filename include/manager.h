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

//Personal Include


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


#endif /*GRADE_DE_H_*/

