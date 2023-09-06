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

    changeSettingsSection(SETTINGS_SECTION_SAVE);
    sfText_setFillColor(sceneMenuSettings->saveSection->title, (sfColor){255, 165, 66, 255});
}

static void _callbackHoverTitle(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_setFillColor(sceneMenuSettings->saveSection->title, (sfColor){255, 165, 66, 150});
}

static void _callbackHoverSave(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_setFillColor(sceneMenuSettings->saveSection->save, (sfColor){255, 165, 66, 150});
}

static void _callbackDefaultTitle(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_setFillColor(sceneMenuSettings->saveSection->title, sfBlack);
}

static void _callbackDefaultSave(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_setFillColor(sceneMenuSettings->saveSection->save, sfBlack);
}

static void _changeSaveOnExit(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    if (sceneMenuSettings->saveSection->saveOnExitButton->isToggled)
        setConfig("saveOnExit", "true");
    else
        setConfig("saveOnExit", "false");
}

void _renderSettingsSaveSectionContent(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    renderTextWithAllCallbacks(sceneMenuSettings->saveSection->save, &saveConfig, &_callbackHoverSave, &_callbackDefaultSave);
    renderText(sceneMenuSettings->saveSection->saveOnExitButtonLabel);
    if (clickOnToggleButton(sceneMenuSettings->saveSection->saveOnExitButton)) _changeSaveOnExit();
    renderToggleButton(sceneMenuSettings->saveSection->saveOnExitButton);
}

void renderSettingsSaveSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    if (sceneMenuSettings->currentSection == SETTINGS_SECTION_SAVE) {
        renderText(sceneMenuSettings->saveSection->title);
        _renderSettingsSaveSectionContent();
    } else {
        renderTextWithAllCallbacks(sceneMenuSettings->saveSection->title, &_callbackPressed, &_callbackHoverTitle, &_callbackDefaultTitle);
    }
}

void initSettingsSaveSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();
    SettingsSaveSection_t *saveSection = malloc(sizeof(SettingsSaveSection_t));

    saveSection->title = createText("Save", (sfVector2f){100, 300}, 50, FONT_SPICY_PIZZA);
    saveSection->save = createText("Save settings", (sfVector2f){400, 100}, 50, FONT_SPICY_PIZZA);
    saveSection->saveOnExitButtonLabel = createText("Always save settings on exit", (sfVector2f){480, 200}, 50, FONT_SPICY_PIZZA);
    saveSection->saveOnExitButton = createToggleButton((sfVector2f){50, 50}, (sfVector2f){400, 210});

    char *saveOnExit = getConfigValueByName("saveOnExit");
    if (saveOnExit != NULL) {
        saveSection->saveOnExitButton->isToggled = (strcmp(saveOnExit, "true") == 0) ? true : false;
    } else {
        setConfig("saveOnExit", "false");
        saveSection->saveOnExitButton->isToggled = false;
    }

    sceneMenuSettings->saveSection = saveSection;
}

void destroySettingsSaveSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_destroy(sceneMenuSettings->saveSection->title);
    sfText_destroy(sceneMenuSettings->saveSection->save);
    sfText_destroy(sceneMenuSettings->saveSection->saveOnExitButtonLabel);
    destroyToggleButton(sceneMenuSettings->saveSection->saveOnExitButton);
    free(sceneMenuSettings->saveSection);
}
