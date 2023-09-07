/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerSoundSection.c
*/

#include "gradeDe.h"

static void _callbackPressed(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    changeSettingsSection(SETTINGS_SECTION_SOUND);
    sfText_setFillColor(sceneMenuSettings->soundSection->title, (sfColor){255, 165, 66, 255});
}

static void _callbackHover(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_setFillColor(sceneMenuSettings->soundSection->title, (sfColor){255, 165, 66, 150});
}

static void _callbackDefault(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_setFillColor(sceneMenuSettings->soundSection->title, sfBlack);
}

static void _musicGestion(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    changeMusicVolume(sceneMenuSettings->soundSection->musicGestion->value);
}

static void _soundGestion(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    changeSoundVolume(sceneMenuSettings->soundSection->soundGestion->value);
}


void _renderSettingsSoundSectionContent(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    renderPlusMinus(sceneMenuSettings->soundSection->musicGestion);
    renderPlusMinus(sceneMenuSettings->soundSection->soundGestion);
}

void renderSettingsSoundSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    if (sceneMenuSettings->currentSection == SETTINGS_SECTION_SOUND) {
        renderText(sceneMenuSettings->soundSection->title);
        _renderSettingsSoundSectionContent();
    } else {
        renderTextWithAllCallbacks(sceneMenuSettings->soundSection->title, &_callbackPressed, &_callbackHover, &_callbackDefault);
    }
}

void initSettingsSoundSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();
    SettingsSoundSection_t *soundSection = malloc(sizeof(SettingsSoundSection_t));

    soundSection->title = createText("Sound", (sfVector2f){100, 100}, 50, FONT_SPICY_PIZZA);
    int *values = malloc(sizeof(int) * 4);
    values[PLUS_MINUS_VALUE] = 100;
    values[PLUS_MINUS_MIN] = 0;
    values[PLUS_MINUS_MAX] = 100;
    values[PLUS_MINUS_STEP] = 1;

    values[PLUS_MINUS_VALUE] = getMusicVolume();
    soundSection->musicGestion = initPlusMinusStruct(
        "Musics",
        values,
        (sfVector2f){400, 100},
        &_musicGestion
    );

    values[PLUS_MINUS_VALUE] = getSoundVolume();
    soundSection->soundGestion = initPlusMinusStruct(
        "Sounds",
        values,
        (sfVector2f){400, 200},
        &_soundGestion
    );

    sceneMenuSettings->soundSection = soundSection;
}

void destroySettingsSoundSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_destroy(sceneMenuSettings->soundSection->title);
    destroyPlusMinus(sceneMenuSettings->soundSection->musicGestion);
    destroyPlusMinus(sceneMenuSettings->soundSection->soundGestion);
    free(sceneMenuSettings->soundSection);
}
