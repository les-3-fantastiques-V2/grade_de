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



void renderSettingsVideoSectionContent(void)
{
}

void renderSettingsVideoSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    if (sceneMenuSettings->currentSection == SETTINGS_SECTION_VIDEO) {
        renderText(sceneMenuSettings->videoSection->title);
        renderSettingsVideoSectionContent();
    } else {
        renderTextWithAllCallbacks(sceneMenuSettings->videoSection->title, &_callbackPressed, &_callbackHover, &_callbackDefault);
    }
}

void initSettingsVideoSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();
    SettingsVideoSection_t *videoSection = malloc(sizeof(SettingsVideoSection_t));

    videoSection->title = createText("Video", (sfVector2f){100, 200}, 50, FONT_SPICY_PIZZA);

    sceneMenuSettings->videoSection = videoSection;
}

void destroySettingsVideoSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_destroy(sceneMenuSettings->videoSection->title);
    free(sceneMenuSettings->videoSection);
}
