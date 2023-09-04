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

    typedef enum PLUS_MINUS_VALUES {
        PLUS_MINUS_VALUE,
        PLUS_MINUS_MIN,
        PLUS_MINUS_MAX,
        PLUS_MINUS_STEP,
    } PLUS_MINUS_VALUES_E;

    typedef enum SETTINGS_SECTION {
        SETTINGS_SECTION_SOUND,
        SETTINGS_SECTION_VIDEO,
    } SETTINGS_SECTION_E;


/*==================== STRUCTURE =====================*/

    typedef struct structPlusMinus {
        int value;
        int minValue;
        int maxValue;
        int step;
        sfText *title;
        sfText *valueText;
        Button_t *plus;
        Button_t *minus;
        void (*update)(void);
        sfClock *clickCooldown;
    } PlusMinus_t;

    typedef struct structSectionSound {
        sfText *title;
        PlusMinus_t *musicGestion;
        PlusMinus_t *soundGestion;
    } SettingsSoundSection_t;

    typedef struct structSectionVideo {
        sfText *title;
        PlusMinus_t *frameRateGestion;
        PlusMinus_t *brightnessGestion;
    } SettingsVideoSection_t;


/*==================== FUNCTION ====================*/

        // Plus Minus
    void renderPlusMinus(PlusMinus_t *plusMinus);
    void destroyPlusMinus(PlusMinus_t *plusMinus);
    PlusMinus_t *initPlusMinusStruct(char *title, int *values, sfVector2f position, void (*update)(void));

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

