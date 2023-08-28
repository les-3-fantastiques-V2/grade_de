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


/*==================== ENUM ====================*/


    typedef enum GAME {
        NO_GAME = -1,
        GAME_TESTING,
        GAME_EMPTY,
        GAME_ABC,
        GAME_RUNNER,
        GAME_MAX,
    } GAME_E;


/*==================== STRUCTURE =====================*/


    typedef struct structGameTooltips {
        sfVector2f originBackgroundPosition;
        sfVector2f originNamePosition;
        sfVector2f originDescriptionPosition;
        sfRectangleShape *background;
        sfTexture *backgroundTexture;
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


/*==================== FUNCTION ====================*/


        // Game Slot
    void destroyGameSlot(GameSlot_t *gameSlot);
    GAME_E getGameSlotIdByMousePosition();
    GameSlot_t *createEmptyGameSlot();
    GameSlot_t *getGameSlotById(GAME_E gameId);
    GameSlot_t *createGameSlotById(GAME_E gameId);

        // Game Slot List
    void initGameSlotListStruct(void);
    void destroyGameSlotListStruct(void);

        // Game ToolTips
    void renderTooltips(GameTooltips_t *gameTooltips);
    void destroyGameTooltips(GameTooltips_t *gameTooltips);
    GameTooltips_t *createGameTooltips(char *name, char *description);


/*==================== MACRO ====================*/


    #define GAME_SLOT_WIDTH 250
    #define GAME_SLOT_HEIGHT 150


#endif /*GAME_SLOT_H_*/