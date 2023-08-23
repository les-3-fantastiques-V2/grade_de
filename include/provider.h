/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** provider.h
*/

#ifndef PROVIDER_H_
    #define PROVIDER_H_

/*=========================== INCLUDE ========================*/


//General Include

//Personal Include
    #include "font.h"
    #include "gameSlot.h"
    #include "mapScene.h"


/*==================== STRUCTURE =====================*/


    typedef struct structWindowConfig {
        sfRenderWindow *window;
        sfVideoMode videoMode;
        char *name;
        unsigned int frameRate;
        sfEvent event;
    } WindowConfig_t;

    typedef struct structGradeDe {
        WindowConfig_t *windowConfig;
        SceneMap_t *sceneMap;
        FontList_t *fontList;
        int currentSceneId;
        int exitStatus;
    } GradeDe_t;


/*==================== ENUM ====================*/


/*==================== FUNCTION ====================*/


        // Font
    void destroyFont(Font_t *font);
    Font_t *getFontById(int fontId);
    Font_t *createFontById(int fontId);

        // Font List
    void initFontListStruct(void);
    void destroyFontListStruct(void);

        // Game Slot
    void destroyGameSlot(GameSlot_t *gameSlot);
    int getGameSlotIdByMousePosition();
    GameSlot_t *createEmptyGameSlot();
    GameSlot_t *getGameSlotById(int gameId);
    GameSlot_t *createGameSlotById(int gameId);

        // Game Slot List
    void initGameSlotListStruct(void);
    void destroyGameSlotListStruct(void);

        // Game ToolTips
    void renderTooltips(GameTooltips_t *gameTooltips);
    void destroyGameTooltips(GameTooltips_t *gameTooltips);
    GameTooltips_t *createGameTooltips(char *name, char *description);

        // Grade De
    void initGradeDeStruct(void);
    int destroyGradeDeStruct(void);
    GradeDe_t *getGradeDeStruct(void);

        // Scene Config
    SceneConfig_t *getSceneConfigById(int sceneId);

        // Scene Map
    void initSceneMapStruct(void);
    void destroySceneMapStruct(void);

        // Window Config
    void initWindowConfigStruct(void);
    void destroyWindowConfigStruct(void);
    WindowConfig_t *getWindowConfigStruct(void);


/*==================== MACRO ====================*/

    #define WINDOW_WIDTH 1280
    #define WINDOW_HEIGHT 720

#endif /*PROVIDER_H_*/

