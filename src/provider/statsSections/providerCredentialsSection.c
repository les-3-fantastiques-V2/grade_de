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

static void _modifieCurrentCredentialsId(int value)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    sceneMenuStats->credentialsSection->credentialsId += value;
    sceneMenuStats->credentialsSection->currentCredentials = getCredentialsById(sceneMenuStats->credentialsSection->credentialsId);

    sceneMenuStats->credentialsSection->asPrevious = (sceneMenuStats->credentialsSection->credentialsId > 0) ? true : false;
    sceneMenuStats->credentialsSection->asNext = (sceneMenuStats->credentialsSection->credentialsId < CREDENTIALS_MAX - 1) ? true : false;
}

static void _leftArrowButtonPressed(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    if (!sceneMenuStats->credentialsSection->asPrevious) return;
    _modifieCurrentCredentialsId(-1);
}

static void _rightArrowButtonPressed(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    if (!sceneMenuStats->credentialsSection->asNext) return;
    _modifieCurrentCredentialsId(1);
}

static void _renderStatsCredentialsSectionContent(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();
    clickOnButton(sceneMenuStats->credentialsSection->leftArrowButton, &_leftArrowButtonPressed);
    clickOnButton(sceneMenuStats->credentialsSection->rightArrowButton, &_rightArrowButtonPressed);

    renderCredentials(sceneMenuStats->credentialsSection->currentCredentials);
    // if (sceneMenuStats->credentialsSection->asPrevious) renderButton(sceneMenuStats->credentialsSection->leftArrowButton);
    // if (sceneMenuStats->credentialsSection->asNext) renderButton(sceneMenuStats->credentialsSection->rightArrowButton);
    renderButton(sceneMenuStats->credentialsSection->leftArrowButton);
    renderButton(sceneMenuStats->credentialsSection->rightArrowButton);
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
    credentialsSection->leftArrowButton = createButton(
        (sfVector2f){42, 50},
        "assets/image/IconLeft.png",
        (sfVector2f) {410 + percent(WINDOW_WIDTH, 3), percent(WINDOW_HEIGHT, 80) / 2 - 25}
    );
    credentialsSection->rightArrowButton = createButton(
        (sfVector2f){42, 50},
        "assets/image/IconRight.png",
        (sfVector2f) {WINDOW_WIDTH - percent(WINDOW_WIDTH, 5) - 42, percent(WINDOW_HEIGHT, 80) / 2 - 25}
    );
    credentialsSection->asPrevious = false;
    credentialsSection->asNext = true;

    sceneMenuStats->credentialsSection = credentialsSection;
    initCredentialsListStruct();
    sceneMenuStats->credentialsSection->currentCredentials = getCredentialsById(CREDENTIALS_DRAGUSHEEN);
}

void destroyStatsCredentialsSection(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    sfText_destroy(sceneMenuStats->credentialsSection->title);
    destroyButton(sceneMenuStats->credentialsSection->leftArrowButton);
    destroyButton(sceneMenuStats->credentialsSection->rightArrowButton);
    destroyCredentialsListStruct();
    free(sceneMenuStats->credentialsSection);
}
