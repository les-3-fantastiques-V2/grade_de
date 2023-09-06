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

    changeSettingsSection(SETTINGS_SECTION_NOTES);
    sfText_setFillColor(sceneMenuSettings->notesSection->title, (sfColor){255, 165, 66, 255});
}

static void _callbackHover(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_setFillColor(sceneMenuSettings->notesSection->title, (sfColor){255, 165, 66, 150});
}

static void _callbackDefault(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_setFillColor(sceneMenuSettings->notesSection->title, sfBlack);
}


void _renderSettingsNotesSectionContent(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    renderText(sceneMenuSettings->notesSection->notes);
}

void renderSettingsNotesSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    if (sceneMenuSettings->currentSection == SETTINGS_SECTION_NOTES) {
        renderText(sceneMenuSettings->notesSection->title);
        _renderSettingsNotesSectionContent();
    } else {
        renderTextWithAllCallbacks(sceneMenuSettings->notesSection->title, &_callbackPressed, &_callbackHover, &_callbackDefault);
    }
}

void initSettingsNotesSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();
    SettingsNotesSection_t *notesSection = malloc(sizeof(SettingsNotesSection_t));

    notesSection->title = createText("Notes", (sfVector2f){100, 300}, 50, FONT_SPICY_PIZZA);
    notesSection->notes = createTextWithMaxWidth(
        "Note that all the settings will be shared with all games and applications.",
        (sfVector2f){400, 100},
        50,
        FONT_SPICY_PIZZA,
        800
    );
    sceneMenuSettings->notesSection = notesSection;
}

void destroySettingsNotesSection(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfText_destroy(sceneMenuSettings->notesSection->title);
    sfText_destroy(sceneMenuSettings->notesSection->notes);
    free(sceneMenuSettings->notesSection);
}
