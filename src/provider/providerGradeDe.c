/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** GradeDeProvider.c
*/

#include "gradeDe.h"

GradeDe_t *getGradeDeStruct(void)
{
    static GradeDe_t gradeDeStruct;
    return &gradeDeStruct;
}

void initGradeDeStruct(void)
{
    GradeDe_t *gradeDeStruct = getGradeDeStruct();

    initWindowConfigStruct();
    gradeDeStruct->currentScene = SCENE_MENU_CHOOSE_GAME;
    gradeDeStruct->exitStatus = 0;
}

int destroyGradeDeStruct(void)
{
    GradeDe_t *gradeDeStruct = getGradeDeStruct();

    destroyWindowConfigStruct();

    return gradeDeStruct->exitStatus;
}
