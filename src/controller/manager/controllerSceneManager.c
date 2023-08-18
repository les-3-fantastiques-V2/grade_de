/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneManager.c
*/

#include "gradeDe.h"

void sceneManager(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    while (gradeDe->currentScene != EXIT) {
        sceneMenuChooseGame();
    }
}
