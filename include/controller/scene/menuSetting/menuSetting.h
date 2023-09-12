/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** menuSetting.h
*/

#ifndef MENU_SETTING_H_
    #define MENU_SETTING_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include
    #include "settingsSections.h"
    #include "provider/button.h"


/*==================== ENUM ====================*/


/*==================== STRUCTURE =====================*/


    typedef struct structSceneMenuSettings {
        SETTINGS_SECTION_E currentSection;
        sfRectangleShape *background;
        sfConvexShape *backgroundMenu;
        Button_t *backButton;
        sfConvexShape *line;
        sfText *note;
        SettingsSoundSection_t *soundSection;
        SettingsVideoSection_t *videoSection;
        SettingsSaveSection_t *saveSection;
    } SceneMenuSettings_t;


/*==================== FUNCTION ====================*/


    // Scene Menu Settings
        void loadSceneMenuSettings(void);
        void renderSceneMenuSettings(void);
        void destroySceneMenuSettings(void);
        void eventManagerSceneMenuSettings(void);
        SceneMenuSettings_t *getSceneMenuSettingsStruct(void);


/*==================== MACRO ====================*/


#endif /*MENU_SETTING_H_*/