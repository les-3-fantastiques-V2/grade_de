/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerSettingsSection.c
*/

#include "gradeDe.h"

void changeSettingsSection(SETTINGS_SECTION_E section)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_setFillColor(sceneMenuSettings->soundSection->title, sfBlack);
    sfText_setFillColor(sceneMenuSettings->videoSection->title, sfBlack);

    sceneMenuSettings->currentSection = section;
}

void renderSettingsSection(void)
{
    renderSettingsSoundSection();
    renderSettingsVideoSection();
}

void initSettingsSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    initSettingsSoundSection();
    initSettingsVideoSection();

    sceneMenuSettings->currentSection = SETTINGS_SECTION_SOUND;
    sfText_setFillColor(sceneMenuSettings->soundSection->title, (sfColor){255, 165, 66, 255});
}

void destroySettingsSection(void)
{
    destroySettingsSoundSection();
    destroySettingsVideoSection();
}
