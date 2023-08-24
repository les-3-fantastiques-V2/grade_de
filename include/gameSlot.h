/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** gameSlot.h
*/

#ifndef GAME_SLOT_H_
    #define GAME_SLOT_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include
    #include "gradeDe.h"


/*==================== STRUCTURE =====================*/


    typedef struct structGameTooltips {
        sfVector2f originBackgroundPosition;
        sfVector2f originNamePosition;
        sfVector2f originDescriptionPosition;
        sfRectangleShape *background;
        sfText *name;
        sfText *description;
    } GameTooltips_t;

    typedef struct structGameSlot {
        int id;
        sfRectangleShape *icon;
        GameTooltips_t *tooltips;
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

#endif /*GAME_SLOT_H_*/