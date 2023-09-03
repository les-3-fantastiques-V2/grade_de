/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneMenuSettings.c
*/

#include "gradeDe.h"

/* System */


SceneMenuSettings_t *getSceneMenuSettingsStruct(void)
{
    static SceneMenuSettings_t SceneMenuSettingsStruct;
    return &SceneMenuSettingsStruct;
}

void eventManagerSceneMenuSettings(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    if (clickOnButton(sceneMenuSettings->backButton)) {
        changeScene(SCENE_MENU_CHOOSE_GAME); return;
    }
}

void renderSceneMenuSettings(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    renderRectangleShape(sceneMenuSettings->background);
    renderRoundedRectangle(sceneMenuSettings->backgroundMenu);
    renderButton(sceneMenuSettings->backButton);
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
    sceneMenuSettings->backButton = createButton(
        (sfVector2f){80, 70},
        "assets/image/IconArrowLeft.png",
        (sfVector2f){20, WINDOW_HEIGHT - 100}
    );
}

void destroySceneMenuSettings(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    destroyButton(sceneMenuSettings->backButton);
    sfRectangleShape_destroy(sceneMenuSettings->background);
    sfConvexShape_destroy(sceneMenuSettings->backgroundMenu);
}
