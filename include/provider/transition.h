/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** transition.h
*/

#ifndef TRANSITION_H_
    #define TRANSITION_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include
    #include "scene.h"


/*==================== ENUM ====================*/


    typedef enum TRANSITION_STATE{
        TRANSITION_STATE_OUT = -1,
        TRANSITION_STATE_NONE = 0,
        TRANSITION_STATE_IN = 1
    } TRANSITION_STATE_E;


/*==================== STRUCTURE =====================*/


    // Transition
        typedef struct structTransition {
            sfRectangleShape *transitionRectangle;
            sfClock *transitionClock;
            int opacity;
            TRANSITION_STATE_E transitionState;
            SCENE_E nextScene;
        } Transition_t;


/*==================== FUNCTION ====================*/


    // transition
        void initTransitionStruct(void);
        void destroyTransitionStruct(void);
        Transition_t *getTransitionStruct(void);


/*==================== MACRO ====================*/


#endif /*TRANSITION_H_*/