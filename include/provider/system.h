/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** system.h
*/

#ifndef SYSTEM_H_
    #define SYSTEM_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include
    #include "provider/cursor.h"
    #include "provider/font.h"
    #include "provider/music.h"
    #include "provider/scene.h"
    #include "provider/sound.h"


/*==================== ENUM ====================*/


/*==================== STRUCTURE =====================*/


    // Config
        typedef struct linkedListConfiguration {
            char *name;
            char *value;
            struct linkedListConfiguration *next;
        } ConfigList_t;

        typedef struct structConfiguration {
            ConfigList_t *configList;
        } Config_t;


    // Grade De
        typedef struct structGradeDe {
            SceneMap_t *sceneMap;
            FontList_t *fontList;
            MouseCursor_t *mouseCursor;
            MusicPlayer_t *musicPlayer;
            SoundPlayer_t *soundPlayer;
            int currentSceneId;
            int exitStatus;
        } GradeDe_t;


    // Window Config
        typedef struct structWindowConfig {
            sfRenderWindow *window;
            sfVideoMode videoMode;
            char *name;
            unsigned int frameRate;
            sfEvent event;
            int brightness;
            sfRectangleShape *brightnessRectangle;
        } WindowConfig_t;


/*==================== FUNCTION ====================*/


    // Config
        void initConfig(void);
        void saveConfig(void);
        void destroyConfig(void);
        void setConfig(char *name, char *value);
        char *getConfigValueByName(char *name);
        Config_t *getConfig(void);

    // Grade De
        void initGradeDeStruct(void);
        int destroyGradeDeStruct(void);
        GradeDe_t *getGradeDeStruct(void);

    // Window Config
        void setFrameRate(int frameRate);
        void initWindowConfigStruct(void);
        void setBrightness(int brightness);
        void destroyWindowConfigStruct(void);
        WindowConfig_t *getWindowConfigStruct(void);


/*==================== MACRO ====================*/


#endif /*SYSTEM_H_*/