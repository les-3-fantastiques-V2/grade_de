/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneMenuSettings.c
*/

#include "gradeDe.h"

/* Button */

static void _backButtonPressed(void)
{
    changeScene(SCENE_MENU_CHOOSE_GAME);
}


/* System */

SceneMenuSettings_t *getSceneMenuSettingsStruct(void)
{
    static SceneMenuSettings_t SceneMenuSettingsStruct;
    return &SceneMenuSettingsStruct;
}

void eventManagerSceneMenuSettings(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    if (clickOnButton(sceneMenuSettings->backButton, &_backButtonPressed)) return;
}

void renderSceneMenuSettings(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    renderRectangleShape(sceneMenuSettings->background);
    renderRoundedRectangle(sceneMenuSettings->backgroundMenu);
    renderRoundedRectangle(sceneMenuSettings->line);
    renderButton(sceneMenuSettings->backButton);
    renderText(sceneMenuSettings->note);
    renderSettingsSection();
}

void loadSceneMenuSettings(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();
    changeMouseCursor(CURSOR_DEFAULT, CURSOR_TYPE_POINTER);
    changeMusic(MUSIC_HOME_AMBIENT);


    sceneMenuSettings->background = createRectangleShape(
        (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT},
        (sfColor) {99, 50, 79, 255},
        (sfVector2f){0, 0}
    );
    sceneMenuSettings->backgroundMenu = createRoundedRectangle(
        (sfVector3f){percent(WINDOW_WIDTH, 96), percent(WINDOW_HEIGHT, 78), 40},
        (sfColor){143, 87, 101, 255},
        (sfVector2f){percent(WINDOW_WIDTH, 2), percent(WINDOW_HEIGHT, 4)}
    );
    sceneMenuSettings->line = createRoundedRectangle(
        (sfVector3f){10, percent(WINDOW_HEIGHT, 70), 4},
        (sfColor) {99, 50, 79, 255},
        (sfVector2f){300, percent(WINDOW_HEIGHT, 8)}
    );
    sceneMenuSettings->backButton = createButton(
        (sfVector2f){80, 70},
        "assets/image/IconArrowLeft.png",
        (sfVector2f){20, WINDOW_HEIGHT - 100}
    );
    sceneMenuSettings->note = createTextWithMaxWidth(
        "Note that all the settings will be shared with all games and applications.",
        (sfVector2f){400, 540},
        20,
        FONT_SPICY_PIZZA,
        800
    );
    initSettingsSection();
}

void destroySceneMenuSettings(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    destroySettingsSection();
    sfText_destroy(sceneMenuSettings->note);
    destroyButton(sceneMenuSettings->backButton);
    sfRectangleShape_destroy(sceneMenuSettings->background);
    sfConvexShape_destroy(sceneMenuSettings->backgroundMenu);
    sfConvexShape_destroy(sceneMenuSettings->line);
}
