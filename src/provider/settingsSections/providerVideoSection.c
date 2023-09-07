/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerVideoSection.c
*/

#include "gradeDe.h"

static void _callbackPressed(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    changeSettingsSection(SETTINGS_SECTION_VIDEO);
    sfText_setFillColor(sceneMenuSettings->videoSection->title, (sfColor){255, 165, 66, 255});
}

static void _callbackHover(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_setFillColor(sceneMenuSettings->videoSection->title, (sfColor){255, 165, 66, 150});
}

static void _callbackDefault(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_setFillColor(sceneMenuSettings->videoSection->title, sfBlack);
}

static void _frameRateGestion(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    setFrameRate(sceneMenuSettings->videoSection->frameRateGestion->value);
}

static void _brightnessGestion(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    setBrightness(sceneMenuSettings->videoSection->brightnessGestion->value);
}



void _renderSettingsVideoSectionContent(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    renderPlusMinus(sceneMenuSettings->videoSection->frameRateGestion);
    renderPlusMinus(sceneMenuSettings->videoSection->brightnessGestion);
}

void renderSettingsVideoSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    if (sceneMenuSettings->currentSection == SETTINGS_SECTION_VIDEO) {
        renderText(sceneMenuSettings->videoSection->title);
        _renderSettingsVideoSectionContent();
    } else {
        renderTextWithAllCallbacks(sceneMenuSettings->videoSection->title, &_callbackPressed, &_callbackHover, &_callbackDefault);
    }
}

void initSettingsVideoSection(void)
{
    WindowConfig_t *winConfig = getWindowConfigStruct();
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();
    SettingsVideoSection_t *videoSection = malloc(sizeof(SettingsVideoSection_t));

    videoSection->title = createText("Video", (sfVector2f){100, 200}, 50, FONT_SPICY_PIZZA);
    int *values = malloc(sizeof(int) * 4);
    values[PLUS_MINUS_VALUE] = winConfig->frameRate;
    values[PLUS_MINUS_MIN] = 12;
    values[PLUS_MINUS_MAX] = 120;
    values[PLUS_MINUS_STEP] = 12;

    videoSection->frameRateGestion = initPlusMinusStruct(
        "FrameRate",
        values,
        (sfVector2f){400, 100},
        &_frameRateGestion
    );
    values[PLUS_MINUS_VALUE] = winConfig->brightness;
    values[PLUS_MINUS_MIN] = 20;
    values[PLUS_MINUS_MAX] = 100;
    values[PLUS_MINUS_STEP] = 1;
    videoSection->brightnessGestion = initPlusMinusStruct(
        "Brightness",
        values,
        (sfVector2f){400, 200},
        &_brightnessGestion
    );


    sceneMenuSettings->videoSection = videoSection;
}

void destroySettingsVideoSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_destroy(sceneMenuSettings->videoSection->title);
    destroyPlusMinus(sceneMenuSettings->videoSection->frameRateGestion);
    destroyPlusMinus(sceneMenuSettings->videoSection->brightnessGestion);
    free(sceneMenuSettings->videoSection);
}
