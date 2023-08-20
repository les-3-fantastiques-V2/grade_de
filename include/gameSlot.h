/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** gameSlot.h
*/

#ifndef GAME_SLOT_H
    #define GAME_SLOT_H

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include
    #include "gradeDe.h"


/*==================== STRUCTURE =====================*/


    typedef struct structGameSlot {
        int id;
        char *name;
        char *description;
        sfRectangleShape *icon;
    } GameSlot_t;

    typedef struct structGameSlotList {
        GameSlot_t *gameSlot;
        struct structGameSlotList *next;
    } GameSlotList_t;


/*==================== ENUM ====================*/


/*==================== FUNCTION ====================*/


/*==================== MACRO ====================*/

    #define GAME_SLOT_WIDTH 250
    #define GAME_SLOT_HEIGHT 150

#endif /*GAME_SLOT_H*/