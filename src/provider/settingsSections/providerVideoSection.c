/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerVideoSection.c
*/

#include "gradeDe.h"

static void _clickOnVideoSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();
    if (sceneMenuSettings->currentSection == SETTINGS_SECTION_VIDEO) return;

    sfFloatRect rect = sfText_getGlobalBounds(sceneMenuSettings->videoSection->title);
    sfVector2f pos = {rect.left, rect.top};
    sfVector2f size = {rect.width, rect.height};
    if (mouseIsOn(pos, size) && sfMouse_isButtonPressed(sfMouseLeft)) {
        changeSettingsSection(SETTINGS_SECTION_VIDEO);
        sfText_setFillColor(sceneMenuSettings->videoSection->title, (sfColor){255, 165, 66, 255});
    }
}

void renderSettingsVideoSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();
    if (sceneMenuSettings->currentSection != SETTINGS_SECTION_VIDEO) {
        sfFloatRect rect = sfText_getGlobalBounds(sceneMenuSettings->videoSection->title);
        sfVector2f pos = {rect.left, rect.top};
        sfVector2f size = {rect.width, rect.height};
        if (mouseIsOn(pos, size)){
            sfText_setFillColor(sceneMenuSettings->videoSection->title, (sfColor){255, 165, 66, 150});
        } else {
            sfText_setFillColor(sceneMenuSettings->videoSection->title, sfBlack);
        }
    }

    _clickOnVideoSection();
    renderText(sceneMenuSettings->videoSection->title);
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
