/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerSceneMap.c
*/

#include "gradeDe.h"

static void _addSceneMap(int sceneId, SceneMap_t **sceneMap)
{
    SceneConfig_t *sceneConfig = getSceneConfigById(sceneId);

    if (sceneConfig == NULL) return;

    SceneMap_t *newSceneMap = malloc(sizeof(SceneMap_t));
    newSceneMap->sceneConfig = sceneConfig;
    newSceneMap->next = *sceneMap;
    *sceneMap = newSceneMap;
}

void initSceneMapStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    SceneMap_t *sceneMap = NULL;

    for (int i = 0; i < SCENE_MAX; i++) {
        _addSceneMap(i, &sceneMap);
    }

    gradeDe->sceneMap = sceneMap;
}

void destroySceneMapStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    while (gradeDe->sceneMap != NULL) {
        SceneMap_t *next = gradeDe->sceneMap->next;
        free(gradeDe->sceneMap);
        gradeDe->sceneMap = next;
    }
}
