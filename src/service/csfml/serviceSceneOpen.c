/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceSceneOpen.c
*/

#include "gradeDe.h"

bool sceneIsOpen(int currentSceneId)
{
    GradeDe_t *gradeDeStruct = getGradeDeStruct();
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    return (gradeDeStruct->currentSceneId == currentSceneId && sfRenderWindow_isOpen(windowConfig->window));
}
