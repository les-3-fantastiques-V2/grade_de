/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneMenuSettingsSystem.c
*/

#include "gradeDe.h"

SceneMenuSettings_t *getSceneMenuSettingsStruct(void)
{
    static SceneMenuSettings_t sceneMenuSettingsStruct;
    return &sceneMenuSettingsStruct;
}

static bool _clickOnBack(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    if (mouseIsOnCircleButton(sceneMenuSettings->backButton)) {
        gradeDe->currentSceneId = SCENE_MENU_CHOOSE_GAME;
        return true;
    }
    return false;
}

void eventManagerSceneMenuSettings(void)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    if (windowConfig->event.mouseButton.type == sfEvtMouseButtonReleased) {
        if (_clickOnBack()) return;
    }

}

void renderSceneMenuSettings(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    renderRectangleShape(sceneMenuSettings->background);
    renderButtonCircle(sceneMenuSettings->backButton);
}

void loadSceneMenuSettings(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();
    changeMouseCursor(CURSOR_DEFAULT, CURSOR_TYPE_POINTER);

    sceneMenuSettings->background = createRectangleShape(
        (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT},
        sfColor_fromRGB(50, 50, 50),
        (sfVector2f){0, 0}
    );

    sceneMenuSettings->backButton = createButtonCircleColor(
        40,
        sfColor_fromRGB(240, 191, 76),
        (sfVector2f){20, 20}
    );
}

void destroySceneMenuSettings(void)
{
    SceneMenuSettings_t *sceneMenuSettings = getSceneMenuSettingsStruct();

    sfRectangleShape_destroy(sceneMenuSettings->background);
    destroyButtonCircleColor(sceneMenuSettings->backButton);
}
