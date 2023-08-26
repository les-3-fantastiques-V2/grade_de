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


        // Grade De
    void initGradeDeStruct(void);
    int destroyGradeDeStruct(void);
    GradeDe_t *getGradeDeStruct(void);

        // Scene Config
    SceneConfig_t *createSceneConfigById(int sceneId);
    void destroySceneConfig(SceneConfig_t *sceneConfig);

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

