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

    changeStatsSection(STATS_SECTION_APPLICATIONS);
    sfText_setFillColor(sceneMenuStats->applicationsSection->title, (sfColor){255, 165, 66, 255});
}

static void _callbackHover(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    sfText_setFillColor(sceneMenuStats->applicationsSection->title, (sfColor){255, 165, 66, 150});
}

static void _callbackDefault(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    sfText_setFillColor(sceneMenuStats->applicationsSection->title, sfBlack);
}

static void _renderStatsApplicationsSectionContent(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();
}


void renderStatsApplicationsSection(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    if (sceneMenuStats->currentSection == STATS_SECTION_APPLICATIONS) {
        renderText(sceneMenuStats->applicationsSection->title);
        _renderStatsApplicationsSectionContent();
    } else {
        renderTextWithAllCallbacks(sceneMenuStats->applicationsSection->title, &_callbackPressed, &_callbackHover, &_callbackDefault);
    }
}

void initStatsApplicationsSection(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();
    StatsApplicationsSection_t *applicationsSection = malloc(sizeof(StatsApplicationsSection_t));

    applicationsSection->title = createText("Applications", (sfVector2f){100, 100}, 50, FONT_SPICY_PIZZA);
    sceneMenuStats->applicationsSection = applicationsSection;
}

void destroyStatsApplicationsSection(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    sfText_destroy(sceneMenuStats->applicationsSection->title);
    free(sceneMenuStats->applicationsSection);
}
