/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerStatsSections.c
*/

#include "gradeDe.h"

void changeStatsSection(STATS_SECTION_E section)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    sfText_setFillColor(sceneMenuStats->applicationsSection->title, sfBlack);
    sfText_setFillColor(sceneMenuStats->credentialsSection->title, sfBlack);

    sceneMenuStats->currentSection = section;
}

void renderStatsSection(void)
{
    renderStatsApplicationsSection();
    renderStatsCredentialsSection();
}

void initStatsSection(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    initStatsApplicationsSection();
    initStatsCredentialsSection();

    changeStatsSection(STATS_SECTION_APPLICATIONS);
    sfText_setFillColor(sceneMenuStats->applicationsSection->title, (sfColor){255, 165, 66, 255});
}

void destroyStatsSection(void)
{
    destroyStatsApplicationsSection();
    destroyStatsCredentialsSection();
}
