/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneManager.c
*/

#include "gradeDe.h"

void changeScene(SCENE_E sceneId)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    gradeDe->currentSceneId = sceneId;
    sleep(0.5);
}

static void _renderScene(SceneConfig_t *sceneConfig)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();
    sceneConfig->loadSceneElement();

    while (sceneIsOpen(sceneConfig->sceneId)) {
        eventManager(sceneConfig);
        sceneConfig->renderFunction();
        renderMouseCursor();
        renderRectangleShape(windowConfig->brightnessRectangle);
        sfRenderWindow_display(windowConfig->window);
        sfRenderWindow_clear(windowConfig->window, sfBlack);
    }

    sceneConfig->destroySceneElement();
}

void sceneManager(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    SceneMap_t *currentScene = gradeDe->sceneMap;

    while (gradeDe->currentSceneId != EXIT) {
        if (currentScene == NULL){
            currentScene = gradeDe->sceneMap;
            continue;
        }

        if (currentScene->sceneConfig->sceneId == gradeDe->currentSceneId)
            _renderScene(currentScene->sceneConfig);

        currentScene = currentScene->next;
    }
}
