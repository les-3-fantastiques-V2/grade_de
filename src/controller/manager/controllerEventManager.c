/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerEventManager.c
*/

#include "gradeDe.h"

static bool closeEvent(WindowConfig_t *windowConfig)
{
    if (windowConfig->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        return true;
    return false;
}

void eventManager(SceneConfig_t *sceneConfig)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    while (sfRenderWindow_pollEvent(windowConfig->window, &windowConfig->event)) {
        if (closeEvent(windowConfig)) playTransition(EXIT);
        sceneConfig->eventSceneManager();
    }
}
