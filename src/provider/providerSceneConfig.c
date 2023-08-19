/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerSceneConfig.c
*/

#include "gradeDe.h"

void (*renderFunction[SCENE_MAX])(void) = {
    &renderSceneMenuChooseGame,
};

void (*loadSceneElement[SCENE_MAX])(void) = {
    &loadSceneMenuChooseGame,
};

void (*destroySceneElement[SCENE_MAX])(void) = {
    &destroySceneMenuChooseGame,
};

SceneConfig_t *getSceneConfigById(int sceneId)
{
    if (sceneId < 0 || sceneId >= SCENE_MAX) return NULL;

    SceneConfig_t *sceneConfig = malloc(sizeof(SceneConfig_t));
    sceneConfig->renderFunction = renderFunction[sceneId];
    sceneConfig->loadSceneElement = loadSceneElement[sceneId];
    sceneConfig->destroySceneElement = destroySceneElement[sceneId];
    sceneConfig->sceneId = sceneId;

    return sceneConfig;
}
