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


void renderSettingsSoundSectionContent(void)
{
}

void renderSettingsSoundSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    if (sceneMenuSettings->currentSection == SETTINGS_SECTION_SOUND) {
        renderText(sceneMenuSettings->soundSection->title);
        renderSettingsSoundSectionContent();
    } else {
        renderTextWithAllCallbacks(sceneMenuSettings->soundSection->title, &_callbackPressed, &_callbackHover, &_callbackDefault);
    }
}

void initSettingsSoundSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();
    SettingsSoundSection_t *soundSection = malloc(sizeof(SettingsSoundSection_t));

    soundSection->title = createText("Son", (sfVector2f){100, 100}, 50, FONT_SPICY_PIZZA);

    sceneMenuSettings->soundSection = soundSection;
}

void destroySettingsSoundSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_destroy(sceneMenuSettings->soundSection->title);
    free(sceneMenuSettings->soundSection);
}
