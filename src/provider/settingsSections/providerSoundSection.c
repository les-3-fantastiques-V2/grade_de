/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerSoundSection.c
*/

#include "gradeDe.h"

static void _clickOnSoundSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();
    if (sceneMenuSettings->currentSection == SETTINGS_SECTION_SOUND) return;

    sfFloatRect rect = sfText_getGlobalBounds(sceneMenuSettings->soundSection->title);
    sfVector2f pos = {rect.left, rect.top};
    sfVector2f size = {rect.width, rect.height};
    if (mouseIsOn(pos, size) && sfMouse_isButtonPressed(sfMouseLeft)) {
        changeSettingsSection(SETTINGS_SECTION_SOUND);
        sfText_setFillColor(sceneMenuSettings->soundSection->title, (sfColor){255, 165, 66, 255});
    }
}

void renderSettingsSoundSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();
    if (sceneMenuSettings->currentSection != SETTINGS_SECTION_SOUND) {
        sfFloatRect rect = sfText_getGlobalBounds(sceneMenuSettings->soundSection->title);
        sfVector2f pos = {rect.left, rect.top};
        sfVector2f size = {rect.width, rect.height};
        if (mouseIsOn(pos, size)){
            sfText_setFillColor(sceneMenuSettings->soundSection->title, (sfColor){255, 165, 66, 150});
        } else {
            sfText_setFillColor(sceneMenuSettings->soundSection->title, sfBlack);
        }
    }

    _clickOnSoundSection();
    renderText(sceneMenuSettings->soundSection->title);
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
