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

    renderText(sceneMenuStats->applicationsSection->applicationLabel);
    renderText(sceneMenuStats->applicationsSection->applicationCount);
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
    applicationsSection->applicationLabel = createText("Application count :  ", (sfVector2f){450, 100}, 40, FONT_SPICY_PIZZA);

    char *applicationCount = intToString(getGameSlotListLength());
    sfFloatRect rect = sfText_getGlobalBounds(applicationsSection->applicationLabel);
    applicationsSection->applicationCount = createText(applicationCount, (sfVector2f){rect.left + rect.width, 100}, 40, FONT_SPICY_PIZZA);
    free(applicationCount);

    sceneMenuStats->applicationsSection = applicationsSection;
}

void destroyStatsApplicationsSection(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    sfText_destroy(sceneMenuStats->applicationsSection->title);
    sfText_destroy(sceneMenuStats->applicationsSection->applicationLabel);
    sfText_destroy(sceneMenuStats->applicationsSection->applicationCount);
    free(sceneMenuStats->applicationsSection);
}
