/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** settingsSection.c
*/

#ifndef SETTINGS_SECTIONS_H_
    #define SETTINGS_SECTIONS_H_

/*=========================== INCLUDE ========================*/


//General Include

//Personal Include

/*==================== ENUM ====================*/

    typedef enum SETTINGS_SECTION {
        SETTINGS_SECTION_SOUND,
        SETTINGS_SECTION_VIDEO,
    } SETTINGS_SECTION_E;


/*==================== STRUCTURE =====================*/

    typedef struct structSectionSound {
        sfText *title;
    } SettingsSoundSection_t;

    typedef struct structSectionVideo {
        sfText *title;
    } SettingsVideoSection_t;


/*==================== FUNCTION ====================*/

        // Settings Section
    void initSettingsSection(void);
    void renderSettingsSection(void);
    void destroySettingsSection(void);
    void changeSettingsSection(SETTINGS_SECTION_E section);

        // Sound Section
    void initSettingsSoundSection(void);
    void renderSettingsSoundSection(void);
    void destroySettingsSoundSection(void);

        // Video Section
    void initSettingsVideoSection(void);
    void renderSettingsVideoSection(void);
    void destroySettingsVideoSection(void);


/*==================== MACRO ====================*/


#endif /*SETTINGS_SECTIONS_H_*/

