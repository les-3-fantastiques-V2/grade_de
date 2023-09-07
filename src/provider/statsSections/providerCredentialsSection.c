/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerSoundSection.c
*/

#include "gradeDe.h"

static void _callbackPressed(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    changeStatsSection(STATS_SECTION_CREDENTIALS);
    sfText_setFillColor(sceneMenuStats->credentialsSection->title, (sfColor){255, 165, 66, 255});
}

static void _callbackHover(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    sfText_setFillColor(sceneMenuStats->credentialsSection->title, (sfColor){255, 165, 66, 150});
}

static void _callbackDefault(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    sfText_setFillColor(sceneMenuStats->credentialsSection->title, sfBlack);
}

static void _renderStatsCredentialsSectionContent(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();
}


void renderStatsCredentialsSection(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    if (sceneMenuStats->currentSection == STATS_SECTION_CREDENTIALS) {
        renderText(sceneMenuStats->credentialsSection->title);
        _renderStatsCredentialsSectionContent();
    } else {
        renderTextWithAllCallbacks(sceneMenuStats->credentialsSection->title, &_callbackPressed, &_callbackHover, &_callbackDefault);
    }
}

void initStatsCredentialsSection(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();
    StatsCredentialsSection_t *credentialsSection = malloc(sizeof(StatsCredentialsSection_t));

    credentialsSection->title = createText("Credentials", (sfVector2f){100, 200}, 50, FONT_SPICY_PIZZA);
    sceneMenuStats->credentialsSection = credentialsSection;
}

void destroyStatsCredentialsSection(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    sfText_destroy(sceneMenuStats->credentialsSection->title);
    free(sceneMenuStats->credentialsSection);
}
